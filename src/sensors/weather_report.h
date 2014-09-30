#ifndef _WEATHER_REPORT_INCLUDE
#define _WEATHER_REPORT_INCLUDE
#include <string>

class WeatherReport {
  public:
    WeatherReport(double);
    virtual ~WeatherReport();

    std::string GetContentForDisplay();
    std::string Serialize();

  private:
    double _rain_chance;

};

#endif
