#ifndef _SERVER_INCLUDE
#define _SERVER_INCLUDE
#include "master_plan.h"
#include "messages.h"
#include "plant.h"
#include "sensors/external_data.h"
#include "history.h"
#include "decisions_maker.h"
#include "sensors/external_conditions_reader.h"

class Server {
  public:
    explicit Server(int);
    virtual ~Server();

    void Listen();

    Plant GetPlant();
    void SetPlant(Plant);
    MasterPlan GetMasterPlan();
    void SetMasterPlan(MasterPlan);
    ExternalData GetSensorsReading();


  private:
    void Communicate(int);
    int _port;
    int _listener, _newconnection;  // listen on sock_fd, new connection on new_fd

    Plant _plant;
    MasterPlan _plan;
    //History _history;
    //DecisionsMaker _decisions_maker;
    //ExternalConditionsReader _external_conditions_reader;
};

#endif
