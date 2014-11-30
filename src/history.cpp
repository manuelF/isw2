#include "history.h"
#include "sensors/external_data.h"
#include <iostream>
#include <sstream>
#include <fstream>

History::History(){
    _actions_filename = "actions.his";
    _plant_filename = "plant.his";
    _external_data_filename = "external_data.his";
    Load();
}

History::~History() {
  Save();
}

void History::InsertActionLog(Decision d){
    _actions_items.push_back(ActionLogItem(d));
}

void History::InsertPlantLog(std::string s){
    _plant_items.push_back(PlantLogItem(s));
}

void History::InsertExternalConditionLog(ExternalData ed){
    _external_condition_items.push_back(ExternalConditionsLogItem(ed));
}

ExternalData History::GetLastExternalCondition(){
    return _external_condition_items.back().GetExternalData();
}

template <class LogType>
void SaveThisCollectionOnThisFile(std::vector<LogType> vector, std::string file){
    std::ofstream output(file);
    output << "HistorySize: " << vector.size() << " ";
    for(auto &s : vector) {
        output << s.Serialize() << std::endl;
    }
}

void History::Save() {
    SaveThisCollectionOnThisFile(_actions_items,_actions_filename);
    SaveThisCollectionOnThisFile(_plant_items, _plant_filename);
    SaveThisCollectionOnThisFile(_external_condition_items,_external_data_filename);
}

template <class LogType>
void LoadThisCollectionFromThisFile(std::vector<LogType>& vector, std::string filename){
    std::ifstream input(filename);
    std::string tmp("MasterPlan 0");
    while(input.good()){
        getline(input, tmp);
        vector.push_back(LogType::Build(tmp));
    }
}

void History::Load() {
  /*
   * Abrir el archivo
   * Mientras haya lineas
   *  Levantarla
   *  Identificar si es planta o es accion
   *  Crear ActionLogItem o PlantLogItem
   *  Insertarla a _items
   */
}

void History::Clear() {
}
