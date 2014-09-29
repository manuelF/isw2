#include "decisions_maker.h"

DecisionsMaker::DecisionsMaker(History his) : _history(his), _timer(60*5, static_cast<TimerNotifiable*>(this)) {
    _timer.Start();
    _actuators_handler = ActuatorsHandler();
}

DecisionsMaker::~DecisionsMaker() {
    _timer.Stop();
}

void DecisionsMaker::TimerExpired() {
    ExternalData ed = _history.GetLastExternalCondition();
    //TODO take a decision
    Decision des = Decision(NOTHING,LOW,HIGH,NOTHING);
    _actuators_handler.ExecuteDecision(des);
    _history.InsertActionLog(des);
}


