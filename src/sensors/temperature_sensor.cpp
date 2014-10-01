#include <iostream>
#include "temperature_sensor.h"
#include "../arduino/arduino.h"

TemperatureSensor::TemperatureSensor() : _arduino(Arduino(8086)){

}

TemperatureSensor::~TemperatureSensor(){

}

Temperature TemperatureSensor::GetCurrentReading() {
    //TODO define proper translation to degrees
    Temperature t =  Temperature(_arduino.readSignal() * 50 - 10);
    std::cout << "Temp-S:: el nivel de temperatura sensado es: " << LevelHandler::Serialize(t.levelOf()) << std::endl;
    return t;
}
