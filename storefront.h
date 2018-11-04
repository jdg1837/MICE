#ifndef __STOREFRONT_H
#define __STOREFRONT_H
#include "scoop.h"
#include "container.h"
#include "topping.h"
#include "item.h"

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Storefront{
   public:
      void add_Container(Container container);
      void add_Scoop(Scoop scoop);
      void add_Topping(Topping top);

   private:
      vector<Container> containers;
      vector<Scoop> scoops;
      vector<Topping> toppings;
};
#endif 
