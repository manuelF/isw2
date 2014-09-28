#include "quantity.h"
#include <cassert>
#include <iostream>

Quantity QuantityHandler::Build(std::string input) {
  if(input == std::string("nada"))
    return Quantity::NOTHING;
  if(input == std::string("bajo"))
    return Quantity::LOW;
  if(input == std::string("alto"))
    return Quantity::HIGH;
  std::cout << "input no manejado: " << input << std::endl;
  assert(false);
  return Quantity::NOTHING;

}

std::string QuantityHandler::Serialize(Quantity quantity) {
  switch(quantity) {
    case Quantity::NOTHING:
      return "nada";
    case Quantity::LOW:
      return "bajo";
    case Quantity::HIGH:
      return "alto";
  }
  assert(false);
  return "JUNK";
}