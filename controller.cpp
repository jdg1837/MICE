#include <iostream>

#include "controller.h"

void Controller::add_item(int item)
{
	string name = " ";
	string description = " ";
	int scoops = 0;
	double cost = 0.0;
	double price = 0.0;
	int stock = 0;

 while(true)
 {
	bool cancel = false;

	Gtk::Dialog *dialog = new Gtk::Dialog();

	if(item == 0) dialog->set_title("Add a new Flavor");
	else if(item == 1) dialog->set_title("Add a new Container");
	else if(item == 2) dialog->set_title("Add a new Topping");

	// Name
	string item_name;
        if(item == 0) item_name =  "Enter flavor name: "; 
        else if(item == 1) item_name = "Enter container name: "; 
        else if(item == 2) item_name =  "Enter topping name: "; 

	Gtk::HBox b_name;

	Gtk::Label l_name{item_name};
	l_name.set_width_chars(25);
	b_name.pack_start(l_name, Gtk::PACK_SHRINK);

	Gtk::Entry e_name;
	e_name.set_max_length(50);
	b_name.pack_start(e_name, Gtk::PACK_SHRINK);
	dialog->get_vbox()->pack_start(b_name, Gtk::PACK_SHRINK);

	// Description
	Gtk::HBox b_desc;

	Gtk::Label l_desc{"Description:"};
	l_desc.set_width_chars(25);
	b_desc.pack_start(l_desc, Gtk::PACK_SHRINK);

	Gtk::Entry e_desc;
	e_desc.set_max_length(50);
	b_desc.pack_start(e_desc, Gtk::PACK_SHRINK);
	dialog->get_vbox()->pack_start(b_desc, Gtk::PACK_SHRINK);

	
	// Scoops
	Gtk::HBox b_scoops;	
	Gtk::Entry e_scoops;
	Gtk::Label l_scoops{"Maximum number of scoops:"};
	if(item == 1)
	{
	
	l_scoops.set_width_chars(25);
	b_scoops.pack_start(l_scoops, Gtk::PACK_SHRINK);

	e_scoops.set_max_length(50);
	b_scoops.pack_start(e_scoops, Gtk::PACK_SHRINK);
	dialog->get_vbox()->pack_start(b_scoops, Gtk::PACK_SHRINK);
    
	}

	// Cost
	Gtk::HBox b_cost;

	Gtk::Label l_cost{"Enter wholesale cost:"};
	l_cost.set_width_chars(25);
	b_cost.pack_start(l_cost, Gtk::PACK_SHRINK);

	Gtk::Entry e_cost;
	e_cost.set_max_length(50);
	b_cost.pack_start(e_cost, Gtk::PACK_SHRINK);
	dialog->get_vbox()->pack_start(b_cost, Gtk::PACK_SHRINK);

	// Price
	Gtk::HBox b_price;

	Gtk::Label l_price{"Enter retail price:"};
	l_price.set_width_chars(25);
	b_price.pack_start(l_price, Gtk::PACK_SHRINK);

	Gtk::Entry e_price;
	e_price.set_max_length(50);
	b_price.pack_start(e_price, Gtk::PACK_SHRINK);
	dialog->get_vbox()->pack_start(b_price, Gtk::PACK_SHRINK);

	// Show dialog
	dialog->add_button("Cancel", 0);
	dialog->add_button("OK", 1);
	dialog->show_all();
	int result = dialog->run();

	dialog->close();
	while (Gtk::Main::events_pending())  Gtk::Main::iteration();

	if(result == 0) return;

	name = e_name.get_text();
	description = e_desc.get_text();
	try
	{
		if(item == 1) 
		scoops = stof(e_scoops.get_text().c_str());
		cost = stof(e_cost.get_text().c_str());
		price = stof(e_price.get_text().c_str());
	}
	catch(exception e)
	{
		Glib::ustring s = "Error.";
		if(item == 1) s += " The input for scoops must be a fully numerical value.";
		s += " The input for cost and price must be numerical, but can be decimal in nature. Use a period (.) to separate the non-decimal part from the decimal part (ex, 7.35). Values asumed in USD. Do not use \"$\"";
//		Gtk::MessageDialog dlg(*this, s, true, Gtk::MESSAGE_INFO, Gtk::BUTTONS_OK, true);dlg.run();
		cout << s << endl;
		continue;
	}


	if (result == 1)
	{
		if(item == 0)
		{
	                Scoop scoop{name, description, cost, price, 4};
                        emporium.add_Scoop(scoop);
		}

		if(item == 1)
		{
                        Container container{name, description, cost, price, 4, scoops};
                        emporium.add_Container(container);
		}

		if(item == 2)
		{
                        Topping topping{name, description, cost, price, 4, 1};
                        emporium.add_Topping(topping);
		}
	}
	break;
 }
 return;
}

void Controller::add_server()
{
	string name = " ";
	string id = " ";
	double wage = 0.0;

 while(true)
 {
	bool cancel = false;

	Gtk::Dialog *dialog = new Gtk::Dialog();

	dialog->set_title("Hire a Server");

	// Name
	Gtk::HBox b_name;

	Gtk::Label l_name{"Name:"};
	l_name.set_width_chars(25);
	b_name.pack_start(l_name, Gtk::PACK_SHRINK);

	Gtk::Entry e_name;
	e_name.set_max_length(50);
	b_name.pack_start(e_name, Gtk::PACK_SHRINK);
	dialog->get_vbox()->pack_start(b_name, Gtk::PACK_SHRINK);

	// ID
	Gtk::HBox b_id;

	Gtk::Label l_id{"Server id:"};
	l_id.set_width_chars(25);
	b_id.pack_start(l_id, Gtk::PACK_SHRINK);

	Gtk::Entry e_id;
	e_id.set_max_length(50);
	b_id.pack_start(e_id, Gtk::PACK_SHRINK);
	dialog->get_vbox()->pack_start(b_id, Gtk::PACK_SHRINK);

	// Wage
	Gtk::HBox b_wage;

	Gtk::Label l_wage{"Wage:"};
	l_wage.set_width_chars(25);
	b_wage.pack_start(l_wage, Gtk::PACK_SHRINK);

	Gtk::Entry e_wage;
	e_wage.set_max_length(50);
	b_wage.pack_start(e_wage, Gtk::PACK_SHRINK);
	dialog->get_vbox()->pack_start(b_wage, Gtk::PACK_SHRINK);

	// Show dialog
	dialog->add_button("Cancel", 0);
	dialog->add_button("OK", 1);
	dialog->show_all();
	int result = dialog->run();

	dialog->close();
	while (Gtk::Main::events_pending())  Gtk::Main::iteration();

	if(result == 0) return;

	name = e_name.get_text();
	id = e_id.get_text();
	try
	{
		wage = stof(e_wage.get_text().c_str());
	}
	catch(exception e)
	{
		Glib::ustring s = "Error. The input for cost and price must be numerical, but can be decimal in nature. Use a period (.) to separate the non-decimal part from the decimal part (ex, 7.35). Values asumed in USD. Do not use \"$\"";
//		Gtk::MessageDialog dlg(*this, s, true, Gtk::MESSAGE_INFO, Gtk::BUTTONS_OK, true);dlg.run();
		cout << s << endl;
		continue;
	}

	Server server{name, id, wage};
	emporium.add_Server(server);
        return;

	break;
 }
}

void Controller::suspend_server()
{
	vector<Server> servers = emporium.get_servers();

	Gtk::Dialog *dialog = new Gtk::Dialog();
	dialog->set_title("Suspend a Server");

	Gtk::ComboBoxText server_index;
	server_index.set_size_request(160);

	for(int i = 0; i < servers.size(); i++){
		server_index.append(servers[i].get_name());
	}

	dialog->get_vbox()->pack_start(server_index, Gtk::PACK_SHRINK);
	dialog->add_button("Cancel", 0);
	dialog->add_button("Ok", 1);
	dialog->show_all();

	int selection = dialog->run();
	int choice = server_index.get_active_row_number();

	dialog->close();     
	while (Gtk::Main::events_pending())  Gtk::Main::iteration();

	if((selection == 0) || (choice == -1)) return;
	
	emporium.suspend_Server(choice);
}

void Controller::restore_server()
{
	vector<Server> suspended = emporium.get_suspended_servers();

	Gtk::Dialog *dialog = new Gtk::Dialog();
	dialog->set_title("Restore a Server");

	Gtk::ComboBoxText server_index;
	server_index.set_size_request(160);

	for(int i = 0; i < suspended.size(); i++){
		server_index.append(suspended[i].get_name());
	}

	dialog->get_vbox()->pack_start(server_index, Gtk::PACK_SHRINK);
	dialog->add_button("Cancel", 0);
	dialog->add_button("Ok", 1);
	dialog->show_all();

	int selection = dialog->run();
	int choice = server_index.get_active_row_number();

	dialog->close();     
	while (Gtk::Main::events_pending())  Gtk::Main::iteration();

	if((selection == 0) || (choice == -1)) return;
	
	emporium.restore_Server(choice);
}

void Controller::add_customer()
{
	string name = " ";
	string id = " ";
	string phone = " ";

 while(true)
 {
	bool cancel = false;

	Gtk::Dialog *dialog = new Gtk::Dialog();

	dialog->set_title("Welcome a beloved customer");

	// Name
	Gtk::HBox b_name;

	Gtk::Label l_name{"Name:"};
	l_name.set_width_chars(25);
	b_name.pack_start(l_name, Gtk::PACK_SHRINK);

	Gtk::Entry e_name;
	e_name.set_max_length(50);
	b_name.pack_start(e_name, Gtk::PACK_SHRINK);
	dialog->get_vbox()->pack_start(b_name, Gtk::PACK_SHRINK);

	// ID
	Gtk::HBox b_id;

	Gtk::Label l_id{"Customer id:"};
	l_id.set_width_chars(25);
	b_id.pack_start(l_id, Gtk::PACK_SHRINK);

	Gtk::Entry e_id;
	e_id.set_max_length(50);
	b_id.pack_start(e_id, Gtk::PACK_SHRINK);
	dialog->get_vbox()->pack_start(b_id, Gtk::PACK_SHRINK);

	// Phone
	Gtk::HBox b_phone;

	Gtk::Label l_phone{"Phone:"};
	l_phone.set_width_chars(25);
	b_phone.pack_start(l_phone, Gtk::PACK_SHRINK);

	Gtk::Entry e_phone;
	e_phone.set_max_length(50);
	b_phone.pack_start(e_phone, Gtk::PACK_SHRINK);
	dialog->get_vbox()->pack_start(b_phone, Gtk::PACK_SHRINK);

	// Show dialog
	dialog->add_button("Cancel", 0);
	dialog->add_button("OK", 1);
	dialog->show_all();
	int result = dialog->run();

	dialog->close();
	while (Gtk::Main::events_pending())  Gtk::Main::iteration();

	if(result == 0) return;

	name = e_name.get_text();
	id = e_id.get_text();
	phone = e_phone.get_text();

	Customer customer{name, id, phone};
	emporium.add_Customer(customer);
        return;

	break;
 }
}

void Controller::add_manager(){
    string name = " ";
	string id = " ";
    double wage = 0.0;
	//string phone = " ";

 while(true)
 {
	bool cancel = false;

	Gtk::Dialog *dialog = new Gtk::Dialog();

	dialog->set_title("Hire a manager");

	// Name
	Gtk::HBox b_name;

	Gtk::Label l_name{"Name:"};
	l_name.set_width_chars(25);
	b_name.pack_start(l_name, Gtk::PACK_SHRINK);

	Gtk::Entry e_name;
	e_name.set_max_length(50);
	b_name.pack_start(e_name, Gtk::PACK_SHRINK);
	dialog->get_vbox()->pack_start(b_name, Gtk::PACK_SHRINK);

	// ID
	Gtk::HBox b_id;

	Gtk::Label l_id{"Manager id:"};
	l_id.set_width_chars(25);
	b_id.pack_start(l_id, Gtk::PACK_SHRINK);

	Gtk::Entry e_id;
	e_id.set_max_length(50);
	b_id.pack_start(e_id, Gtk::PACK_SHRINK);
	dialog->get_vbox()->pack_start(b_id, Gtk::PACK_SHRINK);

	// Wage
	Gtk::HBox b_wage;

	Gtk::Label l_wage{"Wage:"};
	l_wage.set_width_chars(25);
	b_wage.pack_start(l_wage, Gtk::PACK_SHRINK);

	Gtk::Entry e_wage;
	e_wage.set_max_length(50);
	b_wage.pack_start(e_wage, Gtk::PACK_SHRINK);
	dialog->get_vbox()->pack_start(b_wage, Gtk::PACK_SHRINK);

	// Show dialog
	dialog->add_button("Cancel", 0);
	dialog->add_button("OK", 1);
	dialog->show_all();
	int result = dialog->run();

	dialog->close();
	while (Gtk::Main::events_pending())  Gtk::Main::iteration();

	if(result == 0) return;

	name = e_name.get_text();
	id = e_id.get_text();
	//phone = e_phone.get_text();
    try{
		wage = stof(e_wage.get_text().c_str());
	}catch(exception e){
		Glib::ustring s = "Error. The input for cost and price must be numerical, but can be decimal in nature. Use a period (.) to separate the non-decimal part from the decimal part (ex, 7.35). Values asumed in USD. Do not use \"$\"";
//		Gtk::MessageDialog dlg(*this, s, true, Gtk::MESSAGE_INFO, Gtk::BUTTONS_OK, true);dlg.run();
		cout << s << endl;
		continue;
	}


	Manager manager{name, id, wage};
	emporium.add_Manager(manager);
        return;

	break;
 }


}

void Controller::create_new_order(){

   vector<Customer> customers = emporium.get_customers();
   vector<Server> servers = emporium.get_servers();
   vector<Order> orders = emporium.get_orders();
   if(customers.size() == 0 || servers.size() == 0)
   {
      Dialogs::message("No registered servers or customers in database.", "Create Order");
	  return;
   }
   
   Gtk::Dialog *cusdialog = new Gtk::Dialog();
   cusdialog->set_title("Customer");

   Gtk::HBox b_cus;
   string title = "Select your name";  
   Gtk::Label l_cus{title};
   l_cus.set_width_chars(15);
   b_cus.pack_start(l_cus, Gtk::PACK_SHRINK);
   
   Gtk::ComboBoxText c_cus;
   c_cus.set_size_request(160);
   
   for(int i = 0; i < customers.size(); i++){
   		c_cus.append(customers[i].get_name());
   }
   
   b_cus.pack_start(c_cus, Gtk::PACK_SHRINK);	
   cusdialog->get_vbox()->pack_start(b_cus, Gtk::PACK_SHRINK);
   cusdialog->add_button("Cancel", 0);
   cusdialog->add_button("Ok", 1);
   cusdialog->show_all();
       
   int cus_selection = cusdialog->run();
   int cus_choice = c_cus.get_active_row_number();

   cusdialog->close();     
   while (Gtk::Main::events_pending())  Gtk::Main::iteration();

   if((cus_selection == 0) || (cus_choice == -1)) return;
   

   State state{0};
   int id = orders.size()+1;
   Order order{id, customers[cus_choice], state};

   order.assign_customer_index(cus_choice);
   vector<Scoop> scoops = emporium.get_scoops();
   vector<Container> containers = emporium.get_containers();
   vector<Topping> toppings = emporium.get_toppings();

   int container_index;
   vector<int> s_req = emporium.get_scoop_vector();
   for(int i = 0; i < s_req.size(); i++) s_req[i] = 0;
   vector<int> t_req;
   for(int i = 0; i < toppings.size(); i++)
   {
       t_req.push_back(0);
   }

while(true)
{   
   Gtk::Dialog *dialog = new Gtk::Dialog();
   dialog->set_title("Container");

   Gtk::HBox b_container;
  
   Gtk::Label l_container{"Pick a Container:"};
   l_container.set_width_chars(15);
   b_container.pack_start(l_container, Gtk::PACK_SHRINK);


   Gtk::ComboBoxText c_container;
   c_container.set_size_request(160);
   for(int i = 0; i < containers.size(); i++){
       if(containers[i].get_state() != "retired"){
         c_container.append(containers[i].name());
       }
   }
   
   b_container.pack_start(c_container, Gtk::PACK_SHRINK);	
   dialog->get_vbox()->pack_start(b_container, Gtk::PACK_SHRINK);
   

   dialog->add_button("Cancel", 0);
   dialog->add_button("Ok", 1);
   dialog->show_all();

   int result;
   int container_choice;
while(true)
{
   result = dialog->run();
   if(result == 0)
	{dialog->close(); return;}
   container_choice = c_container.get_active_row_number();
   if(container_choice == -1) continue;
   else break;
}

   dialog->close();
   while (Gtk::Main::events_pending())  Gtk::Main::iteration();

   int c_req = emporium.check_item(0, container_choice);
   if((c_req)+1 > containers[container_choice].quantity())
   {Dialogs::message("Container out of stock!", "Sorry"); continue;}
   emporium.add_item(0, container_choice);

   container_index = container_choice;

//	if(result == 0) return;

   Serving serving{containers[container_choice]};

    for(int i = 0; i < 3; ++i){

       Gtk::Dialog *dialog2 = new Gtk::Dialog();
       dialog2->set_title("New Order");

       Gtk::HBox b_topping;
       string title = "Pick Topping " + to_string(i+1);  
       Gtk::Label l_topping{title};
       l_topping.set_width_chars(15);
       b_topping.pack_start(l_topping, Gtk::PACK_SHRINK);
   
       Gtk::ComboBoxText c_topping;
       c_topping.set_size_request(160);
 //      c_topping.append("No topping");
       for(int i = 0; i < toppings.size(); i++){
          if(toppings[i].get_state() != "retired"){
            c_topping.append(toppings[i].name());
          }
       }
    
       b_topping.pack_start(c_topping, Gtk::PACK_SHRINK);	
       dialog2->get_vbox()->pack_start(b_topping, Gtk::PACK_SHRINK);
   
       Gtk::HBox b_amount;

       Gtk::Label l_amount{"Pick amount:"};
       l_amount.set_width_chars(15);
       b_amount.pack_start(l_amount, Gtk::PACK_SHRINK);

       Gtk::ComboBoxText c_amount;
       c_amount.set_size_request(160);

       c_amount.append("Lite");
       c_amount.append("Normal");
       c_amount.append("Extra");
       c_amount.append("Drenched");

       b_amount.pack_start(c_amount, Gtk::PACK_SHRINK);
       dialog2->get_vbox()->pack_start(b_amount, Gtk::PACK_SHRINK);

       dialog2->add_button("Cancel", 0);
       dialog2->add_button("No Topping", 1);
       dialog2->add_button("Ok", 2);
       dialog2->show_all();

       bool already_selected = false;

	while(true)
	{
		int result2 = dialog2->run();
		if(result2 == 0) {dialog2->close(); return;}
		else if(result2 == 1) break;

		int get_topping = c_topping.get_active_row_number();
		if(get_topping == -1) break;

		int get_amount = c_amount.get_active_row_number();
		if(get_amount == -1) get_amount = 0;

		if(t_req[get_topping] != 0)
		{
			Dialogs::message("You have already chosen that topping!", "Error");
			already_selected = true;
			break;
		}
        	else
			t_req[get_topping] = get_amount + 1;

		Topping topping = toppings[get_topping];
		topping._set_amount(get_amount+1);
		serving.push_topping(topping);

		break;
	}

       dialog2->close();
       while (Gtk::Main::events_pending())  Gtk::Main::iteration();

       if(already_selected)
       {
	i--;
	continue;
       }
    }


    Gtk::Dialog *dialog3 = new Gtk::Dialog();
 
    dialog3->set_title("Scoops");

    Gtk::HBox b_scoops;

    Gtk::Label l_scoops{"How many scoops?"};
    l_scoops.set_width_chars(15);
    b_scoops.pack_start(l_scoops, Gtk::PACK_SHRINK);

    //int j = c_container.get_active_row_number();
    int max_scoops = containers[container_choice].max_scoops();

    //Serving serving(containers[container_choice]);

    Gtk::ComboBoxText c_scoops;
    c_scoops.set_size_request(160);

    for(int k = 1; k <= max_scoops; k++){
	    c_scoops.append(to_string(k));
    }

    b_scoops.pack_start(c_scoops, Gtk::PACK_SHRINK);	
    dialog3->get_vbox()->pack_start(b_scoops, Gtk::PACK_SHRINK);


    dialog3->add_button("Cancel", 0);
    dialog3->add_button("Ok", 1);
    dialog3->show_all();

/*    int result3 = dialog3->run();
//	if(result3 == 0) return;
    int num_scoops = c_scoops.get_active_row_number();

    dialog3->close();
    while (Gtk::Main::events_pending())  Gtk::Main::iteration();*/



//    if(result3 == 0) return;

   int result3;
   int num_scoops;
while(true)
{
   result3 = dialog3->run();
   if(result3 == 0)
	{dialog3->close(); return;}
   num_scoops = c_scoops.get_active_row_number();
   if(num_scoops == -1) continue;
   else break;
}

    dialog3->close();
    while (Gtk::Main::events_pending())  Gtk::Main::iteration();

    for(int k = 0; k < num_scoops+1; k++){
        Gtk::Dialog *dialog4 = new Gtk::Dialog();

        dialog4->set_title("Choose flavor:");

        Gtk::HBox b_flavor;

        Gtk::ComboBoxText c_flavor;
        c_flavor.set_size_request(160);

        for(int z = 0; z < scoops.size(); z++){
            if(scoops[z].get_state() != "retired"){        	
              c_flavor.append(scoops[z].name());
            }
        }

        b_flavor.pack_start(c_flavor, Gtk::PACK_SHRINK);	
        dialog4->get_vbox()->pack_start(b_flavor, Gtk::PACK_SHRINK);

        dialog4->add_button("Cancel", 0);
        dialog4->add_button("Ok", 1);
        dialog4->show_all();

/*        int result4 = dialog4->run();
        int scoop_index = c_flavor.get_active_row_number();

        dialog4->close();
        while (Gtk::Main::events_pending())  Gtk::Main::iteration();*/


//        if(result4 == 0) return;

   int result4;
   int scoop_index;
while(true)
{
   result4 = dialog4->run();
   if(result4 == 0)
	{dialog4->close(); return;}
   scoop_index = c_flavor.get_active_row_number();
   int s_req2 = emporium.check_item(1, scoop_index);
   if((s_req2)+1 > scoops[scoop_index].quantity())
   {Dialogs::message("Scoop out of stock!", "Sorry"); continue;}
   emporium.add_item(1, scoop_index);
   (s_req[scoop_index])++;
   break;
}
        dialog4->close();
        while (Gtk::Main::events_pending())  Gtk::Main::iteration();

        serving.push_scoop(scoops[scoop_index]);

    }
	serving.requests(container_index, s_req, t_req);
	order.push_serving(serving);

	int another = Dialogs::question("Add another serving to the order?", "Continue?", {"No", "Yes"});
	if(another == 0) break;
}	
	int confirmation = confirm_order(order);

	if(confirmation == 0) 
	{
		Dialogs::message("Order canceled", "Confirmation");
	}
	else 
	{
		Dialogs::message("Order confirmed!", "Confirmation");
		print_order(order);
		emporium.add_Order(order);
	}
}

void Controller::open_file(int option){
    
    string filename;
    regex extension{".*\\.txt$"};					//REGEX!

    while (true)
    {
	    string message;
	    if(option == 0) message = "Enter file to save to:";
	    if(option == 1) message = "Enter file to load from";

	    filename = Dialogs::input(message, "File opening");
	    if(filename == "CANCEL") return;
	    if(!regex_match(filename,extension))
	    {
		Dialogs::message("Program only accepts .txt files", "Error");
		continue;
	    }
	    
	    break;
     }

     if (option == 0) emporium.save(filename);
     if (option == 1) emporium.load(filename);
}


void Controller::pay_for_order()
{
	   vector<Order> orders = emporium.get_orders();
    
	   if(orders.size() == 0)
       {
           Dialogs::message("No orders available", "Pay for Order");
           return;
       }

       while (Gtk::Main::events_pending())  Gtk::Main::iteration();   

	   Gtk::Dialog *orderdialog = new Gtk::Dialog();
       orderdialog->set_title("Pay for Order");

       Gtk::HBox b_order;
       string title2 = "Select order";  
       Gtk::Label l_order{title2};
       l_order.set_width_chars(15);
       b_order.pack_start(l_order, Gtk::PACK_SHRINK);
   
       Gtk::ComboBoxText c_order;
       c_order.set_size_request(160);

       vector<int> indexes;
       for(int i = 0; i < orders.size(); i++){
       		if((orders[i].get_state_index() == 2) || (orders[i].get_state_index() == 3))
			continue;
		indexes.push_back(i);
       		c_order.append(to_string(orders[i].get_id()));
       }

       b_order.pack_start(c_order, Gtk::PACK_SHRINK);	
       orderdialog->get_vbox()->pack_start(b_order, Gtk::PACK_SHRINK);
	   orderdialog->add_button("Cancel", 0);
       orderdialog->add_button("Ok", 1);
       orderdialog->show_all();
       
	   int order_selection = orderdialog->run();
       int order_choice;
	    
       if(order_selection == 1)
	   {
            order_choice = c_order.get_active_row_number();

			if(orders[indexes[order_choice]].get_state() != "filled")
            {
                 Dialogs::message("This order has not been filled yet!", "Pay for Order");
                 orderdialog->close();
                 return;
            }
            
			emporium.pay_order(indexes[order_choice]);
			orderdialog->close();
			
       }
       else
       {
			orderdialog->close();
            return;
       } 
}

void Controller::fill_order()
{
	   vector<Server> servers = emporium.get_servers();
       vector<Order> orders = emporium.get_orders();

       if(orders.size() == 0 || servers.size() == 0)
	   {
           Dialogs::message("No orders or servers available", "Fill Order");
           return;
       }

	   while (Gtk::Main::events_pending())  Gtk::Main::iteration();
	   Gtk::Dialog *serverdialog = new Gtk::Dialog();
       serverdialog->set_title("Fill Order");

       Gtk::HBox b_server;
       string title = "Select your name";  
       Gtk::Label l_server{title};
       l_server.set_width_chars(15);
       b_server.pack_start(l_server, Gtk::PACK_SHRINK);
   
       Gtk::ComboBoxText c_server;
       c_server.set_size_request(160);
       for(int i = 0; i < servers.size(); i++){
       		c_server.append(servers[i].get_name());
       }

       b_server.pack_start(c_server, Gtk::PACK_SHRINK);	
       serverdialog->get_vbox()->pack_start(b_server, Gtk::PACK_SHRINK);
	   serverdialog->add_button("Cancel", 0);
       serverdialog->add_button("Ok", 1);
       serverdialog->show_all();
       
	   int server_selection = serverdialog->run();
	   int server_choice;
	   if(server_selection == 1)
       {
       		server_choice = c_server.get_active_row_number();
       }
       else
       {
	   		serverdialog->close();
			return;
       }

       serverdialog->close();  

	   while (Gtk::Main::events_pending())  Gtk::Main::iteration();   

	   Gtk::Dialog *orderdialog = new Gtk::Dialog();
       orderdialog->set_title("Fill Order");

       Gtk::HBox b_order;
       string title2 = "Select order";  
       Gtk::Label l_order{title2};
       l_order.set_width_chars(15);
       b_order.pack_start(l_order, Gtk::PACK_SHRINK);
   
       vector<int> indexes;
       Gtk::ComboBoxText c_order;
       c_order.set_size_request(160);
       for(int i = 0; i < orders.size(); i++){
		if(orders[i].get_state_index() != 0)
			continue;
		indexes.push_back(i);
       		c_order.append(to_string(orders[i].get_id()));
       }

       b_order.pack_start(c_order, Gtk::PACK_SHRINK);	
       orderdialog->get_vbox()->pack_start(b_order, Gtk::PACK_SHRINK);
	   orderdialog->add_button("Cancel", 0);
       orderdialog->add_button("Ok", 1);
       orderdialog->show_all();
       
	   int order_selection = orderdialog->run();
       int order_choice;
	    
       if(order_selection == 1)
	   {
            order_choice = c_order.get_active_row_number();
            emporium.fill_order(indexes[order_choice], server_choice);
            emporium.pay_server_fill(server_choice);
			orderdialog->close();
			
       }
       else
       {
			orderdialog->close();
       } 
}

int Controller::confirm_order(Order& order)
{
	vector<Serving> servings = order.get_servings();
	double price = order.price();
	string info = "";	

	for(int i = 0; i < servings.size(); i++)
	{
		ostringstream os;
		os << servings[i];
		info += os.str();
	}

	info += "\nTotal cost:                                     $";
	string price_text = to_string(price);
	info += price_text.substr(0, 4);

	int confirmation = Dialogs::question(info, "Confirm order");

	if(confirmation == 0){
        return 0;
	}else{
        return 1;
	}
    
}

ostream& operator<<(ostream& os, const Serving& serving)
{   
	os << serving.container() << ": " << serving.get_size_scoop() << " Scoops,  " << serving.get_size_topping() << " Toppings  " << "Price: $" <<  serving.price() << '\n';
	return os;
}        

void Controller::print_server_report(){
    vector<Server> servers = emporium.get_servers();
    vector<Server> suspended = emporium.get_suspended_servers();
    string all_servers = "";
    double wage;
    int total_orders;
    if((servers.size() != 0) || (suspended.size() != 0)){
        for(int i = 0; i < servers.size(); i++){
            all_servers += to_string(i+1);
            all_servers += ") ";
            all_servers += servers[i].get_name();
            all_servers += ", ";
            all_servers += servers[i].get_id();
            all_servers += ", ";
            wage = servers[i].get_wage();
            all_servers += "$";
            all_servers += to_string(wage);
            all_servers += " per hour, ";
            all_servers += "Total orders filled: ";
            total_orders = servers[i].get_orders();
            all_servers += to_string(total_orders);
            all_servers += '\n';       
        }
	    all_servers += "\nSuspended Servers:\n";
        for(int i = 0; i < suspended.size(); i++){
            all_servers += to_string(i+1);
            all_servers += ") ";
            all_servers += suspended[i].get_name();
            all_servers += ", ";
            all_servers += suspended[i].get_id();
            all_servers += ", ";
            wage = suspended[i].get_wage();
            all_servers += "$";
            all_servers += to_string(wage);
            all_servers += " per hour, ";
            all_servers += "Total orders filled: ";
            total_orders = suspended[i].get_orders();
            all_servers += to_string(total_orders);
            all_servers += '\n';       
        }

        Dialogs::message(all_servers, "Server Report");
    }else{
        Dialogs::message("There are currently no servers", "Server Report");
    }
}

void Controller::print_customer_report(){
    vector<Customer> customers = emporium.get_customers();
    string all_customers = "";  
    if(customers.size() != 0){  
        for(int i = 0; i < customers.size(); i++){
            all_customers += to_string(i+1);
            all_customers += ") ";
            all_customers += customers[i].get_name();
            all_customers += ", id: ";
            all_customers += customers[i].get_id();
            all_customers += ", phone: ";
            all_customers += customers[i].get_phone();
            all_customers += '\n';
        }
       Dialogs::message(all_customers, "Customer Report");
    }else{
        Dialogs::message("There are currently no customers", "Customer Report");
    }
}

void Controller::print_inventory_report(){
    vector<Container> containers = emporium.get_containers();
    vector<Scoop> scoops = emporium.get_scoops();
    vector<Topping> toppings = emporium.get_toppings();
    string inventory = "";

    inventory += "Containers:";
    inventory += '\n';

    for(int i = 0; i < containers.size(); i++){       
        inventory += containers[i].name();
        inventory += ", Stock: ";
        inventory += to_string(containers[i].quantity());
        inventory += " , Status: ";
        inventory += containers[i].get_state();
        inventory += '\n';
    }

    inventory += "Scoops:";
    inventory += '\n';

    for(int i = 0; i < scoops.size(); i++){
        inventory += scoops[i].name();
        inventory += ", Stock: ";
        inventory += to_string(scoops[i].quantity());
        inventory += " , Status: ";
        inventory += scoops[i].get_state();
        inventory += '\n';
    }
   
    Dialogs::message(inventory, "Inventory Report");
}

void Controller::print_profit_report()
{
	vector<double> values = emporium.get_values();
	string message = "";
	message += "Profit    : $" + to_string(values[0])+ '\n';
	message += "Loss      : $" + to_string(values[1])+ '\n';
	message += "Net Profit: $" + to_string(values[2])+ '\n';
	Dialogs::message(message, "Profit-Loss Report");
}

void Controller::print_order_report(int option)
{
	string report = "";
	vector<Order> orders = emporium.get_orders();
    if(option == 0){
        for(int i = 0; i < orders.size(); i++){
		    string state = orders[i].get_state();
            if(state == "unfilled"){
                report += to_string(i+1) + ")\npending\n";
            }else if(state == "filled"){
                report += to_string(i+1) + ")\nfilled\n";
	    }else
		continue;
        	
		    vector<Serving> servings = orders[i].get_servings();		
		    for(int j = 0; j < servings.size(); j++){
			    report += servings[j].to_string() + '\n';
            }
	    }
       Dialogs::message(report, "Order Report"); 
        
    }else{
	    for(int i = 0; i < orders.size(); i++){
            report += to_string(i+1) + ")\n";
		    string state = orders[i].get_state();
            if(state == "unfilled"){
                report += "pending\n";
            }else if(state == "filled"){
                report += "filled\n";
            }else if(state == "paid"){
                report += "filled and paid\n";
            }else{
                report += "canceled\n";
            }
        	
		    vector<Serving> servings = orders[i].get_servings();		
		    for(int j = 0; j < servings.size(); j++){
			    report += servings[j].to_string() + '\n';
            }
	    }
        Dialogs::message(report, "Order History");
    }
	
}

void Controller::test_data()
{                                    
	emporium.test_data();
}

void Controller::print_order(Order& order)
{
	vector<Serving> servings = order.get_servings();
	string info = "";	

	for(int i = 0; i < servings.size(); i++)
	{
		info += to_string(i+1);
		info += ")\n";
		info += servings[i].to_string();
		info += '\n';
	}
	Dialogs::message(info, "Order");
}



void Controller::add_photos()
{
	emporium.add_photos();
}

void Controller::change_photos()
{
	emporium.change_photos();
}

void Controller::test_photos()
{
	emporium.test_photos();
}

void Controller::print_menu()
{
	emporium.print_menu();
}

void Controller::edit_item()
{
	emporium.edit_item();
}

void Controller::edit_salary()
{
	emporium.edit_salary();
}

void Controller::manage_stock(int x)
{
	emporium.manage_stock(x);
}

void Controller::retire_item(){
    vector<Scoop> scoops = emporium.get_scoops();
    vector<Container> containers = emporium.get_containers();
    vector<Topping> toppings = emporium.get_toppings();
    Gtk::Dialog *dialog = new Gtk::Dialog();
	dialog->set_title("Choose the item type");

	Gtk::ComboBoxText c_type;
	c_type.set_size_request(160);
	c_type.append("Scoops");
	c_type.append("Containers");
    c_type.append("Toppings");
	
	dialog->get_vbox()->pack_start(c_type, Gtk::PACK_SHRINK);

	dialog->add_button("Cancel", 0);
	dialog->add_button("Ok", 1);
	dialog->show_all();

	int result = dialog->run();
	int item = c_type.get_active_row_number();


	dialog->close();
	while (Gtk::Main::events_pending())  Gtk::Main::iteration();

	if((result == 0) || (item == -1)) return;

    if(item == 0){
       Gtk::Dialog *scoops_dialog = new Gtk::Dialog();
	   scoops_dialog->set_title("Choose flavor: ");

	   Gtk::ComboBoxText c_flavor;
	   c_flavor.set_size_request(160);   
       for(int i = 0; i < scoops.size(); i++){
          c_flavor.append(scoops[i].name());
       }      

        scoops_dialog->get_vbox()->pack_start(c_flavor, Gtk::PACK_SHRINK);

		scoops_dialog->add_button("Cancel", 0);
		scoops_dialog->add_button("Ok", 1);
		scoops_dialog->show_all();

		int scoops_result = scoops_dialog->run();
		if(scoops_result == 0)
		{
			scoops_dialog->close();
			return;
		}

		int scoop_chosen = c_flavor.get_active_row_number();
        emporium.change_sstate(scoop_chosen);

        scoops_dialog->close();
		while (Gtk::Main::events_pending())  Gtk::Main::iteration();

		return;

    }else if(item == 1){
       Gtk::Dialog *containers_dialog = new Gtk::Dialog();
	   containers_dialog->set_title("Choose container: ");

	   Gtk::ComboBoxText c_container;
	   c_container.set_size_request(160);   
       for(int i = 0; i < containers.size(); i++){
          c_container.append(containers[i].name());
       }      

        containers_dialog->get_vbox()->pack_start(c_container, Gtk::PACK_SHRINK);

		containers_dialog->add_button("Cancel", 0);
		containers_dialog->add_button("Ok", 1);
		containers_dialog->show_all();

		int containers_result = containers_dialog->run();
		if(containers_result == 0)
		{
			containers_dialog->close();
			return;
		}

		int container_chosen = c_container.get_active_row_number();
        emporium.change_cstate(container_chosen);

        containers_dialog->close();
		while (Gtk::Main::events_pending())  Gtk::Main::iteration();

		return;

    }else if(item == 2){
       Gtk::Dialog *toppings_dialog = new Gtk::Dialog();
	   toppings_dialog->set_title("Choose topping: ");

	   Gtk::ComboBoxText c_topping;
	   c_topping.set_size_request(160);   
       for(int i = 0; i < toppings.size(); i++){
          c_topping.append(toppings[i].name());
       }      

        toppings_dialog->get_vbox()->pack_start(c_topping, Gtk::PACK_SHRINK);

		toppings_dialog->add_button("Cancel", 0);
		toppings_dialog->add_button("Ok", 1);
		toppings_dialog->show_all();

		int toppings_result = toppings_dialog->run();
		if(toppings_result == 0)
		{
			toppings_dialog->close();
			return;
		}

		int topping_chosen = c_topping.get_active_row_number();
        emporium.change_tstate(topping_chosen);

        toppings_dialog->close();
		while (Gtk::Main::events_pending())  Gtk::Main::iteration();

		return;
    }
}

