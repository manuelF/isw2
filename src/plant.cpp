#include "plant.h"
#include <sstream>
#include <cassert>
#include <iostream>

Plant::Plant() {
}

Plant::Plant(const Plant& other) {
  _entries = std::vector<std::string>(other._entries.begin(), other._entries.end());
}

std::string Plant::Serialize() {
  std::stringstream ss;
  ss << std::string("Plant ");
  for (auto &e : _entries) {
    ss << e << std::endl;
  }
  return ss.str();
}

void Plant::AddNewEntry(std::string item) {
  _entries.push_back(item);
}

std::string Plant::GetContentForDisplay() {
  if (_entries.empty()) {
    return std::string("No hay entradas en la planta");
  }
  else {
    std::stringstream ss;
    for (auto &e : _entries) {
      ss << "2014/09/28 : " << e << std::endl;
    }
    return ss.str();
  }
}

Plant Plant::Build(std::string input) {
  std::stringstream ss(input);
  std::string member;
  Plant target;
  assert(ss.str().substr(0,5) == std::string("Plant"));
  ss >> member; // to trim the "Plant"
  ss.ignore();
  while (getline(ss, member)) {
    if (member !=std::string( ""))
      target.AddNewEntry(member);
  }
  return target;
}

