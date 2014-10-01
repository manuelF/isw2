#include <cstdio>
#include <cstdlib>
#include <string>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/wait.h>
#include <signal.h>

#include <thread>
#include <iostream>
#include <sstream>
#include <string.h>

#include "server.h"

void sigchld_handler(int s)
{
  while(waitpid(-1, NULL, WNOHANG) > 0);
}

Plant Server::GetPlant() {
  return _plant;
}

void Server::SetPlant(Plant plant) {
  _plant = plant;
}

MasterPlan Server::GetMasterPlan() {
  return _plan;
}

void Server::SetMasterPlan(MasterPlan plan) {
  _plan = plan;
}

ExternalData Server::GetSensorsReading() {
  return ExternalData::GetSample();
}

void Server::Communicate(int sender_fd) {
  char buf[10000];

  while(1) {
    int len = 0;
    memset(buf, 0, sizeof buf);
    if((len = recv(sender_fd, buf, sizeof(buf), 0)) > 0) {
      buf[len] = '\0';
      Message* message = MessageBuilder::Build(std::string(buf));
      Message* response = message->Execute(*this);
      if (message->ExpectResponse() && response) {
        std::string response_string = response->Serialize();
        if (send(sender_fd, response_string.c_str(), response_string.size(), 0) == -1) {
            perror("Error on Communicate::OnSendReply");
            exit(1);
         }
        delete response;
      }
      delete message;
    }
    else {
      std::cout << "Communication closed" << std::endl;
      return;
    }
  }
}

Server::Server(int port) : _port(port), _listener(0), _newconnection(0),
    _plan(MasterPlan::BuildFromFile("default_plan")),
    _decisions_maker(_history, _plan),
    _external_conditions_reader(_history)
    {

  struct addrinfo hints, *servinfo, *p;
  struct sigaction sa;
  int yes=1;
  int rv;
  std::stringstream ss;
  ss << _port;

  memset(&hints, 0, sizeof hints);
  hints.ai_family = AF_UNSPEC;
  hints.ai_socktype = SOCK_STREAM;
  hints.ai_flags = AI_PASSIVE; // use my IP

  if ((rv = getaddrinfo(NULL, ss.str().c_str(), &hints, &servinfo)) != 0) {
    fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(rv));
    exit(1);
  }

  // loop through all the results and bind to the first we can
  for(p = servinfo; p != NULL; p = p->ai_next) {
    if ((_listener = socket(p->ai_family, p->ai_socktype,
        p->ai_protocol)) == -1) {
      perror("server: socket");
      continue;
    }

    if (setsockopt(_listener, SOL_SOCKET, SO_REUSEADDR, &yes,
        sizeof(int)) == -1) {
      perror("setsockopt");
      exit(1);
    }

    if (bind(_listener, p->ai_addr, p->ai_addrlen) == -1) {
      close(_listener);
      perror("server: bind");
      continue;
    }

    break;
  }

  if (p == NULL)  {
    fprintf(stderr, "server: failed to bind\n");
    exit(2);
  }

  freeaddrinfo(servinfo); // all done with this structure

  #define CONNECTIONS_BACKLOG 10   // how many pending connections queue will hold
  if (listen(_listener, CONNECTIONS_BACKLOG) == -1) {
    perror("listen");
    exit(1);
  }

  sa.sa_handler = sigchld_handler; // reap all dead processes
  sigemptyset(&sa.sa_mask);
  sa.sa_flags = SA_RESTART;
  if (sigaction(SIGCHLD, &sa, NULL) == -1) {
    perror("sigaction");
    exit(1);
  }
}

Server::~Server() {
  close(_listener); _listener = 0;
  close(_newconnection); _newconnection = 0;
}

void Server::Listen() {
  struct sockaddr_storage their_addr; // connector's address information
  socklen_t sin_size;
  char s[INET6_ADDRSTRLEN];
  printf("server: waiting for connections...\n");

  while(1) {  // main accept() loop
    sin_size = sizeof their_addr;
    _newconnection = accept(_listener, (struct sockaddr *)&their_addr, &sin_size);
    if (_newconnection == -1) {
      perror("accept");
      continue;
    }

    void *inet_addr;
    if (( (struct sockaddr *)&their_addr)->sa_family == AF_INET)
      inet_addr = &(((struct sockaddr_in*) (struct sockaddr *)&their_addr)->sin_addr);
    else
      inet_addr = &(((struct sockaddr_in6*) (struct sockaddr *)&their_addr)->sin6_addr);

    inet_ntop(their_addr.ss_family, inet_addr, s, sizeof s);
    printf("server: got connection from %s\n", s);


    Communicate(_newconnection);
    close(_newconnection);
  }
}


