#ifndef _FERTILIZER_ACTUATOR_INCLUDE
#define _FERTILIZER_ACTUATOR_INCLUDE
#include "actuator.h"
#include "quantity.h"

class FertilizerActuator : public Actuator {
  public:
    FertilizerActuator();
    virtual ~FertilizerActuator();

    virtual bool IsWorking();
    virtual void Send(Quantity);
  private:
    Arduino _arduino;
};

#endif
