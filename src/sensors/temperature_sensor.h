#ifndef _TEMPERATURE_SENSOR_INCLUDE
#define _TEMPERATURE_SENSOR_INCLUDE

#include "../basic_datatypes.h"
typedef double Temperature;

class TemperatureSensor {
  public:
    Temperature GetCurrentReading();
};
#endif
