#ifndef _LEVEL_INCLUDE
#define _LEVEL_INCLUDE
#include <string>

enum Level {ABUNDANT, MODERATE, LITTLE};

class LevelHandler {
  public:
    static Level Build(std::string);
    static std::string Serialize(Level);
};

#endif
