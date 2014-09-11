#ifndef  _DECISIONS_INCLUDE
#define  _DECISIONS_INCLUDE

#include <iostream>
#include <string>
#include "external_anomalies_listener.h"
#include "external_conditions.h"
#include "master_plan.h"
#include "weather_report.h"

class Decisions : public ExternalAnomaliesListener {
  public:
    Decisions();
    Decisions(std::string);
    virtual ~Decisions();

    void ExternalNotification(WeatherReport wr);

  private:
    /*
     * Pasar esto a puntero, que le pasemos una funcion
     * nuestra para que nos notifique
     */
    ExternalConditions _external;
    MasterPlan _plan;
};

#endif
