#ifndef _ACTION_LOG_ITEM
#define _ACTION_LOG_ITEM
#include <string>
#include "decision.h"
#include "log_item.h"

class ActionLogItem : public LogItem {
  public:
    ActionLogItem(Decision);
    ActionLogItem(std::string);
    virtual ~ActionLogItem();
    std::string Serialize();
  private:
  	Decision _decision;
};

#endif
