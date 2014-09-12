#include "weather_station.h"

WeatherStation::WeatherStation() {

}

WeatherStation::~WeatherStation() {

}

WeatherReport WeatherStation::GetForecastWeather() {
  return WeatherReport(13.0);
}

WeatherReport WeatherStation::GetCurrentWeather() {
  return WeatherReport(88.0);
}

void WeatherStation::NotifyOfSuddenChanges() {
}
