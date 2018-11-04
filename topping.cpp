#include "topping.h"
#include <stdexcept>

Topping::Topping(std::string name, std::string description, double cost, double price, State state,
              int amount) :
    Item(name, description, cost, price, state), _amount{amount} { }
std::string Topping::type() {return "Topping";}
int Topping::amount() {return _amount;}
string Topping::amount_text(){
	if(_amount == 1) return "light";
	else if(_amount == 2) return "normal";
	else if(_amount == 3) return "extra";
	else if(_amount == 4) return "drenched";
}
void Topping::_set_amount(int amount) {
    if (0 < amount && amount < 5) _amount = amount;
    else throw std::runtime_error("Invalid topping amount");
}
