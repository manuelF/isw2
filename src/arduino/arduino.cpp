#include "arduino.h"
#include <iostream>

Arduino::Arduino(){
    //TODO open connection
}

Arduino::~Arduino() {
    //TODO close connection
}

float Arduino::readSignal(Port p){
    //TODO ask for signal
    return -1;
}

void Arduino::writeSignal(Port p, float signal){
    //TODO write signal
}
