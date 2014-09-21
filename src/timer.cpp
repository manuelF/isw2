#include "timer.h"

Timer::Timer(Seconds s, TimerNotifiable* n) :
  _interval(s), _to_awake(n), _abort(false), _started(false) {

  _control_thread = std::thread(&Timer::Trigger, this);
}

Timer::~Timer() {
  Stop();
  if(_control_thread.joinable())
    _control_thread.join();
}

void Timer::Start() {
  _abort = false;
  _started = true;
}

void Timer::Stop() {
  _abort = true;
}

void Timer::Trigger() {
  while(1) {
    std::this_thread::sleep_for(_interval);
    if (!_started) continue;
    if (_abort) return;
    _to_awake->TimerExpired();
  }
}
