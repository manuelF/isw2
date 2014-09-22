#include "gui.h"
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <netdb.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>

#include <arpa/inet.h>

#include <sstream>

#include "messages.h"

std::string GUI::Process(std::string input) {
/*
  Message* message = MessageBuilder::Build(input);
  Message* response = message->Execute(*this);
  std::string response_string = response->Serialize();
  delete message;
  delete response;
  return response_string;
  */
  return input;
}

void GUI::Communicate(int sender_fd) {
  char buf[10000];

  while(1) {
    /*
     * Pseudocodigo:
     * while(1):
     *  Interactuar hasta llegar a un menu que necesita algun dato
     *  Construir el mensaje que lo pide
     *  enviarlo
     *  Esperar a recibir la respuesta
     *  construir el mensaje de respuesta
     *  llamarnos a traves del mensaje con una cosa interactiva para seguir avanzando
     *  volver a la pantalla anterior
     */
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


void GUI::Connect() {
  int numbytes;
  struct addrinfo hints, *servinfo, *p;
  int rv;
  char s[INET6_ADDRSTRLEN];
  std::stringstream ss;
  ss << _port;

  memset(&hints, 0, sizeof hints);
  hints.ai_family = AF_UNSPEC;
  hints.ai_socktype = SOCK_STREAM;

  if ((rv = getaddrinfo(_server, ss.str().c_str(), &hints, &servinfo)) != 0) {
    fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(rv));
    exit(1);
  }

  // loop through all the results and connect to the first we can
  for(p = servinfo; p != NULL; p = p->ai_next) {
    if ((sockfd = socket(p->ai_family, p->ai_socktype,
        p->ai_protocol)) == -1) {
      perror("client: socket");
      continue;
    }

    if (connect(sockfd, p->ai_addr, p->ai_addrlen) == -1) {
      close(sockfd);
      perror("client: connect");
      continue;
    }

    break;
  }

  if (p == NULL) {
    fprintf(stderr, "client: failed to connect\n");
    exit(2);
  }

  void *inet_addr;
  if (( (struct sockaddr *)&p->ai_addr)->sa_family == AF_INET)
    inet_addr = &(((struct sockaddr_in*) (struct sockaddr *)&p->ai_addr)->sin_addr);
  else
    inet_addr = &(((struct sockaddr_in6*) (struct sockaddr *)&p->ai_addr)->sin6_addr);

  inet_ntop(p->ai_family, inet_addr, s, sizeof s);
  printf("client: connecting to %s\n", s);

  freeaddrinfo(servinfo); // all done with this structure

  Communicate(sockfd);

  close(sockfd);
}

GUI::GUI(char* server, int port) : _server(server), _port(port) {

}
