#ifndef  _DECISIONS_MAKER_INCLUDE
#define  _DECISIONS_MAKER_INCLUDE

#include <iostream>
#include <string>
#include "actuators/actuators_handler.h"
#include "history.h"
#include "timer.h"

class DecisionsMaker : public TimerNotifiable {
  public:
    DecisionsMaker();
    virtual ~DecisionsMaker();

    void TimerExpired();
  private:
    ActuatorsHandler _actuators;
    History _history;
    Timer _timer;
};

#endif
