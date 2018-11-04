#include <iostream>
#include <string>
#include <cstdlib>
#include "customer.h"

using namespace std;

int main(void)
{
	Customer customer("Conly", "12345", "(123)-456-7890");

	if(customer.get_name() != "Conly")
	{
		cout << "incorrect name" << endl;
	}

	if(customer.get_id() != "12345")
	{
		cout << "incorrect id" << endl;
	}

	if(customer.get_phone() != "(123)-456-7890")
	{
		cout << "incorrect phone" << endl;
	}
}
