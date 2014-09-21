#include "light_actuator.h"

LightActuator::LightActuator () {
}

LightActuator::~LightActuator () {
}

bool LightActuator::IsWorking() {
  return false;
}

Quantity LightActuator::SupplyRemaining() {
  return 4;
}

void LightActuator::Send(Quantity q) {
}
