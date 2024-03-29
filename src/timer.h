#ifndef _TIMER_INCLUDE
#define _TIMER_INCLUDE
#include <chrono>
#include <thread>
#include "timer_notifiable.h"
#include "basic_datatypes.h"

class Timer {
  public:
    Timer(Seconds, TimerNotifiable*);
    virtual ~Timer();

    void Start();
    void Stop();

  private:
    void Trigger();

    std::chrono::seconds _interval;
    TimerNotifiable* _to_awake;
    bool _abort;
    bool _started;
    std::thread _control_thread;
};

#endif
