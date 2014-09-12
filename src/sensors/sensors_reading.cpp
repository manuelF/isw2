#include "sensors_reading.h"
#include <sstream>

SensorsReading::SensorsReading(double humidity, double ph, double temperature) :
  humidity(humidity), ph(ph), temperature(temperature) {
}

std::string SensorsReading::Serialize() {
  std::stringstream ss;
  ss << humidity << " ";
  ss << ph << " ";
  ss << temperature << std::endl;

  return ss.str();
}
