#ifndef _HUMIDITY_SENSOR_INCLUDE
#define _HUMIDITY_SENSOR_INCLUDE

#include "../basic_datatypes.h"
#include "../arduino/arduino.h"

class HumiditySensor {
  public:
    HumiditySensor();
    virtual ~HumiditySensor();
    Humidity GetCurrentReading();
  private:
    Arduino _arduino;

};
#endif
