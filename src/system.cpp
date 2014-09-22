#include "server.h"

int main(int argc, char* argv[]) {

  /* We have to create sockets to make this class the server with an
   * attachable GUI
  */
  Server s(3490);
  s.Listen();
}
