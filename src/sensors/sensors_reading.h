#ifndef _SENSORS_READING_INCLUDE
#define _SENSORS_READING_INCLUDE

#include <string>

struct SensorsReading {
  SensorsReading(double, double, double);

  std::string Serialize();

  double humidity;
  double ph;
  double temperature;
};

#endif
