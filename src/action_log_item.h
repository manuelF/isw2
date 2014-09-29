#ifndef _ACTION_LOG_ITEM
#define _ACTION_LOG_ITEM
#include <string>
#include "decision.h"
#include "log_item.h"

class ActionLogItem : public LogItem {
  public:
    ActionLogItem(Decision);
    virtual ~ActionLogItem();
    std::string Serialize();
    static ActionLogItem Build(std::string);
  private:
  	Decision _decision;

};

#endif
