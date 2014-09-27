#include "decisions.h"

Decisions::Decisions() :
  _history("default_log"),
  _timer(60*5, static_cast<TimerNotifiable*>(this)) {
    _timer.Start();
}

Decisions::~Decisions() {
  _timer.Stop();
}

void Decisions::TimerExpired() {
  std::cout << "Decisions Timer" << std::endl;
}


