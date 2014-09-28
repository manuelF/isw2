#include "decisions_maker.h"

DecisionsMaker::DecisionsMaker() :
  //_history("default_log"),
  _timer(60*5, static_cast<TimerNotifiable*>(this)) {
    _timer.Start();
}

DecisionsMaker::~DecisionsMaker() {
  _timer.Stop();
}

void DecisionsMaker::TimerExpired() {
  std::cout << "DecisionsMaker Timer" << std::endl;
}


