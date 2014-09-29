#ifndef _WATER_ACTUATOR_INCLUDE
#define _WATER_ACTUATOR_INCLUDE
#include "actuator.h"
#include "quantity.h"

class WaterActuator : public Actuator {
  public:
    WaterActuator();
    virtual ~WaterActuator();

    virtual bool IsWorking();
    virtual void Send(Quantity);
  private:
    Arduino _arduino;
};

#endif
