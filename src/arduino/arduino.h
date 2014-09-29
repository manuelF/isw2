#ifndef  _ARDUINO_INCLUDE
#define  _ARDUINO_INCLUDE

#include "port.h"

class Arduino {
public:
    Arduino(Port);
    virtual ~Arduino();

    float readSignal();

    void writeSignal(float signal);
private:
    Port _port;
};

#endif

