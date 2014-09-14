#include "fertilizer_actuator.h"

FertilizerActuator::FertilizerActuator () {
}

FertilizerActuator::~FertilizerActuator () {
}

bool FertilizerActuator::IsWorking() {
  return false;
}

Quantity FertilizerActuator::SupplyRemaining() {
  return 4;
}

void FertilizerActuator::Send(Quantity q) {
}

