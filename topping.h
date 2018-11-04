#ifndef TOPPING_H
#define TOPPING_H

#include "item.h"

using namespace std;

class Topping : public Item {
  public:
    Topping(std::string name, std::string description, double cost, double price, State state, int amount);
    std::string type() override;
    int amount();
    string amount_text();
    const static int LIGHT_AMOUNT = 1;
    const static int NORMAL_AMOUNT = 2;
    const static int EXTRA_AMOUNT = 3;
    const static int DRENCHED_AMOUNT = 4;
    void _set_amount(int amount);
  private:
//    void _set_amount(int amount);
    int _amount;
};
#endif
