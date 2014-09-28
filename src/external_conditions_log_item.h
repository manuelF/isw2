#ifndef _ACTION_LOG_ITEM
#define _ACTION_LOG_ITEM

#include "log_item.h"
#include <string>
#include "sensors/external_data.h"

class ExternalConditionsLogItem : public LogItem {
  public:
    ExternalConditionsLogItem(std::string);
    ExternalConditionsLogItem(ExternalData);
    virtual ~ExternalConditionsLogItem();
    std::string Serialize();
  private:
  	ExternalData _external_data;
};

#endif
