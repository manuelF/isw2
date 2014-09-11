#include "weather_station.h"

WeatherStation::WeatherStation() {

}

WeatherStation::~WeatherStation() {

}

WeatherReport WeatherStation::GetForecast() {
  return WeatherReport();
}

WeatherReport WeatherStation::GetCurrentWeather() {
  return WeatherReport();
}

void WeatherStation::NotifyOfSuddenChanges() {
}
