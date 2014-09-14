#ifndef _EXTERNAL_ANOMALIES_INCLUDE
#define _EXTERNAL_ANOMALIES_INCLUDE

#include "weather_report.h"

class ExternalAnomaliesListener {
  public:
    virtual void ExternalNotification(WeatherReport wr) = 0;
};

#endif
