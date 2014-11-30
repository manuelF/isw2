#ifndef  _ARDUINO_INCLUDE
#define  _ARDUINO_INCLUDE

#include "port.h"


class Arduino {
public:
    Arduino(Port);
    virtual ~Arduino();

    float readSignal();

    void writeSignal(float signal);

    static void ResetWriteCountForTest();
    static int writeCount;
private:
    Port _port;
};

#endif

