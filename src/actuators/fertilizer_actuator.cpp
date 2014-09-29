#include "fertilizer_actuator.h"

FertilizerActuator::FertilizerActuator () : _arduino(Arduino(8081)) {
}

FertilizerActuator::~FertilizerActuator () {
}

bool FertilizerActuator::IsWorking() {
  return true;
}

void FertilizerActuator::Send(Quantity q) {
    //TODO define me
    _arduino.writeSignal(15);
    stdout << "Fertilizer Actuator has sent " << q << endl;
}

