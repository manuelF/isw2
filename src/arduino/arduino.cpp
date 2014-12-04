#include "arduino.h"
#include <iostream>
#include <random>


Arduino::Arduino(Port p) : _port(p), _isTest(false) {
    //TODO open connection
}

Arduino::~Arduino() {
    //TODO close connection
}

float Arduino::readSignal(){
    //TODO ask for signal
    float r = 1.0;
    if (!_isTest)
      r = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
    return r;
}

void Arduino::writeSignal(float signal){
    //TODO write signal
    Arduino::writeCount++;
}

void Arduino::ResetWriteCountForTest() {
  writeCount = 0;
}

void Arduino::SetUpForTest() {
  _isTest = true;
}

int Arduino::writeCount;
