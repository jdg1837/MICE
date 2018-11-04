
ostream& operator+=(ostream& os, const Serving& serving);

ostream& operator+=(ostream& os, const Serving& serving)
{   
	os << _container.name() << ": " << serving.get_size_scoop() << " Scoops, " << serving.get_size_topping() << "Toppings" << "Price: $" << serving.price() << '\n';
	return os;
}        

int confirm_order()
{
	double price = order.price();
	string confirmation = "";

	for(int i = 0; i < servings.size(); i++)
	{
		message += servings[i];
	}

	message += "\nTotal cost:                                     $";
	message += to_string(price);
	
	int confirmation = question(message, "Confirm order");

	if(confirmation == 0) return 0;
	else return 1;
}

void show_order()
{
	string order = "";
	for(int i = 0; i < servings.size(); i++)
	{
		string buffer = serving[i].to_string();
		order += buffer;
	}
	message(order, "Order");
}
