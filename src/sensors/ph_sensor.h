#ifndef _PH_SENSOR_INCLUDE
#define _PH_SENSOR_INCLUDE

#include "sensor.h"

class PHSensor : public Sensor {
  public:
    double GetCurrentReading();
};

#endif
