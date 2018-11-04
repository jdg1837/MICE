#ifndef __CUSTOMER_H
#define __CUSTOMER_H

#include <iostream>
#include <string>
#include <cstdlib>
#include <exception>

#include "person.h"

using namespace std;


class Customer: public Person{

	public:

		Customer(string name, string id, string phone);

		string get_phone();


	private:

		string _phone;
};
#endif
