#include "arduino.h"
#include <iostream>

Arduino::Arduino(Port p) : _port(p){
    //TODO open connection
}

Arduino::~Arduino() {
    //TODO close connection
}

float Arduino::readSignal(){
    //TODO ask for signal
    float r = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
    return r;
}

void Arduino::writeSignal(float signal){
    //TODO write signal
}
