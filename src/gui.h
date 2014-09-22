#ifndef _GUI_INCLUDE
#define _GUI_INCLUDE

#include <string>
#include "messages.h"

class GUI {
  public:
    GUI(char*, int);

    void Connect();

  private:
    Message* Menu();
    void Communicate(int);
    std::string Process(std::string);

    char* _server;
    int _port;
    int sockfd;
    int _current_screen;
};

#endif
