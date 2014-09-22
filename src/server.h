#ifndef _SERVER_INCLUDE
#define _SERVER_INCLUDE
#include "decisions.h"
#include "plant.h"

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


class Server {
  public:
    explicit Server(int);
    ~Server();

    void Listen();

    Plant GetPlant();

  private:
    void Communicate(int);
    std::string Process(std::string);

    int _port;
    int sockfd, newfd;  // listen on sock_fd, new connection on new_fd

    Plant _plant;
    //Decisions _d;
};

#endif
