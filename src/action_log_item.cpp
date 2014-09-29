#include "action_log_item.h"
#include <sstream>

ActionLogItem::ActionLogItem(Decision decision): _decision(decision){
}

ActionLogItem ActionLogItem::Build(std::string decision_string){
	std:: stringstream ss(decision_string);
	std:: string tmp;

	ss >> tmp;
	Quantity water = QuantityHandler::Build(tmp);
	ss >> tmp;
	Quantity light = QuantityHandler::Build(tmp);
	ss >> tmp;
	Quantity fertilizer = QuantityHandler::Build(tmp);
	ss >> tmp;
	Quantity antibiotics = QuantityHandler::Build(tmp);

	return ActionLogItem(Decision(water,light,fertilizer,antibiotics));
}


ActionLogItem::~ActionLogItem() {
}

std::string ActionLogItem::Serialize() {
  return _decision.Serialize();
}
