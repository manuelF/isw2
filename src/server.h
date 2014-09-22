#ifndef _SERVER_INCLUDE
#define _SERVER_INCLUDE
#include "decisions.h"
#include "plant.h"
#include "master_plan.h"

class Server {
  public:
    explicit Server(int);
    ~Server();

    void Listen();

    Plant GetPlant();
    MasterPlan GetMasterPlan();

  private:
    void Communicate(int);
    std::string Process(std::string);

    int _port;
    int sockfd, newfd;  // listen on sock_fd, new connection on new_fd

    Plant _plant;
    MasterPlan _plan;
    //Decisions _d;
};

#endif
