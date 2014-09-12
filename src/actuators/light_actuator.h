#ifndef _LIGHT_ACTUATOR_INCLUDE
#define _LIGHT_ACTUATOR_INCLUDE
#include "actuator.h"

class LightActuator : public Actuator {
  public:
    LightActuator();
    virtual ~LightActuator();

    virtual bool IsWorking();
    virtual int SupplyRemaining() ;
    virtual void SendLittle();
    virtual void SendLot();
};

#endif
