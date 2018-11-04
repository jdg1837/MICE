#include "storefront.h"

void Storefront::add_Container(Container container){
   containers.push_back(container);
}   

void Storefront::add_Scoop(Scoop scoop){
   scoops.push_back(scoop);
}

void Storefront::add_Topping(Topping top){
   toppings.push_back(top);
}
