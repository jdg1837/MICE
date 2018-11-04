#ifndef __MANAGER_H
#define __MANAGER_H

#include <iostream>
#include <string>
#include <cstdlib>
#include <exception>

#include "person.h"

using namespace std;

class Manager: public Person{
    public:
        Manager(string name, string id, double wage) : Person(name, id), _wage{wage} {};;
        double get_wage();

    private:
        double _wage;
};
#endif
