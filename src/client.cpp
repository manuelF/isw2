#include "gui.h"
#include <iostream>

int main(int argc, char* argv[]) {
  if(argc != 2) {
    std::cout << "usage: ./client hostname" << std::endl;
    return 1;
  }
  GUI g(argv[1], 3490);
  g.Connect();
}







