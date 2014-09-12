#include "water_actuator.h"

WaterActuator::WaterActuator () {
}

WaterActuator::~WaterActuator () {
}

bool WaterActuator::IsWorking() {
  return false;
}

int WaterActuator::SupplyRemaining() {
  return 4;
}

void WaterActuator::SendLittle() {
}

void WaterActuator::SendLot() {
}
