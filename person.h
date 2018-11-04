#ifndef __PERSON_H
#define __PERSON_H

#include <iostream>
#include <string>
#include <cstdlib>
#include <exception>

using namespace std;


class Person{

	public:	
		Person(string name, string id): _name(name), _id(id) {};

		string get_name();
		string get_id();

	private:

		string _name;
		string _id;

};
#endif
