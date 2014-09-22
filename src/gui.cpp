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

#define PORT "3490" // the port client will be connecting to

#define MAXDATASIZE 100 // max number of bytes we can get at once


bool valid(char option) {
  return (('1'<=option) && ('9'>=option));
}

#define SIG_QUIT 9
#define SIG_HELP 1

void pollingLoop(int fd) {

}

// get sockaddr, IPv4 or IPv6:
void *get_in_addr(struct sockaddr *sa)
{
  if (sa->sa_family == AF_INET) {
    return &(((struct sockaddr_in*)sa)->sin_addr);
  }

  return &(((struct sockaddr_in6*)sa)->sin6_addr);
}

int main(int argc, char *argv[])
{
  int sockfd, numbytes;
  char buf[MAXDATASIZE];
  struct addrinfo hints, *servinfo, *p;
  int rv;
  char s[INET6_ADDRSTRLEN];

  if (argc != 2) {
      fprintf(stderr,"usage: client hostname\n");
      exit(1);
  }

  memset(&hints, 0, sizeof hints);
  hints.ai_family = AF_UNSPEC;
  hints.ai_socktype = SOCK_STREAM;

  if ((rv = getaddrinfo(argv[1], PORT, &hints, &servinfo)) != 0) {
    fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(rv));
    return 1;
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
    return 2;
  }

  inet_ntop(p->ai_family, get_in_addr((struct sockaddr *)p->ai_addr),
      s, sizeof s);
  printf("client: connecting to %s\n", s);

  freeaddrinfo(servinfo); // all done with this structure

  pollingLoop(sockfd);

  if ((numbytes = recv(sockfd, buf, MAXDATASIZE-1, 0)) == -1) {
      perror("recv");
      exit(1);
  }
  send(sockfd, "Peron", 6, 0);
  while(1);
  buf[numbytes] = '\0';

  printf("client: received '%s'\n",buf);

  close(sockfd);

  return 0;
}









int kind(char option) {
  return (static_cast<int>(option) - static_cast<int>('0'));
}

void printGreeting() {
  std::cout << "Bienvenidos a H.O.P." << std::endl;
  std::cout << "Por favor, ingrese la opcion: " << std::endl;
  std::cout << "9 para salir" << std::endl;
  std::cout << "Opcion deseada: ";
}
/*
int main() {
  char option;

  do {
    printGreeting();
    std::cin >> option;
    if(valid(option)) {
      if(kind(option)==SIG_QUIT)
        break;
    }
  } while (1);

  return 0;
}
*/
