#include "antibiotic_actuator.h"

AntibioticActuator::AntibioticActuator () {
}

AntibioticActuator::~AntibioticActuator () {
}

bool AntibioticActuator::IsWorking() {
  return false;
}

Quantity AntibioticActuator::SupplyRemaining() {
  return 4;
}

void AntibioticActuator::Send(Quantity q) {
}
