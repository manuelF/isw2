#include "external_conditions_log_item.h"
#include <sstream>

ExternalConditionsLogItem ExternalConditionsLogItem::Build(std::string wr){
	std:: stringstream ss(wr);
	double tmp;

	ss >> tmp;
	Humidity humidity = Humidity(tmp);
  	ss >> tmp;
	PH ph = PH(tmp);
  	ss >> tmp;
  	Temperature temperature = Temperature(tmp);
  	ss >> tmp;
	WeatherReport weather_report = WeatherReport(tmp);

  	return ExternalConditionsLogItem(ExternalData(humidity,ph,temperature,weather_report));
}

ExternalConditionsLogItem::ExternalConditionsLogItem(ExternalData wr): _external_data(wr){
}

ExternalConditionsLogItem::~ExternalConditionsLogItem() {
}

std::string ExternalConditionsLogItem::Serialize() {
  return _external_data.Serialize();
}

ExternalData ExternalConditionsLogItem::GetExternalData() {
  return _external_data;
}
