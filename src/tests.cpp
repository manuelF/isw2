#include <iostream>
#include <cstdlib>
#include <cassert>

#include "actuators/actuators_handler.h"
#include "actuators/quantity.h"
#include "level.h"
#include "master_plan.h"
#include "sensors/external_data.h"
#include "basic_datatypes.h"
#include "history.h"

void WriteBeginTest(int i) {
  std::cout << "******************* TEST " << i << " **********************" << std::endl;
}

void WriteEndTest(int i) {
  std::cout << "******************* END TEST " << i << " ******************"<< std::endl;
}
void TestTodosLosActuadoresEscriben() {
  WriteBeginTest(1);
  Quantity q_nothing = QuantityHandler::Build("nada");
  Decision d(q_nothing, q_nothing, q_nothing, q_nothing);
  ActuatorsHandler ah;
  ah.ExecuteDecision(d);
  assert(Arduino::writeCount == 4);
  WriteEndTest(1);
}

void TestModificarEtapaPlanMaestro() {
  WriteBeginTest(2);
  Quantity q_nothing = QuantityHandler::Build("nada");
  Level l_poco = LevelHandler::Build("poco");
  MasterPlan mp = MasterPlan::BuildEmpty();
  mp.AddStage(Stage(1, "Prueba", l_poco, l_poco, l_poco));
  mp.AddStage(Stage(2, "Prueba2", l_poco, l_poco, l_poco));
  mp.AddStage(Stage(3, "Prueba3", l_poco, l_poco, l_poco));
  mp.AddStage(Stage(4, "Prueba4", l_poco, l_poco, l_poco));

  Stage newStage(4, "NuevoStage", l_poco, l_poco, l_poco);
  assert(mp.GetActualStage()._friendly_name == "Prueba4");
  mp.ModifyStage(4, newStage);
  assert(mp.GetActualStage()._friendly_name == "NuevoStage");
  WriteEndTest(2);
}

void TestNuevaEntradaEnHistorial() {
  WriteBeginTest(3);
  Quantity q_nothing = QuantityHandler::Build("nada");
  ExternalData ed(Humidity(0.0f), PH(0.0f), Temperature(0.0f), WeatherReport(0.0f));
  History his;
  his.Clear();
  his.InsertExternalConditionLog(ed);
  assert(his.GetLastExternalCondition() == ed);
  WriteEndTest(3);
}

int main(int argc, char* argv[]) {
  TestTodosLosActuadoresEscriben();
  TestModificarEtapaPlanMaestro();
  TestNuevaEntradaEnHistorial();
  std::cout << std::endl << "Todos los test concluyeron exitosamente." << std::endl;
  return 0;
}
