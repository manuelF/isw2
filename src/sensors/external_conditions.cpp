#include "external_conditions.h"

#include <iostream>

ExternalConditions::ExternalConditions()
  : _weather(), _polling_timer(1, static_cast<TimerNotifiable*>(this)) {
    _polling_timer.Start();
}

ExternalConditions::~ExternalConditions() {
  _polling_timer.Stop();
}

SensorsReading ExternalConditions::GetSensorsReading() {
  return SensorsReading(
      _humidity.GetCurrentReading(), _ph.GetCurrentReading(),
      _temperature.GetCurrentReading());
}

WeatherReport ExternalConditions::GetCurrentWeather() {
  return _weather.GetCurrentWeather();
}

WeatherReport ExternalConditions::GetForecastWeather() {
  return _weather.GetForecastWeather();
}

void ExternalConditions::TimerExpired() {
  // GetSensorsReading y enviar
  std::cout << "ExternalConditions::TimerExpired" << std::endl;
}
