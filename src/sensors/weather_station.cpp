#include <iostream>
#include "weather_station.h"

WeatherStation::WeatherStation() {

}

WeatherStation::~WeatherStation() {

}

WeatherReport WeatherStation::GetForecastWeather() {
  return WeatherReport(10.0);
}

WeatherReport WeatherStation::GetCurrentWeather() {
    std::cout << "WeathStat:: las chances actuales de lluvia son del 10% " << std::endl;
    return WeatherReport(10.0);
}
