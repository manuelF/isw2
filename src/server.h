#ifndef _SERVER_INCLUDE
#define _SERVER_INCLUDE
#include "master_plan.h"
#include "messages.h"
#include "plant.h"


class Server {
  public:
    explicit Server(int);
    virtual ~Server();

    void Listen();

    Plant GetPlant();
    void SetPlant(Plant);
    MasterPlan GetMasterPlan();
    void SetMasterPlan(MasterPlan);

  private:
    void Communicate(int);
    int _port;
    int _listener, _newconnection;  // listen on sock_fd, new connection on new_fd

    Plant _plant;
    MasterPlan _plan;
    //Decisions _d;
};

#endif
