#include <iostream>
#include "actuators_handler.h"

ActuatorsHandler::ActuatorsHandler() {
}

ActuatorsHandler::~ActuatorsHandler() {
}

void ActuatorsHandler::ExecuteDecision(const Decision& d) {
    std::cout << "AH:: recibi la decision." << std::endl;
    std::cout << "AH:: envio la decision al actuador de antibioticos: " << d.antibiotic << std::endl;
    _antibiotic.Send(d.antibiotic);
    std::cout << "AH:: envio la decision al actuador de agua: " << d.water << std::endl;
    _water.Send(d.water);
    std::cout << "AH:: envio la decision al actuador de luz y calor: " << d.light << std::endl;
    _light.Send(d.light);
    std::cout << "AH:: envio la decision al actuador de fertilizante: " << d.fertilizer << std::endl;
    _fertilizer.Send(d.fertilizer);
}
