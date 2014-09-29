#include "light_actuator.h"
#include <iostream>

LightActuator::LightActuator () : _arduino(Arduino(8082)) {
}

LightActuator::~LightActuator () {
}

bool LightActuator::IsWorking() {
  return false;
}

void LightActuator::Send(Quantity q) {
    //TODO define me
    _arduino.writeSignal(15);
    std::cout << "Light Actuator has sent " << q << std::endl;
}
