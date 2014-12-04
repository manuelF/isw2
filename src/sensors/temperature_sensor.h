#ifndef _TEMPERATURE_SENSOR_INCLUDE
#define _TEMPERATURE_SENSOR_INCLUDE

#include "../basic_datatypes.h"
#include "../arduino/arduino.h"

class TemperatureSensor {
  public:
    TemperatureSensor();
    virtual ~TemperatureSensor();
    Temperature GetCurrentReading();
    void SetUpForTest();
  private:
    Arduino _arduino;
};
#endif
