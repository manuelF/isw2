#ifndef _TIMER_NOTIFIABLE_INCLUDE
#define _TIMER_NOTIFIABLE_INCLUDE

class TimerNotifiable {
  public:
    virtual void TimerExpired() = 0;
};

#endif
