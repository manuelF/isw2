#ifndef _BASIC_DATATYPES_INCLUDE
#define _BASIC_DATATYPES_INCLUDE
#include <sstream>
#include "level.h"

typedef int Seconds;

class SensedValue{
  public:
    virtual ~SensedValue(){};
    virtual std::string Serialize() = 0;
    virtual Level levelOf() = 0;
};

class PH: public SensedValue {
  public:

    PH (double value){
    	ph = value;
      MIN = 0; MAX = 99;
    }

    virtual ~PH(){};

    std::string Serialize(){
    	std::stringstream ss;
  		ss << " " << ph << " ";
    	return ss.str();
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
    double MIN;
    double MAX;
  	double ph;
};

class Temperature: public SensedValue {
  public:
    Temperature(double value){
    	temperature = value;
      MIN = 0; MAX = 99;
    }

    virtual ~Temperature(){};

    std::string Serialize(){
    	std::stringstream ss;
  		ss << " " << temperature << " ";
    	return ss.str();
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
    double MIN;
    double MAX;
  	double temperature;
};

class Humidity: public SensedValue {
  public:
    Humidity(double value){
    	humidity =  value;
      MIN = 0; MAX = 99;
    }

    virtual ~Humidity(){};

    std::string Serialize(){
    	std::stringstream ss;
  		ss << " " << humidity << " ";
    	return ss.str();
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
    double MIN;
    double MAX;
  	double humidity;
};
#endif
