#ifndef  _ACTUATOR_INCLUDE
#define  _ACTUATOR_INCLUDE

class Actuator {
  virtual bool IsWorking() = 0;
  virtual int SupplyRemaining() = 0;
  virtual void SendLittle() = 0;
  virtual void SendLot() = 0;
};

#endif

