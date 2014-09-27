#include "actuators_handler.h"

ActuatorsHandler::ActuatorsHandler() {
}

ActuatorsHandler::~ActuatorsHandler() {
}

void ActuatorsHandler::ExecuteDecision(const Decision& d) {
  _antibiotic.Send(d.antibiotic);
  _water.Send(d.water);
  _light.Send(d.light);
  _fertilizer.Send(d.fertilizer);
}
