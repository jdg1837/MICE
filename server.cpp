#include "server.h"

Server::Server(string name, string id, double wage): Person(name, id), total_orders{0}, _wage{wage} {};

void Server::increase_orders(){total_orders++;}

int Server::get_orders(){return total_orders;}

void Server::set_orders(int order_count){total_orders = order_count;}

double Server::get_wage(){return _wage;}

void Server::set_wage()
{
	int new_wage;
	while(true)
	{
	string in = Dialogs::input("Enter new wage: ", "Change Salary", to_string(_wage), "CANCEL");
	if(in == "CANCEL") return;
	try
	{
		new_wage = stof(in.c_str());
	}
	catch(exception e)
	{
		Dialogs::message("Wage must be numerical", "Error");
		continue;
	}
	break;
	}
	_wage = new_wage;
}
