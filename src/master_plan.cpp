#include "master_plan.h"
#include <iostream>
#include <sstream>

Stage::Stage(
    int order, std::string name, int target_humidity, double target_ph,
    int target_temperature) : _natural_order(order), _friendly_name(name),
    _humidity_required(target_humidity), _ph_required(target_ph),
    _temperature_required(target_temperature) {
}

Stage::~Stage() {
}



MasterPlan::MasterPlan(std::string filename) {
  /* Abrir el archivo
   * Parsear el MasterPlan del archivo
   * Cargar la estructura local
   */
}

MasterPlan::~MasterPlan() {
}
