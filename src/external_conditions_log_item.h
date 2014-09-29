#ifndef _EXTERNAL_CONDITIONS_LOG_ITEM
#define _EXTERNAL_CONDITIONS_LOG_ITEM

#include "log_item.h"
#include <string>
#include "sensors/external_data.h"

class ExternalConditionsLogItem : public LogItem {
  public:
    ExternalConditionsLogItem(std::string);
    ExternalConditionsLogItem(ExternalData);
    virtual ~ExternalConditionsLogItem();
    std::string Serialize();
    static ExternalConditionsLogItem Build(std::string);
    ExternalData GetExternalData();
  private:
  	ExternalData _external_data;
};

#endif
