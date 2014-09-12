#ifndef _HISTORY_INCLUDE
#define _HISTORY_INCLUDE

#include <vector>
#include "log_item.h"

class History {
  public:
    History(std::string);
    virtual ~History();

    void Insert();

    void Save(std::string);

  private:
    void Load(std::string);

    std::string _current_filename;
    std::vector<LogItem> _items;
};

#endif
