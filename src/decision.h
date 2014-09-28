#ifndef _DECISION_INCLUDE
#define _DECISION_INCLUDE
#include "actuators/quantity.h"
#include <string>


struct Decision {
  public:
  	Decision(Quantity, Quantity, Quantity, Quantity);

	std::string Serialize();

	Quantity water;
	Quantity light;
	Quantity fertilizer;
	Quantity antibiotic;
};


#endif
