#include "external_data.h"
#include <sstream>

ExternalData::ExternalData(Humidity humidity, PH ph, Temperature temperature, WeatherReport weather_report) :
  humidity(humidity), ph(ph), temperature(temperature), weather_report(weather_report) {
}

bool ExternalData::operator==(const ExternalData& other) const {
  return humidity == other.humidity && ph == other.ph && temperature == other.temperature;
}

std::string ExternalData::Serialize() {
  std::stringstream ss;
  ss << "Data ";
  ss << humidity.Serialize() << " ";
  ss << ph.Serialize() << " ";
  ss << temperature.Serialize() << " ";
  ss << weather_report.Serialize() << std::endl;

  return ss.str();
}

std::string ExternalData::GetContentForDisplay() {
  std::stringstream ss;
  ss << "Medicion de Sensores: ";
  ss << "Humedad: " << humidity.Serialize() << "% ";
  ss << "PH: " << ph.Serialize() << " ";
  ss << "Temperatura: " << temperature.Serialize() << "C. ";
  ss << weather_report.GetContentForDisplay() << std::endl;

  return ss.str();

}

ExternalData ExternalData::Build(std::string input) {
  std::stringstream ss(input);
  std::string a;
  ss >> a; // Me como el Data
  double t;
  ss >> t; Humidity h(t);
  ss >> t; PH p(t);
  ss >> t; Temperature temp(t);
  ss >> t; WeatherReport wr(t);

  return ExternalData(h,p,temp,wr);
}

ExternalData ExternalData::GetSample() {
  return ExternalData(Humidity(45), PH(5), Temperature(33), WeatherReport(87));
}
