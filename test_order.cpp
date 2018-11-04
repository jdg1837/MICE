#include <iostream>
#include "container.h"
#include "topping.h"
#include "scoop.h"
#include "serving.h"
#include "server.h"
#include "order.h"
#include "state.h"

int main() {      
   int i;	
   std::string x_name = "Waffle Cone";
   std::string x_description = "A dry, cone-shaped pastry with a waffle texture";
   double x_cost = 0.30;
   double x_price = 0.99;
   int x_max_scoops = 3;

   Container container{x_name, x_description, x_cost, x_price, x_max_scoops};

   Serving serving{container};

   serving.push_scoop(Scoop("Chocolate", "Chocolatey Goodness", 3.00, 3.50));
   serving.push_scoop(Scoop("Vanilla", "Vanillaaaaa", 2.00, 2.50));

   serving.push_topping(Topping("Candy Sprinkles", "sprinkle sprinkle", 0.01, 0.20, 1));
   serving.push_topping(Topping("Brownie Bites", "brown", 0.02, 0.40, 1));


   Serving serving2{container};

   serving2.push_scoop(Scoop("Chocolate", "Chocolatey Goodness", 3.00, 3.50));
   serving2.push_scoop(Scoop("Vanilla", "Vanillaaaaa", 2.00, 2.50));

   serving2.push_topping(Topping("Candy Sprinkles", "sprinkle sprinkle", 0.01, 0.20, 1));
   serving2.push_topping(Topping("Brownie Bites", "brown", 0.02, 0.40, 1));
   
   Order order1{1, Customer("Whatever", "232", "9191919332"), Server("Chelsea", "1234", 1000.00), State{0}};

   order1.push_serving(serving);
   order1.push_serving(serving2);
   if(order1.price() - 15.18 > 0.0000001)
   {
        cerr << "price is incorrect" << endl;
   }
   
   if(order1.get_state() != "unfilled")
   {
        cerr << "should be unfiled" << endl;
   }
 
   Server bestserver("Jonathan", "1234", 1.00000); 
   order1.fill(bestserver);
   if(order1.get_state() != "filled")
   {
        cerr << "should be filled" << endl;
   }
   if(bestserver.get_name() != "Jonathan")
   {
        cerr << "chelsea is not the best server" << endl;   
   } 
   order1.pay();
   if(order1.get_state() != "paid")
   {
        cerr << "should be paid" << endl;
   }
   order1.cancel();

   if(order1.get_state() != "canceled")
   {
        cerr << "should be canceled" << endl;
   }
   if(order1.get_id() != 1)
   {
        cerr << "wrong order id" << endl;
   } 

}
