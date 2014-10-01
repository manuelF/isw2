#include "gui.h"
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <netdb.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>

#include <arpa/inet.h>

#include <cassert>
#include <iostream>
#include <sstream>

#include "level.h"
#include "messages.h"

Message* GUI::Menu() {
  int chosen_option = 0;
  std::string new_content;
  int new_stage_number;
  std::string new_stage_name;
  std::string new_humidity;
  std::string new_ph;
  std::string new_temperature;
  MasterPlan _temporal_plan = MasterPlan::BuildEmpty();
  while(1) {
    switch(_current_screen) {
      case 0: // Main menu
        std::cout << std::endl;
        std::cout << "******* Pantalla principal" << std::endl;
        std::cout << "0. Salir" << std::endl;
        std::cout << "1. Ver/editar planta " << std::endl;
        std::cout << "2. Ver/editar plan maestro " << std::endl;
        std::cout << "3. Ver la medicion de los sensores " << std::endl;
        std::cout << "Elija la opcion deseada: " ;
        std::cin >> chosen_option;
        switch (chosen_option) {
          case 0: return NULL;
          case 1: _current_screen = 1; // Goto plant view
                  return static_cast<Message*>(new MessageGetPlant());
          case 2: _current_screen = 3; // Goto masterplan view
                  return static_cast<Message*>(new MessageGetMasterPlan());
          case 3: _current_screen = 6; // Goto sensors view
                  return static_cast<Message*>(new MessageGetSensorsReading());
          default: continue;
        }
        assert(false);
        break;
      case 1: // Plant view
        std::cout << std::endl;
        std::cout << "******* Planta" << std::endl;
        std::cout << _plant.GetContentForDisplay() << std::endl;
        std::cout << std::endl;
        std::cout << "0. Volver" << std::endl;
        std::cout << "1. Agregar una entrada a la planta " << std::endl;
        std::cout << "Elija la opcion deseada: " ;
        std::cin >> chosen_option;
        switch (chosen_option) {
          case 0: _current_screen = 0; // Goto main screen
                  continue;
          case 1: _current_screen = 2; // Goto new plant entry
                  continue;
          default: continue;
        }
        assert(false);
        break;
      case 2: // Plant edition
        std::cout << std::endl;
        std::cout << "********* Editando la planta" << std::endl;
        std::cout << "Ingrese una nueva entrada: " ;
        std::cin.ignore();
        getline(std::cin, new_content);
        _plant.AddNewEntry(new_content);
        _current_screen = 1; // Goto plant view
        return static_cast<Message*>(new MessageReturnPlant(_plant));

      case 3: // Master plan view
        std::cout << std::endl;
        std::cout << "****** Plan maestro" << std::endl;
        std::cout << _plan.GetContentForDisplay() << std::endl;
        std::cout << "0. Volver" << std::endl;
        std::cout << "1. Agregar/Reemplazar por un plan nuevo " << std::endl;
        std::cout << "2. Editar el plan actual " << std::endl;
        std::cout << "Elija la opcion deseada: " ;
        std::cin >> chosen_option;
        switch (chosen_option) {
          case 0: _current_screen = 0; // Goto main screen
                  continue;
          case 1: _current_screen = 4; // Goto new master plan
                  _temporal_plan = MasterPlan::BuildEmpty();
                  continue;
          case 2: _current_screen = 5; // Goto edit master plan
                  std::cout << " No implementado todavia " <<std::endl;
                  _current_screen = 3;
                  continue;
          default: continue;
        }
        break;

      case 4: // Master plan new
        std::cout << std::endl;
        std::cout << "****** Nuevo plan maestro" <<  std::endl;
        std::cout << "Plan nuevo:" << std::endl;
        std::cout << _temporal_plan.GetContentForDisplay() << std::endl;
        std::cout << std::endl;
        std::cout << "0. Volver sin guardar" << std::endl;
        std::cout << "1. Volver y guardar el plan" << std::endl;
        std::cout << "2. Agregar entrada al plan" << std::endl;
        std::cout << "Elija la opcion deseada: " ;
        std::cin >> chosen_option;
        switch (chosen_option) {
          case 0: _current_screen = 0; // Goto main screen
                  continue;
          case 1: _current_screen = 3; // Goto new master plan
                  _plan = _temporal_plan;
                  return static_cast<Message*>(new MessageReturnMasterPlan(_plan));
          case 2: // Add new entries
                  std::cout << std::endl << "Ingrese numero de etapa: ";
                  std::cin.ignore(); std::cin >> new_stage_number;
                  std::cout << std::endl <<
                    "Ingrese el nombre de esta etapa: ";
                  std::cin.ignore(); getline(std::cin, new_stage_name);
                  std::cout << std::endl <<
                    "Ingrese la humedad necesaria [poco / moderado / abundante]: ";
                  getline(std::cin, new_humidity);
                  //TODO: if new_content not in [..] repreguntar
                  std::cout << std::endl <<
                    "Ingrese el PH necesario [poco / moderado / abundante]: ";
                  getline(std::cin, new_ph);
                  //TODO: if new_content not in [..] repreguntar
                  std::cout << std::endl <<
                    "Ingrese la temperatura necesaria [poco / moderado / abundante]: ";
                  getline(std::cin, new_temperature);
                  //TODO: if new_content not in [..] repreguntar
                  _temporal_plan.AddStage(Stage(new_stage_number, new_stage_name,
                        LevelHandler::Build(new_humidity), LevelHandler::Build(new_ph),
                        LevelHandler::Build(new_temperature)));
                  continue;
          case 3: // Edit entry
                  std::cout << std::endl << "Ingrese el numero de etapa a editar";
                  std::cin.ignore(); std::cin >> new_stage_number;
                  std::cout << std::endl <<
                    "Ingrese el nombre de esta etapa: ";
                  std::cin.ignore(); getline(std::cin, new_stage_name);
                  std::cout << std::endl <<
                    "Ingrese la humedad necesaria [poco / moderado / abundante]: ";
                  getline(std::cin, new_humidity);
                  //TODO: if new_content not in [..] repreguntar
                  std::cout << std::endl <<
                    "Ingrese el PH necesario [poco / moderado / abundante]: ";
                  getline(std::cin, new_ph);
                  //TODO: if new_content not in [..] repreguntar
                  std::cout << std::endl <<
                    "Ingrese la temperatura necesaria [poco / moderado / abundante]: ";
                  getline(std::cin, new_temperature);
                  //TODO: if new_content not in [..] repreguntar
                  _temporal_plan.ModifyStage(new_stage_number, Stage(new_stage_number, new_stage_name,
                        LevelHandler::Build(new_humidity), LevelHandler::Build(new_ph),
                        LevelHandler::Build(new_temperature)));

          default:
                  continue;
        }
        case 5: // Master plan edition
                 break;
        case 6: //Get sensors reading
                std::cout << std::endl;
                std::cout << "****** Mediciones actuales de sensores" <<  std::endl;
                std::cout << _data.GetContentForDisplay() << std::endl;
                std::cout << std::endl;
                _current_screen = 0;
                break;
        default:
            assert(false);
    }
  }
  return NULL;
}

void GUI::Communicate(int sender_fd) {
  char buf[10000];

    /*
     * Pseudocodigo:
     * while(1):
     *  Interactuar hasta llegar a un menu que necesita algun dato
     *  Construir el mensaje que lo pide
     *  enviarlo
     *  Esperar a recibir la respuesta
     *  construir el mensaje de respuesta
     *  llamarnos a traves del mensaje con una cosa interactiva para seguir avanzando
     *  volver a la pantalla anterior
     */

  while(1) {
    Message* message_needed = Menu();
    if (message_needed == NULL) return; // Exit

    std::string query = message_needed->Serialize();
    if (send(sender_fd, query.c_str(), query.size(), 0) == -1) {
      perror("Error on Communicate::OnSendQuery"); exit(1);
    }

    if (message_needed->ExpectResponse()) {
      int len = 0;
      len = recv(sender_fd, buf, sizeof(buf), 0);
      if( len  > 0){
        buf[len] = '\0';
      }
      else if (len == 0 ) {
        perror("Server cerro la comunicacion"); exit(1);
      }
      else {
        perror("Error on Communicate::OnReceiveResponse"); exit(1);
      }
      Message* message_response = MessageBuilder::Build(std::string(buf));
      message_response->Execute(*this);
      delete message_response;
    }
    delete message_needed;
    memset(buf, 0, sizeof buf);
  }
}


void GUI::Connect() {
  struct addrinfo hints, *servinfo, *p;
  int rv;
  char s[INET6_ADDRSTRLEN];
  std::stringstream ss;
  ss << _port;

  memset(&hints, 0, sizeof hints);
  hints.ai_family = AF_UNSPEC;
  hints.ai_socktype = SOCK_STREAM;

  if ((rv = getaddrinfo(_server, ss.str().c_str(), &hints, &servinfo)) != 0) {
    fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(rv));
    exit(1);
  }

  // loop through all the results and connect to the first we can
  for(p = servinfo; p != NULL; p = p->ai_next) {
    if ((_socket = socket(p->ai_family, p->ai_socktype,
        p->ai_protocol)) == -1) {
      perror("client: socket");
      continue;
    }

    if (connect(_socket, p->ai_addr, p->ai_addrlen) == -1) {
      close(_socket);
      perror("client: connect");
      continue;
    }

    break;
  }

  if (p == NULL) {
    fprintf(stderr, "client: failed to connect\n");
    exit(2);
  }

  void *inet_addr;
  if (( (struct sockaddr *)&p->ai_addr)->sa_family == AF_INET)
    inet_addr = &(((struct sockaddr_in*) (struct sockaddr *)&p->ai_addr)->sin_addr);
  else
    inet_addr = &(((struct sockaddr_in6*) (struct sockaddr *)&p->ai_addr)->sin6_addr);

  inet_ntop(p->ai_family, inet_addr, s, sizeof s);
  printf("client: connecting to %s\n", s);

  freeaddrinfo(servinfo); // all done with this structure

  Communicate(_socket);

  close(_socket);
}

void GUI::SetPlant(Plant plant) {
  _plant = plant;
}

void GUI::SetMasterPlan(MasterPlan plan) {
  _plan = plan;
}

void GUI::SetSensors(ExternalData data) {
  _data = data;
}

GUI::GUI(char* server, int port) : _server(server), _port(port),
  _socket(0), _current_screen(0), _plan(MasterPlan::BuildEmpty()),
  _data(ExternalData::GetSample()) {

}
