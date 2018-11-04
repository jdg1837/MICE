#ifndef __ORDER_H
#define __ORDER_H
#include "serving.h"
#include "server.h"
#include "customer.h"
#include "state.h"

#include <vector>
#include <string>

using namespace std;

class Order {
        
   public:
      Order(int idorder, Customer customer1, State state1) : id{idorder}, customer{customer1}, state{state1} {};
      double price();
      void assign_customer_index(int);
      void assign_state_index(int);
      int get_customer_index();
      void fill(Server server);
      void pay();
      void cancel();
      int get_state_index();
      int get_id();
   
      void push_serving(Serving serving);

      string get_state();

      vector<Serving> get_servings();


   private:
      int id;
      vector<Serving> servings;
      Server server{"TBD","TBD", 0};
      Customer customer;
      int customer_index = -1;
      State state;
      int state_index = 0;

};
#endif
