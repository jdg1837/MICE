#ifndef CONTAINER_H
#define CONTAINER_H

#include "item.h"

class Container : public Item {
  public:
    Container(std::string name, std::string description, double cost, double price, State state,
              int max_scoops);
    std::string type() override;
    int max_scoops();
    void edit_scoops(int);
  private:
    int _max_scoops;
};
#endif
