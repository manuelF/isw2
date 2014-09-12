#include "weather_report.h"

class WeatherStation {
  public:
    WeatherStation();
    virtual ~WeatherStation();
    void NotifyOfSuddenChanges();


    WeatherReport GetCurrentWeather();
    WeatherReport GetForecastWeather();
};
