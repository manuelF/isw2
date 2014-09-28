#ifndef _QUANTITY_INCLUDE
#define _QUANTITY_INCLUDE
#include <string>

enum Quantity {NOTHING, LOW, HIGH};

class QuantityHandler {
  public:
    static Quantity Build(std::string);
    static std::string Serialize(Quantity);
};

#endif
