#include <iostream>
#include "serving.h"
#include "container.h"
#include "topping.h"
#include "scoop.h"

int main() 
{
	int i;	
	std::string x_name = "Waffle Cone";
  	std::string x_description = "A dry, cone-shaped pastry with a waffle texture";
  	double x_cost = 0.30;
  	double x_price = 0.99;
  	int x_max_scoops = 3;

  	Container container{x_name, x_description, x_cost, x_price, x_max_scoops};

	Serving serving{container};

	serving.push_scoop(Scoop("Chocolate", "Chocolatey Goodness", 3.00, 3.50));
	serving.push_scoop(Scoop("Vanilla", "Vanillaaaaa", 2.00, 2.50));

	serving.push_topping(Topping("Candy Sprinkles", "sprinkle sprinkle", 0.01, 0.20, 1));
	serving.push_topping(Topping("Brownie Bites", "brown", 0.02, 0.40, 1));

	if(serving.get_size_scoop() != 2)
	{
		std::cerr << "Wrong size" << std::endl;
	}

	if(serving.get_size_topping() != 2)
	{
		std::cerr << "Wrong topping size" << std::endl;
	}

	if(serving.price() - 7.59 > 0.000000001)
	{
		std::cout << serving.price() << std::endl;
		std::cerr << "Wrong price!" << std::endl;
	}

	std::cout << serving.to_string() << std::endl;

}
