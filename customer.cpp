#include "customer.h"

Customer::Customer(string name, string id, string phone): Person(name, id), _phone{phone} {};

string Customer::get_phone(){return _phone;}
