#ifndef _ACTUATORS_HANDLER_INCLUDE
#define _ACTUATORS_HANDLER_INCLUDE

#include "../decision.h"
#include "antibiotic_actuator.h"
#include "fertilizer_actuator.h"
#include "light_actuator.h"
#include "water_actuator.h"

class ActuatorsHandler {
  public:
    ActuatorsHandler();
    virtual ~ActuatorsHandler();

    void ExecuteDecision(const Decision&);
  private:
    AntibioticActuator _antibiotic;
    WaterActuator _water;
    LightActuator _light;
    FertilizerActuator _fertilizer;
};

#endif
