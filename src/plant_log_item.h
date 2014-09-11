#ifndef _PLANT_LOG_ITEM
#define _PLANT_LOG_ITEM

#include "log_item.h"

class PlantLogItem : public LogItem {
  public:
    PlantLogItem();
    virtual ~PlantLogItem();
    std::string Serialize();
};

#endif
