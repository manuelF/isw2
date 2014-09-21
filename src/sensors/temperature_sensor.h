#ifndef _TEMPERATURE_SENSOR_INCLUDE
#define _TEMPERATURE_SENSOR_INCLUDE

#include "../basic_datatypes.h"

class TemperatureSensor {
  public:
    Temperature GetCurrentReading();
};
#endif
