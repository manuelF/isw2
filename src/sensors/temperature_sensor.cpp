#include "temperature_sensor.h"
#include "../arduino/arduino.h"

TemperatureSensor::TemperatureSensor() : _arduino(Arduino(8086)){

}

TemperatureSensor::~TemperatureSensor(){

}

Temperature TemperatureSensor::GetCurrentReading() {
    //TODO define proper translation to degrees
  return Temperature(_arduino.readSignal() * 50 - 10);
}
