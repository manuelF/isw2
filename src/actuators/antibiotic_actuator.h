#ifndef _ANTIBIOTC_ACTUATOR_INCLUDE
#define _ANTIBIOTC_ACTUATOR_INCLUDE
#include "actuator.h"
#include "quantity.h"

class AntibioticActuator : public Actuator {
  public:
    AntibioticActuator();
    virtual ~AntibioticActuator();

    virtual bool IsWorking();
    virtual Quantity SupplyRemaining() ;
    virtual void Send(Quantity);
};

#endif
