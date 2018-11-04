#ifndef __SERVING_H
#define __SERVING_H

#include "container.h"
#include "scoop.h"
#include "topping.h"
#include <vector>
#include <string>

using namespace std;

class Serving
{
	public:
		Serving(Container container) : _container{container} {};
		string container() const;
		double price() const;
		void push_scoop(Scoop scoop);
		void push_topping(Topping topping);
		int get_size_topping() const;
		int get_size_scoop() const;
		std::string to_string();
		void requests(int, vector<int>, vector<int>);
		int get_c_index();
		vector<int> get_s_req();
        	vector<int> get_t_req();
		void consume();

	private:
		Container _container;
		std::vector<Scoop> _scoops;
		std::vector<Topping> _toppings;
        	std::vector<int> t_req;
		int c_index = -1;
		std::vector<int> s_req;
};

#endif
