#ifndef _MESSAGES_INCLUDE
#define _MESSAGES_INCLUDE

#include <string>
#include "plant.h"

class Server;

class Message {
  public:
    virtual std::string Serialize() = 0;
    virtual Message* Execute(Server&) = 0;
};

class MessageBuilder {
  public:
    static Message* Build(std::string);
};


class MessageGetPlant : public Message {
  public:
    std::string Serialize();
    Message* Execute(Server&);
};

class MessageReturnPlant : public Message {
  public:
    explicit MessageReturnPlant(Plant);
    std::string Serialize();
    Message* Execute(Server& );

  private:
    Plant _plant;
};

#endif
