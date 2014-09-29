#ifndef _LOG_ITEM_INCLUDE
#define _LOG_ITEM_INCLUDE
#include <string>

class LogItem {
  public:

    virtual std::string Serialize() = 0;
};

#endif
