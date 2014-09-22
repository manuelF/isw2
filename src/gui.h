#ifndef _GUI_INCLUDE
#define _GUI_INCLUDE

#include <string>
#include "master_plan.h"
#include "messages.h"
#include "plant.h"

class GUI {
  public:
    GUI(char*, int);

    void Connect();

    void SetPlant(Plant);
    void SetMasterPlan(MasterPlan);

  private:
    Message* Menu();
    void Communicate(int);

    char* _server;
    int _port;
    int sockfd;
    int _current_screen;
    Plant _plant;
};

#endif
