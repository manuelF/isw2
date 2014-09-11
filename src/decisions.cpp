#include "decisions.h"

Decisions::Decisions(std::string filename) : _external(), _plan(filename) {
  _external.Register(static_cast<ExternalAnomaliesListener*>(this));
}

Decisions::Decisions() : _external(), _plan("default_plan") {
  _external.Register(static_cast<ExternalAnomaliesListener*>(this));
}

Decisions::~Decisions() {
  _external.Unregister(static_cast<ExternalAnomaliesListener*>(this));
}

void Decisions::ExternalNotification(WeatherReport wr) {
  std::cout << "We have external notification" << std::endl;
}

int main(int argc, char* argv[]) {

  /* We have to create sockets to make this class the server with an
   * attachable GUI
  */
  Decisions d;

  std::cout << "Prueba" << std::endl;

}
