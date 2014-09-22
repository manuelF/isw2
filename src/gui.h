#ifndef _GUI_INCLUDE
#define _GUI_INCLUDE

#include <string>

class GUI {
  public:
    GUI(char*, int);

    void Connect();

  private:
    void Communicate(int);
    std::string Process(std::string);

    char* _server;
    int _port;
    int sockfd;
};

#endif
