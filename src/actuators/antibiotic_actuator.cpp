#include "antibiotic_actuator.h"
#include <iostream>

AntibioticActuator::AntibioticActuator () : _arduino(Arduino(8080)) {
}

AntibioticActuator::~AntibioticActuator () {
}

bool AntibioticActuator::IsWorking() {
  return true;
}

void AntibioticActuator::Send(Quantity q) {
    //TODO define me
    _arduino.writeSignal(15);
    std::cout << "Antibiotic Actuator has sent " << q << std::endl;
}
