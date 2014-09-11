#ifndef _ACTUATORS_HANDLER_INCLUDE
#define _ACTUATORS_HANDLER_INCLUDE

#include "actuator.h"
#include "antibiotic_actuator.h"

class ActuatorsHandler {
  public:
    ActuatorsHandler();
    virtual ~ActuatorsHandler();

  private:
    AntibioticActuator _antibiotic;
#if 0
    Actuator _water;
    Actuator _light;
#endif
};

#endif
