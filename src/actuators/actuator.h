#ifndef  _ACTUATOR_INCLUDE
#define  _ACTUATOR_INCLUDE
#include "quantity.h"

class Actuator {
  virtual bool IsWorking() = 0;
  virtual void Send(Quantity) = 0;
};

#endif

