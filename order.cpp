#include "order.h"

double Order::price(){
   double total;
   for(int i = 0; i < servings.size(); i++){
       total += servings[i].price();
   }
	
   return total;
}

void Order::fill(Server server1){
    state.change_state(1);
    server = server1;
    server.increase_orders();
    state_index = 1;
}


void Order::assign_customer_index(int cus_index){
    customer_index = cus_index;
}

void Order::assign_state_index(int index){
    state_index = index;
}

int Order::get_customer_index(){
    return customer_index;
}

int Order::get_state_index(){
    return state_index;
}

void Order::pay(){
    state.change_state(2);
    state_index = 2;
}

void Order::cancel(){
    state.change_state(3);
    state_index = 3;
}

int Order::get_id(){
    return id;
}

void Order::push_serving(Serving serving){
	servings.push_back(serving);
}

string Order::get_state(){
    return state.to_string();
}

vector<Serving> Order::get_servings(){
	return servings;
}
