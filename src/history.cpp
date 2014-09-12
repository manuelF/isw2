#include "history.h"
#include <iostream>

History::History(std::string filename) : _current_filename(filename) {
  Load(filename);
}

History::~History() {
  Save(_current_filename);
}

void History::Insert() {
  //_items.push_back(item);
}

void History::Save(std::string filename) {
  for(auto &i : _items) {
    std::string result = i.Serialize();
    std::cout << result;
  }
}

void History::Load(std::string filename) {
  /*
   * Abrir el archivo
   * Mientras haya lineas
   *  Levantarla
   *  Identificar si es planta o es accion
   *  Crear ActionLogItem o PlantLogItem
   *  Insertarla a _items
   */
}
