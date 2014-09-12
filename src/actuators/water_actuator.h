#ifndef _WATER_ACTUATOR_INCLUDE
#define _WATER_ACTUATOR_INCLUDE
#include "actuator.h"

class WaterActuator : public Actuator {
  public:
    WaterActuator();
    virtual ~WaterActuator();

    virtual bool IsWorking();
    virtual int SupplyRemaining() ;
    virtual void SendLittle();
    virtual void SendLot();
};

#endif
