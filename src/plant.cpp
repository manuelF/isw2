#include "plant.h"
#include <sstream>
#include <cassert>

Plant::Plant() {
}

Plant::~Plant() {
}

Plant Plant::Build(std::string input) {
  std::stringstream ss;
  ss << input;

  Plant target;
  assert(ss.str() == std::string( "Plant"));
  return target;
}

std::string Plant::Serialize() {
  return std::string("Plant ");
}
