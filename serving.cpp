#include "serving.h"

double Serving::price() const
{
	double price = 0;
	int i;
	
	for(i = 0; i < _scoops.size(); i++)
	{
		price += _scoops[i].price(); 		
	}
	
	if(_toppings.size() != 0)
	{
		for(i = 0; i < _toppings.size(); i++)
		{
			price += _toppings[i].price();
		}
	}
	price += _container.price();
	return price;
}

string Serving::container() const
{
	return _container.name();
}

void Serving::push_scoop(Scoop scoop)
{
	_scoops.push_back(scoop);
}

void Serving::push_topping(Topping topping)
{
	_toppings.push_back(topping);
}

int Serving::get_size_scoop() const
{
	return _scoops.size();
}

int Serving::get_size_topping() const
{
	return _toppings.size();
}

std::string Serving::to_string()
{
        std::string serving = "";
        serving = serving + "Chosen Container: " + _container.name() + '\n';
        int i;
        serving = serving + "Scoops: ";

        for(i = 0; i < _scoops.size(); i++)
        {
                serving = serving + _scoops[i].name() + " ";
        }

        serving = serving + '\n';

	serving = serving + "Toppings: ";

	if(_toppings.size() != 0)
	{
         	for(i = 0; i < _toppings.size(); i++)
		{
                 	serving = serving + _toppings[i].name() + "-" + _toppings[i].amount_text() + "   ";
		}
                serving = serving + '\n';
	}
        else
	{
         	serving = serving + "None\n";
	}

        return serving;
}

void Serving::requests(int c, vector<int> s, vector<int> t)
{
	c_index = c;
	s_req = s;
    	t_req = t;
}

int Serving::get_c_index(){return c_index;}

vector<int> Serving::get_s_req(){return s_req;}

vector<int> Serving::get_t_req(){return t_req;}

void Serving::consume()
{
	_container.consume(1);
	for(int i = 0; i < _scoops.size(); i++)
		_scoops[i].consume(1);

}
