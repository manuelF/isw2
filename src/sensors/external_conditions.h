#ifndef _EXTERNAL_CONDITIONS_INCLUDE
#define _EXTERNAL_CONDITIONS_INCLUDE

#include <set>
#include "weather_station.h"
#include "external_anomalies_listener.h"

class ExternalConditions {
  public:
    ExternalConditions();
    ~ExternalConditions();

    void Register(ExternalAnomaliesListener*);
    void Unregister(ExternalAnomaliesListener*);

  private:
    WeatherStation _weather;
    std::set<ExternalAnomaliesListener*> _listeners;
};

#endif
