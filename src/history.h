#ifndef _HISTORY_INCLUDE
#define _HISTORY_INCLUDE

#include <vector>
#include "log_item.h"

class History {
  public:
    History();
    virtual ~History();

    void Save(std::string);
    void Load(std::string);

  private:
    std::vector<LogItem> _items;
};

#endif
