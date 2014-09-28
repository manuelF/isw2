#ifndef _DECISION_INCLUDE
#define _DECISION_INCLUDE
#include "actuators/quantity.h"

struct Decision {
  Quantity light;
  Quantity water;
  Quantity fertilizer;
  Quantity antibiotic;
};
#endif

