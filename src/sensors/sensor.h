#ifndef _SENSOR_INCLUDE
#define _SENSOR_INCLUDE

class Sensor {
  public:
    virtual double GetCurrentReading() = 0;
};

#endif
