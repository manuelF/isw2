#ifndef _MESSAGES_INCLUDE
#define _MESSAGES_INCLUDE

#include <string>
#include "plant.h"
#include "master_plan.h"

class Server;
class GUI;

class Message {
  public:
    virtual std::string Serialize() = 0;
    virtual Message* Execute(Server&) = 0;
    virtual Message* Execute(GUI&) = 0;
};

class MessageBuilder {
  public:
    static Message* Build(std::string);
};


class MessageGetPlant : public Message {
  public:
    std::string Serialize();
    Message* Execute(Server&);
    Message* Execute(GUI&);
};

class MessageReturnPlant : public Message {
  public:
    explicit MessageReturnPlant(Plant);
    std::string Serialize();
    Message* Execute(Server&);
    Message* Execute(GUI&);

  private:
    Plant _plant;
};

class MessageGetMasterPlan : public Message {
  public:
    std::string Serialize();
    Message* Execute(Server&);
    Message* Execute(GUI&);
};

class MessageReturnMasterPlan : public Message {
public:
  explicit MessageReturnMasterPlan(MasterPlan);
  std::string Serialize();
  Message* Execute(Server&);
  Message* Execute(GUI&);

private:
  MasterPlan _plan;
};
#endif
