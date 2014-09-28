#ifndef _EXTERNAL_DATA_INCLUDE
#define _EXTERNAL_DATA_INCLUDE

#include "../basic_datatypes.h"
#include "weather_report.h"
#include <string>

struct ExternalData {
  ExternalData(Humidity, PH, Temperature, WeatherReport);

  std::string Serialize();

  Humidity humidity;
  PH ph;
  Temperature temperature;
  WeatherReport weather_report;
};

#endif
