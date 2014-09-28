#include "decision.h"
#include <sstream>

Decision::Decision(Quantity water, Quantity light, Quantity fertilizer, Quantity antibiotic) :
  water(water), light(light), fertilizer(fertilizer), antibiotic(antibiotic) {
}

std::string Decision::Serialize() {
  std::stringstream ss;
  ss << QuantityHandler::Serialize(water) << " ";
  ss << QuantityHandler::Serialize(light) << " ";
  ss << QuantityHandler::Serialize(fertilizer) << " ";
  ss << QuantityHandler::Serialize(antibiotic) << std::endl;

  return ss.str();
}
