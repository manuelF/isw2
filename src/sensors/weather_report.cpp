#include "weather_report.h"
#include <sstream>

WeatherReport::WeatherReport(double rain_chance) : _rain_chance(rain_chance) {
}

WeatherReport::~WeatherReport() {
}

std::string WeatherReport::GetContentForDisplay() {
  std::stringstream ss;
  ss << _rain_chance << "% probabilidad de lluvia";
  return ss.str();
}

std::string WeatherReport::Serialize() {
  std::stringstream ss;
  ss << _rain_chance;
  return ss.str();
}
