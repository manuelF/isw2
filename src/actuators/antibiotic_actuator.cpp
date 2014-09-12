#include "antibiotic_actuator.h"

AntibioticActuator::AntibioticActuator () {
}

AntibioticActuator::~AntibioticActuator () {
}

bool AntibioticActuator::IsWorking() {
  return false;
}

int AntibioticActuator::SupplyRemaining() {
  return 4;
}

void AntibioticActuator::SendLittle() {
}

void AntibioticActuator::SendLot() {
}
