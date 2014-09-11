#ifndef  _DECISIONS_INCLUDE
#define  _DECISIONS_INCLUDE

#include <iostream>
#include "external_anomalies_listener.h"
#include "external_conditions.h"
#include "weather_report.h"

class Decisions : public ExternalAnomaliesListener {
  public:
    Decisions();
    virtual ~Decisions();

    void ExternalNotification(WeatherReport wr);

  private:
    /*
     * Pasar esto a puntero, que le pasemos una funcion
     * nuestra para que nos notifique
     */
    ExternalConditions _external;
};

#endif
