#include "light_actuator.h"

LightActuator::LightActuator () {
}

LightActuator::~LightActuator () {
}

bool LightActuator::IsWorking() {
  return false;
}

int LightActuator::SupplyRemaining() {
  return 4;
}

void LightActuator::SendLittle() {
}

void LightActuator::SendLot() {
}
