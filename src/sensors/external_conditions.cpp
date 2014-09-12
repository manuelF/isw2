#include "external_conditions.h"

#include <iostream>

ExternalConditions::ExternalConditions() : _weather() {
}

ExternalConditions::~ExternalConditions() {
}

void ExternalConditions::Register(ExternalAnomaliesListener* listener) {
  std::cout << "Registering" << std::endl;
  _listeners.insert(listener);
}

void ExternalConditions::Unregister(ExternalAnomaliesListener* listener) {
  std::cout << "Unregistering" << std::endl;
  auto it = _listeners.find(listener);
  if(it!=_listeners.end()) {
    _listeners.erase(it);
  }
}

SensorsReading ExternalConditions::ReadSensors() {
  return SensorsReading(
      _humidity.GetCurrentReading(), _ph.GetCurrentReading(),
      _temperature.GetCurrentReading());
}

WeatherReport ExternalConditions::GetCurrentWeather() {
  return _weather.GetCurrentWeather();
}
