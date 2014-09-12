#ifndef _PLANT_INCLUDE
#define _PLANT_INCLUDE
#include "history.h"

class Plant {
  public:
    Plant(History&);
    virtual ~Plant();

  private:
    History& _historical_logger;
};

#endif
