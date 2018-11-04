#include "container.h"

Container::Container(std::string name, std::string description, double cost, double price, State state,
              int max_scoops)
          : Item(name, description, cost, price, state), _max_scoops{max_scoops} { }
std::string Container::type() {return "Container";}
int Container::max_scoops() {return _max_scoops;}
void Container::edit_scoops(int scoops){_max_scoops = scoops;}
