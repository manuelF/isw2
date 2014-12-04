#include <iostream>
#include "ph_sensor.h"
#include "../arduino/arduino.h"

PHSensor::PHSensor() : _arduino(Arduino(8085)){

}

PHSensor::~PHSensor(){

}

void PHSensor::SetUpForTest() {
  _arduino.SetUpForTest();
}

PH PHSensor::GetCurrentReading() {
  //TODO define proper translation to ph
  PH ph = PH(_arduino.readSignal() * 14);
  std::cout << "PH-S:: el nivel de ph sensado es: " << LevelHandler::Serialize(ph.levelOf()) << std::endl;
  return ph;
}
