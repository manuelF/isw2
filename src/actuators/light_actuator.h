#ifndef _LIGHT_ACTUATOR_INCLUDE
#define _LIGHT_ACTUATOR_INCLUDE
#include "actuator.h"
#include "quantity.h"

class LightActuator : public Actuator {
  public:
    LightActuator();
    virtual ~LightActuator();

    virtual bool IsWorking();
    virtual Quantity SupplyRemaining() ;
    virtual void Send(Quantity);
};

#endif
