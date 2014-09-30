#ifndef _GUI_INCLUDE
#define _GUI_INCLUDE

#include <string>
#include "master_plan.h"
#include "messages.h"
#include "plant.h"
#include "sensors/external_data.h"

class GUI {
  public:
    GUI(char*, int);

    void Connect();

    void SetPlant(Plant);
    void SetMasterPlan(MasterPlan);
    void SetSensors(ExternalData);

  private:
    Message* Menu();
    void Communicate(int);

    char* _server;
    int _port;
    int _socket;
    int _current_screen;
    Plant _plant;
    MasterPlan _plan;
    ExternalData _data;
};

#endif
