#ifndef _PLANT_INCLUDE
#define _PLANT_INCLUDE
#include "history.h"

class Plant {
  public:
    Plant();
    virtual ~Plant();
    std::string Serialize();

    static Plant Build(std::string);
};

#endif
