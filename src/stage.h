#ifndef _STAGE_H
#define _STAGE_H
#include <string>
#include "level.h"

struct Stage {
  Stage(int, std::string, Level, Level, Level);
  virtual ~Stage();
  std::string Serialize();
  std::string GetContentForDisplay();

  static Stage Build(std::string);

  int _natural_order;
  std::string _friendly_name;
  Level _humidity_required;
  Level _ph_required;
  Level _temperature_required;
};

#endif
