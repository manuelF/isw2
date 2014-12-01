#include "external_conditions_reader.h"

#include <iostream>

ExternalConditionsReader::ExternalConditionsReader(History& his)
  : _polling_timer(1*1, static_cast<TimerNotifiable*>(this)), _history(his) {
  _polling_timer.Start();
}

ExternalConditionsReader::~ExternalConditionsReader() {
  _polling_timer.Stop();
}

ExternalData ExternalConditionsReader::GetSensorsReading() {
  return ExternalData(
      _humidity.GetCurrentReading(), _ph.GetCurrentReading(),
      _temperature.GetCurrentReading(), _weather.GetCurrentWeather());
}

void ExternalConditionsReader::TimerExpired() {
  ExternalData ed = GetSensorsReading();
  std::cout << "ECR:: Se senso: " << ed.GetContentForDisplay() << std::endl;
  _history.InsertExternalConditionLog(ed);
  std::cout << "ECR:: persisti en el historial las mediciones tomadas." << std::endl;
}
