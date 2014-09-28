#include "action_log_item.h"
#include <sstream>

ActionLogItem::ActionLogItem(Decision decision): _decision(decision){
}

ActionLogItem::ActionLogItem(std::string desicion_string):
		_decision(Decision(Quantity::NOTHING,Quantity::NOTHING,Quantity::NOTHING,Quantity::NOTHING)){
	std:: stringstream ss(desicion_string);
	std:: string tmp;

	ss >> tmp;
	Quantity water = QuantityHandler::Build(tmp);
	ss >> tmp;
	Quantity ligth = QuantityHandler::Build(tmp);
	ss >> tmp;
	Quantity fertilizer = QuantityHandler::Build(tmp);
	ss >> tmp;
	Quantity antibiotics = QuantityHandler::Build(tmp);

	_decision = Decision(water,ligth,fertilizer,antibiotics);
}


ActionLogItem::~ActionLogItem() {
}

std::string ActionLogItem::Serialize() {
  return _decision.Serialize();
}
