#include "timer.h"

Timer::Timer(Seconds s, TimerNotifiable& n) :
  _interval(s), _to_awake(n), _abort(false) {
}

Timer::~Timer() {
  Stop();
}

void Timer::Start() {
  _abort = false;
  _control_thread = std::move(std::thread(&Timer::Trigger, this));
}

void Timer::Stop() {
  _abort = true;
}

void Timer::Trigger() {
  while(1) {
    std::this_thread::sleep_for(_interval);
    if (_abort) break;
    _to_awake.TimerExpired();
  }
}
