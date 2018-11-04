#include "topping.h"
#include <iostream>

int main() {
  std::string expected = "";
  bool passed = true; // Optimist!

  //
  // Test constructor
  //

  std::string x_name = "Maraschino Cherry";
  std::string x_description = "A sweet, plump cherry preserved in maraschino syrup";
  double x_cost = 0.10;
  double x_price = 0.50;
  int x_amount = Topping::EXTRA_AMOUNT;

  Topping topping{x_name, x_description, x_cost, x_price, x_amount};

  if (topping.name() != x_name ||
      topping.description() != x_description ||
      topping.cost() != x_cost ||
      topping.price() != x_price ||
      topping.type() != "Topping" ||
      topping.amount() != Topping::EXTRA_AMOUNT) {
    std::cerr << "#### Topping constructor fail" << std::endl;
    std::cerr << "Expected: " << x_name << ','
                              << x_description << ','
                              << x_cost << ','
                              << x_price << ','
                              << "Topping" << ','
                              << x_amount << std::endl;
    std::cerr << "Actual:   " << topping.name() << ','
                              << topping.description() << ','
                              << topping.cost() << ','
                              << topping.price() << ','
                              << topping.type() << ','
                              << topping.amount() << std::endl;
    passed = false;
  }

  //
  // Report results
  //
}
