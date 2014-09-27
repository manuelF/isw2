#ifndef  _DECISIONS_INCLUDE
#define  _DECISIONS_INCLUDE

#include <iostream>
#include <string>
#include "actuators/actuators_handler.h"
#include "history.h"
#include "timer.h"

class Decisions : public TimerNotifiable {
  public:
    Decisions();
    virtual ~Decisions();

    void TimerExpired();
  private:
    ActuatorsHandler _actuators;
    History _history;
    Timer _timer;
};

#endif
