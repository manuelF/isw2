#ifndef _BASIC_DATATYPES_INCLUDE
#define _BASIC_DATATYPES_INCLUDE
#include <string>
#include "level.h"

typedef int Seconds;

class SensedValue{
  public:
    virtual ~SensedValue(){};
    virtual std::string Serialize() = 0;
    virtual Level levelOf() = 0;
  protected:
	//TODO define this values for each class
	float MIN = 0;
	float MAX = 99;
};

class PH: public SensedValue {
  public:
    PH(double value){
    	ph = value;
    }
    virtual ~PH(){};
    std::string Serialize(){
    	return "ph";
    }
    Level levelOf(){
    	//TODO define me properly
    	if (ph < MIN){
    		return LITTLE;
    	} else if (ph < MAX){
    		return MODERATE;
    	} else {
    		return ABUNDANT;
    	}
    }
  private:
  	double ph;
};

class Temperature: public SensedValue {
  public:
    Temperature(double value){
    	temperature = value;
    }
    virtual ~Temperature(){};
    std::string Serialize(){
    	return "temp";
    }
    Level levelOf(){
    	//TODO define me properly
    	if (temperature < MIN){
    		return LITTLE;
    	} else if (temperature < MAX){
    		return MODERATE;
    	} else {
    		return ABUNDANT;
    	}
    }
  private:
  	double temperature;
};

class Humidity: public SensedValue {
  public:
    Humidity(double value){
    	humidity =  value;
    }
    virtual ~Humidity(){};
    std::string Serialize(){
    	return "hum";
    }
    Level levelOf(){
    	//TODO define me properly
    	if (humidity < MIN){
    		return LITTLE;
    	} else if (humidity < MAX){
    		return MODERATE;
    	} else {
    		return ABUNDANT;
    	}
    }
  private:
  	double humidity;
};
#endif
