#ifndef _PLANT_LOG_ITEM
#define _PLANT_LOG_ITEM

#include "log_item.h"

class PlantLogItem : public LogItem {
  public:
    PlantLogItem(std::string);
    virtual ~PlantLogItem();
    std::string Serialize();
    static PlantLogItem Build(std::string);

  private:
    std::string _log;
};

#endif
