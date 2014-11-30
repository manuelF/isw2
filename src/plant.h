#ifndef _PLANT_INCLUDE
#define _PLANT_INCLUDE
//#include "history.h"
#include <string>
#include <vector>
#include "stage.h"

class Plant {
  public:
    Plant();
    Plant(const Plant&);

    std::string Serialize();
    void AddNewEntry(std::string);
    std::string GetContentForDisplay();

    static Plant Build(std::string);
  private:
    std::vector<std::string> _entries;
//    Stage _stage;
};

#endif
