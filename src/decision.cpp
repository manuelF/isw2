#include "decision.h"
#include <sstream>

Decision::Decision(Quantity water, Quantity light, Quantity fertilizer, Quantity antibiotics) :
  water(water), light(light), fertilizer(fertilizer), antibiotics(antibiotics) {
}

std::string Decision::Serialize() {
  std::stringstream ss;
  ss << water.Serialize() << " ";
  ss << light.Serialize() << " ";
  ss << fertilizer.Serialize() << " ";
  ss << antibiotics.Serialize() << std::endl;

  return ss.str();
}
