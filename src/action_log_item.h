#ifndef _ACTION_LOG_ITEM
#define _ACTION_LOG_ITEM

#include "log_item.h"

class ActionLogItem : public LogItem {
  public:
    ActionLogItem();
    virtual ~ActionLogItem();
    std::string Serialize();
};

#endif
