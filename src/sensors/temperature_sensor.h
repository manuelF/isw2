#ifndef _TEMPERATURE_SENSOR_INCLUDE
#define _TEMPERATURE_SENSOR_INCLUDE

#include "sensor.h"

class TemperatureSensor : public Sensor {
  public:
    double GetCurrentReading();
};
#endif
