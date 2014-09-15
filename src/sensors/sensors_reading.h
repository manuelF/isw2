#ifndef _SENSORS_READING_INCLUDE
#define _SENSORS_READING_INCLUDE

#include "../basic_datatypes.h"
#include <string>

struct SensorsReading {
  SensorsReading(Humidity, PH, Temperature);

  std::string Serialize();

  Humidity humidity;
  PH ph;
  Temperature temperature;
};

#endif
