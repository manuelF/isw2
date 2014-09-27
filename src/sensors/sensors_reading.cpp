#include "sensors_reading.h"
#include <sstream>

SensorsReading::SensorsReading(Humidity humidity, PH ph, Temperature temperature) :
  humidity(humidity), ph(ph), temperature(temperature) {
}

std::string SensorsReading::Serialize() {
  std::stringstream ss;
  ss << humidity.Serialize() << " ";
  ss << ph.Serialize() << " ";
  ss << temperature.Serialize() << std::endl;

  return ss.str();
}
