#ifndef  _DECISIONS_MAKER_INCLUDE
#define  _DECISIONS_MAKER_INCLUDE

#include <iostream>
#include <string>
#include "actuators/actuators_handler.h"
#include "history.h"
#include "timer.h"
#include "master_plan.h"

class DecisionsMaker : public TimerNotifiable {
  public:
    DecisionsMaker(History&, MasterPlan&); //Should this be a pointer to History? TODO para manu
    virtual ~DecisionsMaker();

    void TimerExpired();
  private:
    ActuatorsHandler _actuators_handler;
    History& _history;
    MasterPlan& _master_plan;
    Timer _timer;
};

#endif
