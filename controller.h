#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <iostream>
#include <regex>
#include <gtkmm.h>
#include <math.h>
#include "emporium.h"
#include "server.h"
#include "serving.h"
#include "customer.h"
#include "container.h"
#include "item.h"
#include "person.h"
#include "state.h"
#include "manager.h"
#include "dialogs.h"
#include "order.h"

using namespace std;

class Controller
{
   public:
	Controller(Emporium& _emporium): emporium(_emporium) {}
    
	void add_item(int item);
	void add_server();
	void suspend_server();
	void restore_server();
	void add_customer();
	void add_manager();
	void create_new_order();
	void open_file(int);
	int confirm_order(Order& order);
	void print_order(Order& order);
	void print_server_report(); 
	void print_customer_report(); 
	void print_inventory_report(); 
	void print_profit_report();
	void print_order_report(int option);  
	void fill_order();
	void pay_for_order();
	void test_data();
	void add_photos();
	void change_photos();
	void test_photos();
	void print_menu();
	void edit_item();
	void edit_salary();
	void manage_stock(int);
    void retire_item();

   private:
	Emporium& emporium;
};

	ostream& operator<<(ostream& os, const Serving& serving);

#endif

