#include <thread>
#include <iostream>
#include <sstream>
#include <string.h>
#include "server.h"
#include "messages.h"

#define BACKLOG 10   // how many pending connections queue will hold

void sigchld_handler(int s)
{
  while(waitpid(-1, NULL, WNOHANG) > 0);
}

Plant Server::GetPlant() {
  return _plant;
}

std::string Server::Process(std::string input) {
  Message* message = MessageBuilder::Build(input);
  Message* response = message->Execute(*this);
  std::string response_string = response->Serialize();
  delete message;
  delete response;
  return response_string;
}

void Server::Communicate(int sender_fd) {
  char buf[10000];

  while(1) {
    int len = 0;
    if( len = recv(sender_fd, buf, sizeof(buf), 0) > 0){
      buf[len] = '\0';
      std::string reply = Process(std::string(buf));
      if (send(sender_fd, reply.c_str(), reply.size(), 0) == -1) {
        perror("Error on Communicate::OnSendReply");
        exit(1);
      }
    }
    else {
      std::cout << "Communication closed" << std::endl;
      exit(1);
    }
  }
}

Server::Server(int port) : _port(port) {
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
    if ((sockfd = socket(p->ai_family, p->ai_socktype,
        p->ai_protocol)) == -1) {
      perror("server: socket");
      continue;
    }

    if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &yes,
        sizeof(int)) == -1) {
      perror("setsockopt");
      exit(1);
    }

    if (bind(sockfd, p->ai_addr, p->ai_addrlen) == -1) {
      close(sockfd);
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

  if (listen(sockfd, BACKLOG) == -1) {
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
  close(sockfd); sockfd = 0;
  close(newfd); newfd = 0;
}

void Server::Listen() {
  struct sockaddr_storage their_addr; // connector's address information
  socklen_t sin_size;
  char s[INET6_ADDRSTRLEN];
  printf("server: waiting for connections...\n");

  while(1) {  // main accept() loop
    sin_size = sizeof their_addr;
    newfd = accept(sockfd, (struct sockaddr *)&their_addr, &sin_size);
    if (newfd == -1) {
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

    if (!fork()) { // this is the child process
      close(sockfd); // child doesn't need the listener
      Communicate(newfd);
      close(newfd);
      exit(0);
    }
    close(newfd);  // parent doesn't need this
  }
}


