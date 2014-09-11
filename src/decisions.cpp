#include "decisions.h"

Decisions::Decisions() : _external() {
  std::cout << "Registering" << std::endl;
  _external.Register(static_cast<ExternalAnomaliesListener*>(this));
}

Decisions::~Decisions() {
  std::cout << "Unregistering" << std::endl;
  _external.Unregister(static_cast<ExternalAnomaliesListener*>(this));
}

void Decisions::ExternalNotification(WeatherReport wr) {
  std::cout << "We have external notification" << std::endl;
}

int main(int argc, char* argv[]) {

  /* We have to create sockets to make this class the server with an
   * attachable GUI
  */
  std::cout << "Prueba" << std::endl;
  Decisions d;


}
