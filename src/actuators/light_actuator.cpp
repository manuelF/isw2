#include "light_actuator.h"

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
    stdout << "Light Actuator has sent " << q << endl;
}
