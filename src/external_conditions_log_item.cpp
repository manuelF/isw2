#include "external_conditions_log_item.h"
#include <sstream>

ExternalConditionsLogItem::ExternalConditionsLogItem(std::string wr): _external_data(ExternalData(Humidity(0),PH(0),Temperature(0),WeatherReport(0))){
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

  	_external_data = ExternalData(humidity,ph,temperature,weather_report);
}

ExternalConditionsLogItem::ExternalConditionsLogItem(ExternalData wr): _external_data(wr){
}

ExternalConditionsLogItem::~ExternalConditionsLogItem() {
}

std::string ExternalConditionsLogItem::Serialize() {
  return _external_data.Serialize();
}
