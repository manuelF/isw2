#ifndef _EXTERNAL_CONDITIONS_INCLUDE
#define _EXTERNAL_CONDITIONS_INCLUDE

#include <set>
#include "external_anomalies_listener.h"
#include "humidity_sensor.h"
#include "ph_sensor.h"
#include "temperature_sensor.h"
#include "sensors_reading.h"
#include "weather_station.h"

class ExternalConditions {
  public:
    ExternalConditions();
    ~ExternalConditions();

    void Register(ExternalAnomaliesListener*);
    void Unregister(ExternalAnomaliesListener*);

    SensorsReading GetSensorsReading();
    WeatherReport GetCurrentWeather();

  private:
    WeatherStation _weather;
    std::set<ExternalAnomaliesListener*> _listeners;
    HumiditySensor _humidity;
    PHSensor _ph;
    TemperatureSensor _temperature;

};

#endif
