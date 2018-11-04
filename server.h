#ifndef __SERVER_H
#define __SERVER_H

#include <iostream>
#include <string>
#include <cstdlib>
#include <exception>

#include "person.h"
#include "dialogs.h"

using namespace std;

class Server: public Person{

	public:

		Server(string name, string id, double wage);

		int get_orders();
		void set_orders(int);
		void increase_orders();
		double get_wage();
		void set_wage();

	private:

		int total_orders;
		double _wage;

};
#endif
