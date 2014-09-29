#include "antibiotic_actuator.h"

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
    stdout << "Antibiotic Actuator has sent " << q << endl;
}
