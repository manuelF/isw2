#ifndef _EXTERNAL_DATA_INCLUDE
#define _EXTERNAL_DATA_INCLUDE

#include "../basic_datatypes.h"
#include "weather_report.h"
#include <string>

struct ExternalData {
  ExternalData(Humidity, PH, Temperature, WeatherReport);

  bool operator==(const ExternalData&) const;
  std::string Serialize();
  std::string GetContentForDisplay();
  static ExternalData Build(std::string);

  static ExternalData GetSample();

  Humidity humidity;
  PH ph;
  Temperature temperature;
  WeatherReport weather_report;
};

#endif
