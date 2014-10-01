#include "master_plan.h"
#include <sstream>
#include <fstream>
#include <iostream>

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
  ss << "--- " << _friendly_name;
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

MasterPlan::MasterPlan(std::string filename) : _stages(), _filename(filename), _persist(true) {
}

MasterPlan MasterPlan::BuildEmpty() {
  MasterPlan plan("not_valid");
  plan._persist = false;
  return plan;
}

MasterPlan MasterPlan::BuildFromString(std::string all_stages) {
  MasterPlan plan = MasterPlan::BuildEmpty();
  std::stringstream input (all_stages);
  std::string tmp;
  int quantity_stages;
  input >> tmp; //Me como el "MasterPlan"
  input >> quantity_stages;

  for (int i = 0; i < quantity_stages; i++) {
    getline(input, tmp);
    plan._stages.push_back(Stage::Build(tmp));
  }
  return plan;
}

MasterPlan MasterPlan::BuildFromFile(std::string filename) {
  std::ifstream input(filename);
  std::string tmp("MasterPlan 0");
  std::string t ;
  while(input.good()) {
    getline(input, tmp);
    t += tmp + "\n";
  }
  MasterPlan plan(BuildFromString(t));
  plan._filename = filename;
  return plan;
}

std::string MasterPlan::Serialize() {
  std::stringstream ss;
  ss << "MasterPlan ";
  ss << _stages.size() << " ";
  for(auto &s: _stages) { // TODO: caracter extra al final?
    ss << s.Serialize() << " \n";
  }
  return ss.str();
}

void MasterPlan::AddStage(Stage s) {
  _stages.push_back(s);
}

void MasterPlan::ModifyStage(int i, Stage s) {
  _stages[i-1]=s;
}

std::string MasterPlan::GetContentForDisplay() {
  if(_stages.empty()) {
    return "Ninguna etapa definida actualmente";
  }
  std::stringstream output;
  for(auto &s : _stages) {
    output << s.GetContentForDisplay() << std::endl;
  }
  return output.str();
}

MasterPlan::~MasterPlan() {
  if(!_persist) return;
  std::ofstream output(_filename);
  output << "MasterPlan " << _stages.size() << " ";
  for(auto &s : _stages) {
    output << s.Serialize() << std::endl;
  }
}

