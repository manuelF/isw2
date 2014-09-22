#include "messages.h"
#include "server.h"
#include "gui.h"

Message* MessageBuilder::Build(std::string input) {
  if (input == std::string("Q-GET-PLANT"))
    return static_cast<Message*>( new MessageGetPlant());
  if (input.substr(0, 5) == std::string("Plant"))
    return static_cast<Message*> ( new MessageReturnPlant(Plant::Build(input)));
  if (input == std::string("Q-GET-MASTER-PLAN"))
    return static_cast<Message*>( new MessageGetMasterPlan());
  if (input.substr(0, 5) == std::string("Master"))
    return static_cast<Message*> ( new MessageReturnMasterPlan(MasterPlan::BuildFromString(input)));
  return NULL;
}

/*
 * ***************************
 */

std::string MessageGetPlant::Serialize () {
  return std::string("Q-GET-PLANT");
}

Message* MessageGetPlant::Execute(Server& s) {
  return new MessageReturnPlant(s.GetPlant());
}

Message* MessageGetPlant::Execute(GUI& s) {
  return NULL;
}

bool MessageGetPlant::ExpectResponse() {
  return true;
}

/*
 * ***************************
 */

MessageReturnPlant::MessageReturnPlant(Plant plant) : _plant(plant) {
}

std::string MessageReturnPlant::Serialize () {
  return _plant.Serialize();
}

Message* MessageReturnPlant::Execute(Server &s) {
  s.SetPlant(_plant);
  return NULL;
}

Message* MessageReturnPlant::Execute(GUI &g) {
  g.SetPlant(_plant);
  return NULL;
}

bool MessageReturnPlant::ExpectResponse() {
  return false;
}
/*
 * ***************************
 */

std::string MessageGetMasterPlan::Serialize () {
  return std::string("Q-GET-MASTERPLAN");
}

Message* MessageGetMasterPlan::Execute(Server& s) {
  return new MessageReturnMasterPlan(s.GetMasterPlan());
}

Message* MessageGetMasterPlan::Execute(GUI& s) {
  return NULL;
}

bool MessageGetMasterPlan::ExpectResponse() {
  return true;
}

/*
 * ***************************
 */

MessageReturnMasterPlan:: MessageReturnMasterPlan(MasterPlan plan) : _plan(plan) {
}

std::string MessageReturnMasterPlan::Serialize () {
  return _plan.Serialize();
}

Message* MessageReturnMasterPlan::Execute(Server &s) {
  s.SetMasterPlan(_plan);
  return NULL;
}

Message* MessageReturnMasterPlan::Execute(GUI &g) {
  g.SetMasterPlan(_plan);
  return NULL;
}

bool MessageReturnMasterPlan::ExpectResponse() {
  return false;
}


