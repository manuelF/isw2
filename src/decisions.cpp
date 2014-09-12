#include "decisions.h"

Decisions::Decisions(std::string plan_filename, std::string history_filename)
    :  _plan(MasterPlan::BuildFromFile(plan_filename)),
       _history(history_filename),
       _plant(_history) {
  _external.Register(static_cast<ExternalAnomaliesListener*>(this));
}

Decisions::Decisions() :
  _plan(MasterPlan::BuildFromFile("default_plan")),
  _history("default_log"),
  _plant(_history) {
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
