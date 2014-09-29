#include "humidity_sensor.h"
#include "../arduino/arduino.h"

HumiditySensor::HumiditySensor() : _arduino(Arduino(8084)){
}

HumiditySensor::~HumiditySensor(){
}

Humidity HumiditySensor::GetCurrentReading() {
    //TODO define proper translation to humidity percentage
  return Humidity(_arduino.readSignal() * 100);
}
