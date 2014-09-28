
#include "level.h"
#include <cassert>
#include <iostream>

Level LevelHandler::Build(std::string input) {
  if(input == std::string("abundante"))
    return Level::ABUNDANT;
  if(input == std::string("moderado"))
    return Level::MODERATE;
  if(input == std::string("poco"))
    return Level::LITTLE;
  std::cout << "input no manejado: " << input << std::endl;
  assert(false);
  return Level::ABUNDANT;

}

std::string LevelHandler::Serialize(Level level) {
  switch(level) {
    case Level::ABUNDANT:
      return "abundante";
    case Level::MODERATE:
      return "moderado";
    case Level::LITTLE:
      return "poco";
  }
  assert(false);
  return "JUNK";
}

