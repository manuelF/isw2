#include <iostream>

#include "weather_station.h"

class Decisions {
  public:
    Decisions();
    virtual ~Decisions();

  private:
    /*
     * Pasar esto a puntero, que le pasemos una funcion
     * nuestra para que nos notifique
     */
    WeatherStation _weather;
};
