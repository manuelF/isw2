#include "ph_sensor.h"
#include "../arduino/arduino.h"

PHSensor::PHSensor() : _arduino(Arduino(8085)){

}

virtual PHSensor::~PHSensor(){

}

PH PHSensor::GetCurrentReading() {
    //TODO define proper translation to ph
  return PH(_arduino.readSignal() * 14);
}
