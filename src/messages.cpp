#include "messages.h"
#include "server.h"

Message* MessageBuilder::Build(std::string input) {
  if (input == std::string("Q-GET-PLANT"))
    return static_cast<Message*>( new MessageGetPlant());
  return NULL;
}

std::string MessageGetPlant::Serialize () {
  return std::string("Q-GET-PLANT");
}

Message* MessageGetPlant::Execute(Server& s) {
  return new MessageReturnPlant(s.GetPlant());
}

MessageReturnPlant::MessageReturnPlant(Plant plant) : _plant(plant) {
}

std::string MessageReturnPlant::Serialize () {
  return _plant.Serialize();
}

Message* MessageReturnPlant::Execute(Server &s) {
  return NULL;
}
