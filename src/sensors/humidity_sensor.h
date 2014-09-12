#ifndef _HUMIDITY_SENSOR_INCLUDE
#define _HUMIDITY_SENSOR_INCLUDE

#include "sensor.h"

class HumiditySensor : public Sensor {
  public:
    double GetCurrentReading();
};
#endif
