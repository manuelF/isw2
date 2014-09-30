#ifndef _MESSAGES_INCLUDE
#define _MESSAGES_INCLUDE

#include <string>
#include "plant.h"
#include "master_plan.h"
#include "sensors/external_data.h"

class Server;
class GUI;

class Message {
  public:
    virtual ~Message() {} ;
    virtual std::string Serialize() = 0;
    virtual Message* Execute(Server&) = 0;
    virtual Message* Execute(GUI&) = 0;
    virtual bool ExpectResponse() = 0;
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
    bool ExpectResponse();
};

class MessageReturnPlant : public Message {
  public:
    explicit MessageReturnPlant(Plant);
    std::string Serialize();
    Message* Execute(Server&);
    Message* Execute(GUI&);
    bool ExpectResponse();

  private:
    Plant _plant;
};

class MessageGetMasterPlan : public Message {
  public:
    std::string Serialize();
    Message* Execute(Server&);
    Message* Execute(GUI&);
    bool ExpectResponse();
};

class MessageReturnMasterPlan : public Message {
  public:
    explicit MessageReturnMasterPlan(MasterPlan);
    std::string Serialize();
    Message* Execute(Server&);
    Message* Execute(GUI&);
    bool ExpectResponse();

  private:
    MasterPlan _plan;
};


class MessageGetSensorsReading : public Message {
  public:
    std::string Serialize();
    Message* Execute(Server&);
    Message* Execute(GUI&);
    bool ExpectResponse();
};


class MessageReturnSensorsReading : public Message {
  public:
    explicit MessageReturnSensorsReading(ExternalData);
    std::string Serialize();
    Message* Execute(Server&);
    Message* Execute(GUI&);
    bool ExpectResponse();
  private:
    ExternalData _sensors;
};
#endif
