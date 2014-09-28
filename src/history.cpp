#include "history.h"
#include <iostream>

History::History(){
  Load();
}

History::~History() {
  Save();
}

void History::Insert() {
  //_items.push_back(item);
}

void History::Save() {
  for(auto &i : _actions_items) {
    std::string result = i.Serialize();
    std::cout << result;
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
