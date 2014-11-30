#include "stage.h"
#include <sstream>

Stage::Stage(
    int order, std::string name, Level target_humidity, Level target_ph,
    Level target_temperature) : _natural_order(order), _friendly_name(name),
    _humidity_required(target_humidity), _ph_required(target_ph),
    _temperature_required(target_temperature) {
}

Stage::~Stage() {
}

std::string Stage::Serialize() {
  std::stringstream ss;
  ss << _natural_order << " ";
  ss << _friendly_name << " ";
  ss << LevelHandler::Serialize(_humidity_required) << " ";
  ss << LevelHandler::Serialize(_ph_required) << " ";
  ss << LevelHandler::Serialize(_temperature_required);
  return ss.str();
}

std::string Stage::GetContentForDisplay() {
  std::stringstream ss;
  //TODO: Cambiar este serialize por una representacion de mucho poco nada
  ss << Serialize() << std::endl;
  return ss.str();
}

Stage Stage::Build(std::string input) {
  std::stringstream ss(input);
  int order; ss >> order;
  std::string name; ss >> name;
  std::string target_humidity; ss >> target_humidity;
  std::string target_ph; ss >> target_ph;
  std::string target_temperature; ss >> target_temperature;

  return Stage(order, name, LevelHandler::Build(target_humidity), LevelHandler::Build(target_ph),
      LevelHandler::Build(target_temperature));
}

