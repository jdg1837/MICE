#include "scoop.h"

Scoop::Scoop(std::string name, std::string description, double cost, double price, State state)
      : Item(name, description, cost, price, state) { }
std::string Scoop::type() {return "Scoop";}
