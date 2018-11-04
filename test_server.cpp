#include <iostream>
#include <string>
#include <cstdlib>
#include "server.h"

using namespace std;

int main(void)
{
	Server server("Darin", "12345", 13.25);

	if(server.get_name() != "Darin")
	{
		cout << "incorrect name" << endl;
	}

	if(server.get_id() != "12345")
	{
		cout << "incorrect id" << endl;
	}

	if(server.get_orders() != 0)
	{
		cout << "incorrect orders" << endl;
	}

	if(server.get_wage() != 13.25)
	{
		cout << "incorrect wage" << endl;
	}
}
