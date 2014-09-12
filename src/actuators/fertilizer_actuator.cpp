#include "fertilizer_actuator.h"

FertilizerActuator::FertilizerActuator () {
}

FertilizerActuator::~FertilizerActuator () {
}

bool FertilizerActuator::IsWorking() {
  return false;
}

int FertilizerActuator::SupplyRemaining() {
  return 4;
}

void FertilizerActuator::SendLittle() {
}

void FertilizerActuator::SendLot() {
}
