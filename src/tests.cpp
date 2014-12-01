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
#include "sensors/external_conditions_reader.h"

template <class T>
void WriteBeginTest(T i) {
  std::cout << "******************* TEST " << i << " **********************" << std::endl;
}

template <class T>
void WriteEndTest(T i) {
  std::cout << "******************* END TEST " << i << " ******************"<< std::endl;
}
void TestTodosLosActuadoresEscriben() {
  WriteBeginTest("Todos los actuadores escriben");
  Quantity q_nothing = QuantityHandler::Build("nada");
  Decision d(q_nothing, q_nothing, q_nothing, q_nothing);
  ActuatorsHandler ah;
  ah.ExecuteDecision(d);
  assert(Arduino::writeCount == 4);
  WriteEndTest("Todos los actuadores escriben");
}

void TestModificarEtapaPlanMaestro() {
  WriteBeginTest("Agregar y Modificar etapas plan maestro");
  Level l_poco = LevelHandler::Build("poco");
  Level l_abundante = LevelHandler::Build("abundante");
  MasterPlan mp = MasterPlan::BuildEmpty();
  mp.AddStage(Stage(1, "Prueba", l_poco, l_poco, l_abundante));
  mp.AddStage(Stage(2, "Prueba2", l_poco, l_abundante, l_poco));
  mp.AddStage(Stage(3, "Prueba3", l_abundante, l_poco, l_poco));
  mp.AddStage(Stage(4, "Prueba4", l_poco, l_poco, l_poco));

  Stage newStage(4, "NuevoStage", l_poco, l_poco, l_poco);
  assert(mp.GetActualStage()._friendly_name == "Prueba4");
  mp.ModifyStage(4, newStage);
  assert(mp.GetActualStage()._friendly_name == "NuevoStage");
  WriteEndTest("Agregar y Modificar etapas plan maestro");
}

void TestNuevaEntradaEnHistorial() {
  WriteBeginTest("Agregar una entrada al historial");
  ExternalData ed(Humidity(0.0f), PH(0.0f), Temperature(0.0f), WeatherReport(0.0f));
  ExternalData ed2(Humidity(0.0f), PH(0.0f), Temperature(0.0f), WeatherReport(0.0f));
  History his;
  his.Clear();
  his.InsertExternalConditionLog(ed);
  assert(his.GetLastExternalCondition() == ed);
  WriteEndTest("Agregar una entrada al historial");
}

void TestCondicionesExternas() {
  WriteBeginTest("Los sensores miden correctamente");
  History his;
  ExternalConditionsReader ecr(his);
  ExternalData ed = ecr.GetSensorsReading();
  WriteEndTest("Los sensores miden correctamente");
}

int main(int argc, char* argv[]) {
  TestTodosLosActuadoresEscriben();
  TestModificarEtapaPlanMaestro();
  TestNuevaEntradaEnHistorial();
  TestCondicionesExternas();
  std::cout << std::endl << "Todos los test concluyeron exitosamente." << std::endl;
  return 0;
}
