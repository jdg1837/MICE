#ifndef SCOOP_H
#define SCOOP_H

#include "item.h"

class Scoop : public Item {
  public:
    Scoop(std::string name, std::string description, double cost, double price, State state);
    std::string type() override;
};
#endif
