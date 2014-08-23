#include <cstdio>
#include <cstdlib>
#include <iostream>

using std::cin;
using std::cout;

bool valid(char option) {
  return (('1'<=option) && ('9'>=option));
}

#define SIG_QUIT 9
#define SIG_HELP 1

int kind(char option) {
  return (static_cast<int>(option) - static_cast<int>('0'));
}

void printGreeting() {
  cout << "Bienvenidos a H.O.P." << std::endl;
  cout << "Por favor, ingrese la opcion: " << std::endl;
  cout << "9 para salir" << std::endl;
  cout << "Opcion deseada: ";
}

int main() {
  char option;

  do {
    printGreeting();
    cin >> option;
    if(valid(option)) {
      if(kind(option)==SIG_QUIT)
        break;
    }
  } while (1);

  return 0;
}
