#include <iostream>
#include "humidity_sensor.h"
#include "../arduino/arduino.h"

HumiditySensor::HumiditySensor() : _arduino(Arduino(8084)){
}

HumiditySensor::~HumiditySensor(){
}

void HumiditySensor::SetUpForTest() {
  _arduino.SetUpForTest();
}

Humidity HumiditySensor::GetCurrentReading() {
    //TODO define proper translation to humidity percentage
    Humidity h = Humidity(_arduino.readSignal() * 100);
    std::cout << "HS:: el nivel de humedad sensado es: " << LevelHandler::Serialize(h.levelOf())<< std::endl;
  return h;
}
