#include "plant_log_item.h"

PlantLogItem::PlantLogItem(std::string) {
}

PlantLogItem PlantLogItem::Build(std::string log){
    return PlantLogItem(log);
}

PlantLogItem::~PlantLogItem() {
}

std::string PlantLogItem::Serialize() {
  return _log;
}
