#ifndef  _DECISIONS_INCLUDE
#define  _DECISIONS_INCLUDE

#include <iostream>
#include <string>
#include "actuators/actuators_handler.h"
#include "history.h"
#include "master_plan.h"
#include "plant.h"
#include "sensors/external_anomalies_listener.h"
#include "sensors/external_conditions.h"
#include "sensors/weather_report.h"

class Decisions : public ExternalAnomaliesListener {
  public:
    Decisions();
    Decisions(std::string, std::string);
    virtual ~Decisions();

    std::string GetSensorsReading();
    std::string GetForecastWeather();

    void ExternalNotification(WeatherReport wr);

  private:
    /*
     * Pasar esto a puntero, que le pasemos una funcion
     * nuestra para que nos notifique
     */
    ExternalConditions _external;
    MasterPlan _plan;
    ActuatorsHandler _actuators;
    History _history;
    Plant _plant;
};

#endif
