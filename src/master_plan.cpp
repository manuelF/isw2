#include "master_plan.h"
#include <sstream>
#include <fstream>

Stage::Stage(
    int order, std::string name, int target_humidity, double target_ph,
    int target_temperature) : _natural_order(order), _friendly_name(name),
    _humidity_required(target_humidity), _ph_required(target_ph),
    _temperature_required(target_temperature) {
}

Stage::~Stage() {
}

std::string Stage::Serialize() {
  std::stringstream ss;
  ss << _natural_order;
  ss << _friendly_name;
  ss << _humidity_required;
  ss << _ph_required;
  ss << _temperature_required;
  return ss.str();
}

Stage Stage::Build(std::string input) {
  std::stringstream ss(input);
  int order; ss >> order;
  std::string name; ss >> name;
  int target_humidity; ss >> target_humidity;
  double target_ph; ss >> target_ph;
  int target_temperature; ss >> target_temperature;

  return Stage(order, name, target_humidity, target_ph, target_temperature);
}

MasterPlan::MasterPlan(std::string filename) : _filename(filename) {
}

MasterPlan MasterPlan::BuildFromString(std::string all_stages) {
  MasterPlan plan("default_plan");
  std::stringstream input (all_stages);
  std::string tmp;

  while(input >> tmp) {
    plan._stages.push_back(Stage::Build(tmp));
  }
  return plan;
}

MasterPlan MasterPlan::BuildFromFile(std::string filename) {
  MasterPlan plan(filename);
  std::ifstream input(filename);
  std::string tmp;
  while(input >> tmp) {
    plan._stages.push_back(Stage::Build(tmp));
  }
  return plan;
}

MasterPlan::~MasterPlan() {
  std::ofstream output(_filename);
  for(auto &s : _stages) {
    output << s.Serialize() << std::endl;
  }
}

