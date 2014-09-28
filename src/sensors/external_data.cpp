#include "external_data.h"
#include <sstream>

ExternalData::ExternalData(Humidity humidity, PH ph, Temperature temperature, WeatherReport weather_report) :
  humidity(humidity), ph(ph), temperature(temperature), weather_report(weather_report) {
}

std::string ExternalData::Serialize() {
  std::stringstream ss;
  ss << humidity.Serialize() << " ";
  ss << ph.Serialize() << " ";
  ss << temperature.Serialize() << " ";
  ss << weather_report.Serialize() << std::endl;

  return ss.str();
}
