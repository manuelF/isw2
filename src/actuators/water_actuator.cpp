#include "water_actuator.h"

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
    stdout << "Water Actuator has sent " << q << endl;
}
