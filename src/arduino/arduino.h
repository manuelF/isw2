#ifndef  _ARDUINO_INCLUDE
#define  _ARDUINO_INCLUDE

class Arduino {
public:
    Arduino();
    virtual ~Arduino();

    float readSignal(Port p);

    void writeSignal(Port p, float signal);
};

#endif

