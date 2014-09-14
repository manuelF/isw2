#include "water_actuator.h"

WaterActuator::WaterActuator () {
}

WaterActuator::~WaterActuator () {
}

bool WaterActuator::IsWorking() {
  return false;
}

Quantity WaterActuator::SupplyRemaining() {
  return 4;
}

void WaterActuator::Send(Quantity q) {
}
