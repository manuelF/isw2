#ifndef _FERTILIZER_ACTUATOR_INCLUDE
#define _FERTILIZER_ACTUATOR_INCLUDE
#include "actuator.h"

class FertilizerActuator : public Actuator {
  public:
    FertilizerActuator();
    virtual ~FertilizerActuator();

    virtual bool IsWorking();
    virtual int SupplyRemaining() ;
    virtual void SendLittle();
    virtual void SendLot();
};

#endif
