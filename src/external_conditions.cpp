#include "external_conditions.h"

ExternalConditions::ExternalConditions() : _weather() {
}

ExternalConditions::~ExternalConditions() {
}

void ExternalConditions::Register(ExternalAnomaliesListener* listener) {
  _listeners.insert(listener);
}

void ExternalConditions::Unregister(ExternalAnomaliesListener* listener) {
  auto it = _listeners.find(listener);
  if(it!=_listeners.end()) {
    _listeners.erase(it);
  }
}

