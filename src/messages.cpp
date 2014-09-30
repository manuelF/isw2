#include "messages.h"
#include "server.h"
#include "gui.h"

#include <iostream>

Message* MessageBuilder::Build(std::string input) {
  if (input == std::string("Q-GET-PLANT"))
    return static_cast<Message*>( new MessageGetPlant());
  if (input.substr(0, 5) == std::string("Plant"))
    return static_cast<Message*> ( new MessageReturnPlant(Plant::Build(input)));
  if (input == std::string("Q-GET-MASTER-PLAN"))
    return static_cast<Message*>( new MessageGetMasterPlan());
  if (input.substr(0, 6) == std::string("Master"))
    return static_cast<Message*> ( new MessageReturnMasterPlan(MasterPlan::BuildFromString(input)));
  if (input == std::string("Q-GET-SENSORS-READING"))
    return static_cast<Message*>( new MessageGetSensorsReading());
  if (input.substr(0, 4) == std::string("Data"))
    return static_cast<Message*> ( new MessageReturnSensorsReading(ExternalData::Build(input)));
  std::cout << "ERRRRRROR con input: " << input  << "intente: " << input.substr(0,5) << std::endl;
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
  return std::string("Q-GET-MASTER-PLAN");
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

/*
 * ***************************
 */

std::string MessageGetSensorsReading::Serialize () {
  return std::string("Q-GET-SENSORS-READING");
}

Message* MessageGetSensorsReading::Execute(Server& s) {
  return new MessageReturnSensorsReading(s.GetSensorsReading());
}

Message* MessageGetSensorsReading::Execute(GUI& s) {
  return NULL;
}

bool MessageGetSensorsReading::ExpectResponse() {
  return true;
}

/*
 * ***************************
 */

MessageReturnSensorsReading::MessageReturnSensorsReading(ExternalData data)
  : _sensors(data) {
}

std::string MessageReturnSensorsReading::Serialize () {
  return _sensors.Serialize();
}

Message* MessageReturnSensorsReading::Execute(Server& s) {
  return NULL;
}

Message* MessageReturnSensorsReading::Execute(GUI& g) {
//TODO Aca hay que imprimir por pantalla
  g.SetSensors(_sensors);
  return NULL;
}

bool MessageReturnSensorsReading::ExpectResponse() {
  return false;
}


