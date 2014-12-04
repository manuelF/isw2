#ifndef _PH_SENSOR_INCLUDE
#define _PH_SENSOR_INCLUDE

#include "../basic_datatypes.h"
#include "../arduino/arduino.h"

class PHSensor {
  public:
    PHSensor();
    virtual ~PHSensor();
    PH GetCurrentReading();
    void SetUpForTest();
private:
    Arduino _arduino;

};

#endif
