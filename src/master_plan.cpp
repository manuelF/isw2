#include "master_plan.h"
#include <sstream>
#include <fstream>
#include <iostream>

MasterPlan::MasterPlan(std::string filename) : _persist(true), _filename(filename) {
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

Stage MasterPlan::GetActualStage() {
    //para la demo siempre es el 4
    _actual_stage = 3;
    return _stages[_actual_stage];
}

Plant MasterPlan::GetPlant() {
  return _plant;
}

void MasterPlan::SetPlant(Plant& other) {
  _plant = other;
}
