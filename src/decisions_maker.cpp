#include "decisions_maker.h"

DecisionsMaker::DecisionsMaker(History& his, MasterPlan& mp) :
        _history(his), _master_plan(mp), _timer(60*5, static_cast<TimerNotifiable*>(this)) {
    _timer.Start();
    _actuators_handler = ActuatorsHandler();
}

DecisionsMaker::~DecisionsMaker() {
    _timer.Stop();
}

void DecisionsMaker::TimerExpired() {
    std::cout << "DM:: Invocado el tomador de decisiones" << std::endl;

    ExternalData ed = _history.GetLastExternalCondition();
    std::cout << "DM:: Leidas las condiciones externas del historial:" << std::endl;
    std::cout << ed.Serialize() << std::endl;

    Stage s = _master_plan.GetActualStage();
    std::cout << "DM:: Leida la etapa actual del plan maestro: " << std::endl;
    std::cout << s.Serialize() << std::endl;

    std::cout << "DM:: Se tomo la decision dado el estado actual del sistema: " << std::endl;
    //TODO take a decision
    Decision des = Decision(NOTHING,LOW,HIGH,NOTHING);
    std::cout << des.Serialize() << std::endl;

    std::cout << "DM:: Se envia la decision al manejador de actuadores." << std::endl;
    _actuators_handler.ExecuteDecision(des);
    std::cout << "DM:: Guardo la decision en el historial." << std::endl;
    _history.InsertActionLog(des);
}


