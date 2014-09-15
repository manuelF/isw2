#ifndef _HUMIDITY_SENSOR_INCLUDE
#define _HUMIDITY_SENSOR_INCLUDE

#include "../basic_datatypes.h"

class HumiditySensor {
  public:
    Humidity GetCurrentReading();
};
#endif
