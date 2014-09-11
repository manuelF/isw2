#ifndef _ANTIBIOTC_ACTUATOR_INCLUDE
#define _ANTIBIOTC_ACTUATOR_INCLUDE
#include "actuator.h"

class AntibioticActuator : public Actuator {
  public:
    AntibioticActuator();
    virtual ~AntibioticActuator();

    virtual bool IsWorking();
    virtual int SupplyRemaining() ;
    virtual void SendLittle();
    virtual void SendLot();
};

#endif
