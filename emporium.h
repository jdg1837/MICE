#ifndef __STOREFRONT_H
#define __STOREFRONT_H
#include "scoop.h"
#include "container.h"
#include "topping.h"
//#include "item.h"
#include "server.h"
#include "manager.h"
#include "customer.h"
//#include "dialogs.h"
#include "order.h"
#include "serving.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <gtkmm.h>

using namespace std;

class Emporium{
   public:
      void add_Container(Container container);
      void add_Scoop(Scoop scoop);
      void add_Topping(Topping top);
      void add_Server(Server server);
      void suspend_Server(int);
      void restore_Server(int);
      void add_Customer(Customer customer);
      void add_Order(Order order);
      void add_Manager(Manager manager);
      double get_register();
      void pay_server_fill(int server_choice);
      void pay_order(int order_index);
      void fill_order(int order_index, int server_index);
      void save(string filename);
      void load(string filename);
      void test_data();
      void print_menu();
      void add_photos();
      void change_photos();
      void test_photos();
      void edit_item();
      void edit_salary();
      void manage_stock(int);
      void add_item(int, int);
      int check_item(int, int);
      vector<int> get_scoop_vector();
      void update_item(int, vector<int>);
      vector<double> get_values();
      void change_sstate(int scoop_index);
      void change_cstate(int container_index);
      void change_tstate(int topping_index);

      vector<Container> get_containers();
      vector<Scoop> get_scoops();
      vector<Topping> get_toppings();
      vector<Server> get_servers();
      vector<Server> get_suspended_servers();
      vector<Customer> get_customers();
      vector<Order> get_orders();

   private:

      vector<Customer> customers;
      vector<Server> servers;
      vector<Server> suspended_servers;
      vector<Manager> managers;
      vector<Container> containers;
      vector<Scoop> scoops;
      vector<Topping> toppings;
      vector<Order> orders;

      vector<int> s_stock;
      vector<int> c_stock;
      
      double cash_register = 0;
      double loss = 0;
      double profit = 0;
};
#endif 
