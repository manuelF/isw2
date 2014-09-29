#include "water_actuator.h"
#include <iostream>

WaterActuator::WaterActuator () : _arduino(Arduino(8083)) {
}

WaterActuator::~WaterActuator () {
}

bool WaterActuator::IsWorking() {
  return true;
}

void WaterActuator::Send(Quantity q) {
    //TODO define me
    _arduino.writeSignal(15);
    std::cout << "Water Actuator has sent " << q << std::endl;
}
