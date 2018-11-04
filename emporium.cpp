#include "emporium.h"

void Emporium::add_Container(Container container){
   containers.push_back(container);
   c_stock.push_back(0);
}   

void Emporium::add_Scoop(Scoop scoop){
   scoops.push_back(scoop);
   s_stock.push_back(0);
}

void Emporium::add_Topping(Topping top){
   toppings.push_back(top);
}

void Emporium::add_Server(Server server){
   servers.push_back(server);
}

void Emporium::suspend_Server(int index){
   vector<Server> buffer;
   for(int i = 0; i < servers.size(); i++)
   {
	if(i == index)
	{
		suspended_servers.push_back(servers[i]);	
		continue;
	}
	buffer.push_back(servers[i]);
   }
   servers = buffer;
}

void Emporium::restore_Server(int index){
   vector<Server> buffer;
   for(int i = 0; i < suspended_servers.size(); i++)
   {
	if(i == index)
	{
		servers.push_back(suspended_servers[i]);	
		continue;
	}
	buffer.push_back(suspended_servers[i]);
   }
   suspended_servers = buffer;
}

void Emporium::add_Customer(Customer customer){
   customers.push_back(customer);
}

void Emporium::add_Order(Order order){
   orders.push_back(order);
}

void Emporium::add_Manager(Manager manager){
   managers.push_back(manager);
}

vector<Container> Emporium::get_containers(){return containers;}

vector<Scoop> Emporium::get_scoops(){return scoops;}

vector<Topping> Emporium::get_toppings(){return toppings;}

vector<Server> Emporium::get_servers(){return servers;}

vector<Server> Emporium::get_suspended_servers(){return suspended_servers;}

vector<Customer> Emporium::get_customers(){return customers;}

vector<Order> Emporium::get_orders(){return orders;}

void Emporium::change_sstate(int scoop_index){
    scoops[scoop_index].change_state();
    Scoop tmp = scoops[scoop_index];
    scoops.erase(scoops.begin() + scoop_index);
    scoops.push_back(tmp);
}

void Emporium::change_cstate(int container_index){
    containers[container_index].change_state();
    Container tmp = containers[container_index];
    containers.erase(containers.begin() + container_index);
    containers.push_back(tmp);
}

void Emporium::change_tstate(int topping_index){
    toppings[topping_index].change_state();
    Topping tmp = toppings[topping_index];
    toppings.erase(toppings.begin() + topping_index);
    toppings.push_back(tmp);
}

vector<double> Emporium::get_values()
{
	vector<double> values;
	values.push_back(profit);
	values.push_back(loss);
	values.push_back(cash_register);
	return values;
}

void Emporium::save(string filename){
   
    ofstream emporiumFile;
    emporiumFile.open(filename);
    
    emporiumFile << "#servers" << endl;
    if(servers.size() > 0){   
        for(int i = 0; i < servers.size(); ++i){
            emporiumFile << servers[i].get_name() << "," << servers[i].get_id() << "," << servers[i].get_wage() << "," << to_string(servers[i].get_orders()) << ", 1" << endl;
        }
    }

    if(suspended_servers.size() > 0){   
        for(int i = 0; i < suspended_servers.size(); ++i){
            emporiumFile << suspended_servers[i].get_name() << "," << suspended_servers[i].get_id() << "," << suspended_servers[i].get_wage() << "," << to_string(suspended_servers[i].get_orders()) << ", 0" << endl;
        }
    }
    
    emporiumFile << "#end," << endl;
    
    emporiumFile << "#customers" << endl; 
    if(customers.size() > 0){   
        for(int i = 0; i < customers.size(); ++i){
            emporiumFile << customers[i].get_name() << "," << customers[i].get_id() << "," << customers[i].get_phone() << endl;
        }
    }
    
    emporiumFile << "#end," << endl;
     
    emporiumFile << "#containers" << endl;

    if(containers.size() > 0){   
        for(int i = 0; i < containers.size(); ++i){
            emporiumFile << containers[i].name() << "," << containers[i].description() << "," << containers[i].cost() << "," << containers[i].price() << "," << containers[i].max_scoops() << "," << containers[i].quantity() << "," << c_stock[i] << "," << containers[i].get_photo_name() << "," << containers[i].get_state_index() << endl;
        }
    }

    emporiumFile << "#end," << endl;

	emporiumFile << "#toppings" << endl;
    if(toppings.size() > 0){
        for(int i = 0; i < toppings.size(); ++i){
            emporiumFile << toppings[i].name() << "," << toppings[i].description() << "," << toppings[i].cost() << "," << toppings[i].price() << "," << toppings[i].get_photo_name() << "," << toppings[i].get_state_index() << endl;
        }
    }

    emporiumFile << "#end," << endl;
    
    emporiumFile << "#scoops" << endl;

	if(scoops.size() > 0){
      for(int i = 0; i < scoops.size(); ++i){
          emporiumFile << scoops[i].name() << "," << scoops[i].description() << "," << scoops[i].cost() << "," << scoops[i].price() << "," << scoops[i].quantity() << "," << s_stock[i] << "," << scoops[i].get_photo_name() << "," << scoops[i].get_state_index() << endl;
      }
    }

    emporiumFile << "#end," << endl;
   
    emporiumFile << "#managers" << endl;
	
	if(managers.size() > 0){
      for(int i = 0; i < managers.size(); ++i){
          emporiumFile << managers[i].get_name() << "," << managers[i].get_id() << "," << managers[i].get_wage() << endl;
      }
    }

    emporiumFile << "#end," << endl;

    emporiumFile << "#emporium" << endl;

    emporiumFile << cash_register << "," << profit << "," << loss << endl;

    emporiumFile << "#end," << endl;

    emporiumFile << "#orders" << endl;
    
    int i;
    for(i = 0; i < orders.size(); i++)
    {
         
         emporiumFile << "#neworder," << orders[i].get_customer_index() << "," << orders[i].get_state_index() << endl;
  
         for(int j = 0; j < orders[i].get_servings().size(); j++)
         {
              emporiumFile << orders[i].get_servings()[j].get_c_index() << ",";
              for(int k = 0; k < orders[i].get_servings()[j].get_s_req().size(); k++)
              {
                  emporiumFile << orders[i].get_servings()[j].get_s_req()[k] << ",";
              }
          
              for(int k = 0; k < orders[i].get_servings()[j].get_t_req().size(); k++)
              {
                  if(k == orders[i].get_servings()[j].get_t_req().size() - 1)
                  {
                       emporiumFile << orders[i].get_servings()[j].get_t_req()[k] << endl;
                       break;
                   }
                  emporiumFile << orders[i].get_servings()[j].get_t_req()[k] << ",";
              }
         }

       emporiumFile << "#endorder," << endl;
    }

    emporiumFile << "#end," << endl;
         
    emporiumFile.close(); 

}

void Emporium::load(string filename){

    string customer_index;
    string state;

	ifstream data(filename);
	int type = 0;
	while( !data.eof() )
	{	
		if(type == 0)
		{
			string stype;
			getline(data, stype);

			if(stype == "#containers")	type = 1;
			if(stype == "#scoops")		type = 2;
			if(stype == "#toppings")	type = 3;
			if(stype == "#customers")	type = 4;
			if(stype == "#servers")		type = 5;
			if(stype == "#managers")	type = 6;
			if(stype == "#emporium")	type = 7;
			if(stype == "#orders")		type = 8;
		}
		
		else if((type == 1) || (type == 2) || (type == 3))
		{
			while(true)
			{
			string name;
			string description;
			string cost;
			string price;
			string max_scoops;
			string stock;
			string request;
			string photo;
			string active;

			getline(data, name, ',');
			if(name == "#end")
			{
				type = 0;
				break;
			}

			getline(data, description, ',');
			getline(data, cost, ',');
			getline(data, price, ',');
		
			if (type == 1) 
			{			
			getline(data, max_scoops, ',');
			getline(data, stock, ',');
			getline(data, request, ',');
			getline(data, photo, ',');
			getline(data, active);
			
			Container container{name, description, stof(cost), stof(price), State(stoi(active)), stoi(max_scoops)};
			container.load_stock(stoi(stock));			
			container.load_photo(photo);
			container.set_state_index(active);
			containers.push_back(container);
			c_stock.push_back(stoi(request));
			}

			else if(type == 2)
			{
			getline(data, stock, ',');
			getline(data, request, ',');
			getline(data, photo, ',');
			getline(data, active);

			Scoop scoop{name, description, stof(cost), stof(price), State(stoi(active))};
			scoop.load_stock(stoi(stock));
			scoop.load_photo(photo);
			scoop.set_state_index(active);
			scoops.push_back(scoop);
			s_stock.push_back(stoi(request));			
			}

			else if(type == 3)
			{
			getline(data, photo, ',');
			getline(data, active);

			Topping topping{name, description, stof(cost), stof(price), State(stoi(active)),1};
			topping.load_photo(photo);
			topping.set_state_index(active);
			toppings.push_back(topping);		
			}

			break;
			}
		}
		else if((type == 4) || (type == 5) || (type == 6))
		{
			while(true)
			{
			string name;
			string id;
			string wage;
			string phone;
			string order_count;
			string is_active;

			getline(data, name, ',');
			if(name == "#end")
			{
				type = 0;
				break;
			}

			getline(data, id, ',');
			
			if(type == 4)
			{
			getline(data, phone);

			Customer customer(name, id, phone);
			customers.push_back(customer);
			}


			if(type == 5)
			{
			getline(data, wage, ',');
			getline(data, order_count, ',');
			getline(data, is_active);
			Server server(name, id, stof(wage));
			server.set_orders(stoi(order_count));
			int working = stoi(is_active);
			if(working == 0)
				suspended_servers.push_back(server);
			else
				servers.push_back(server);
			}

			if(type == 6)
			{
			getline(data, wage);
			Manager manager(name, id, stof(wage));
			managers.push_back(manager);
			}

			break;
			}
		}
		else if(type == 7)
		{
			while(true)
			{
			string in_register;
			string in_profit;
			string in_loss;

			getline(data, in_register, ',');
			if(in_register == "#end")
			{
				type = 0;
				break;
			}
			cash_register = stof(in_register);
			getline(data, in_profit, ',');
			profit = stof(in_profit);
			getline(data, in_loss);
			loss = stof(in_loss);	

			break;
			}
		}

		else if(type == 8)
		{
			while(true)
			{
			string function;
			getline(data, function, ',');
			if(function == "#end")
			{
				type = 0;
				break;
			}

			getline(data, customer_index, ',');
			getline(data, state);

			type = 9;
			break;
			}
		}
		
		else if(type == 9)
		{

			Order order(orders.size()+1, customers[stoi(customer_index)], State{stoi(state)});
			order.assign_customer_index(stoi(customer_index));
			order.assign_state_index(stoi(state));			

			while(true)
			{

			vector<int> scoops_requested;
			vector<int> toppings_requested;

			string container_index;
			string buffer;

			getline(data, container_index, ',');
			if(container_index == "#endorder")
			{
				orders.push_back(order);
				type = 8;
				customer_index = "";
				state = "";
				break;
			}

			Serving serving(containers[stoi(container_index)]);

			for(int i = 0; i < scoops.size(); i++)
			{
			getline(data, buffer, ',');
			int s_amount = stoi(buffer);
			scoops_requested.push_back(s_amount);
			for(int j = 0; j < s_amount; j++)
				serving.push_scoop(scoops[i]);
			}


			int i;
			for(i = 0; i < toppings.size()-1; i++)
			{
			getline(data, buffer, ',');
			int s_amount = stoi(buffer);
			toppings_requested.push_back(s_amount);
			if(s_amount == 0) continue;
			toppings[i]._set_amount(s_amount);
			serving.push_topping(toppings[i]);
			}

			getline(data, buffer);
			int s_amount = stoi(buffer);
			toppings_requested.push_back(s_amount);

			if(s_amount != 0)
			{			
			toppings[i]._set_amount(s_amount);
			serving.push_topping(toppings[i]);
			}

			serving.requests(stoi(container_index), scoops_requested, toppings_requested);

			order.push_serving(serving);
	
			}
		}
	}

	data.close();
}

void Emporium::add_item(int option, int pos)
{
	if(option == 0) (c_stock[pos]++);
	if(option == 1) (s_stock[pos]++);
}

int Emporium::check_item(int option, int pos)
{
	if(option == 0) return c_stock[pos];
	if(option == 1) return s_stock[pos];
}

void Emporium::update_item(int c_index, vector<int> consumed)
{
	(c_stock[c_index])--;
	for(int i = 0; i < consumed.size(); i++)
		s_stock[i] -= consumed[i];
}

vector<int> Emporium::get_scoop_vector(){return s_stock;}

void Emporium::test_data()
{                                                                                     
        containers.push_back(
        	Container{"Cone", "Crispy airy delight", 0.25, 0.50, 4, 2});
        containers.push_back(
        	Container{"Waffle Cone", "Crunchy wrapped waffle cake", 0.35, 0.75, 4, 3});
	c_stock.push_back(0);
	c_stock.push_back(0);
        scoops.push_back(
        	Scoop{"Chocolate", "Rich smooth chocolate ice cream", 0.20, 0.50, 4});
        scoops.push_back(
        	Scoop{"Vanilla", "Real vanilla bean ice cream", 0.20, 0.50, 4});
        scoops.push_back(
        	Scoop{"Strawberry", "Chunks of strawberry wrapped in vanilla ice cream", 0.20, 0.50, 4});
	s_stock.push_back(0);
	s_stock.push_back(0);
	s_stock.push_back(0);
        toppings.push_back(
        	Topping{"Cherry", "Classic marichino cherry", 0.1, 0.2, 4, 1});
        toppings.push_back(
        	Topping{"Chocolate Sauce", "Rich thick chocolate", 0.1, 0.25, 4, 1});
        toppings.push_back(
        	Topping{"Whipped Cream", "Real sweet cream whipped to perfection", 0.1, 0.2, 4, 1});
	servers.push_back(
		Server{"Chelsea", "27", 9.50});
	servers.push_back(
		Server{"Diego", "42", 9.50});
	servers.push_back(
		Server{"Jonathan", "99", 9.50});
	customers.push_back(
		Customer{"Brezeale", "1320", "(224)699-8778"});
	customers.push_back(
		Customer{"Rice", "1325", "(225)688-9559"});
	managers.push_back(
		Manager{"Turing", "1944", 25});
        // Display acknowledgement                                                                                                    
        Dialogs::message("Added 2 containers, 3 scoops, 3 toppings, 3 servers, 2 customers, and 1 manager", "Warning");
}

void Emporium::print_menu()
{
	bool all_have_photo = true;
	for(int i = 0; i < scoops.size(); i++) if(!scoops[i].check_photo()) all_have_photo = false;
	for(int i = 0; i < containers.size(); i++) if(!containers[i].check_photo()) all_have_photo = false;
	for(int i = 0; i < toppings.size(); i++) if(!toppings[i].check_photo()) all_have_photo = false;
	if(!all_have_photo)
	{
		Dialogs::message("Not all items have a photo", "Error");
		return;
	}

	Gtk::Dialog *dialog = new Gtk::Dialog();
	dialog->set_title("Menu");

	Gtk::Label l_delicious{"Our Delicious Menu:"};
	dialog->get_vbox()->pack_start(l_delicious, Gtk::PACK_SHRINK);

	Gtk::Label l_scoops{"Flavors:"};
	dialog->get_vbox()->pack_start(l_scoops, Gtk::PACK_SHRINK);

	vector<Gtk::Image*> s_files;
	vector<Gtk::Label*> s_names;

	Gtk::HBox s_photos;
	Gtk::HBox s_labels;

	for(int i = 0; i < scoops.size(); i++)
	{
		if(scoops[i].get_state_index() == 4)
		{
			s_files.push_back(scoops[i].get_photo());
			Gtk::Label *buffer = new Gtk::Label{scoops[i].name()};
			s_names.push_back(buffer);
		}
	}

	for(int i = 0; i < s_files.size(); i++)
	{
		s_photos.pack_start(*(s_files[i]), Gtk::PACK_SHRINK);
		Gtk::Label* l_buffer = s_names[i];
		l_buffer->set_width_chars(16);
		s_labels.pack_start(*(l_buffer), Gtk::PACK_SHRINK);
	}

	dialog->get_vbox()->pack_start(s_photos, Gtk::PACK_SHRINK);
	dialog->get_vbox()->pack_start(s_labels, Gtk::PACK_SHRINK);
	

	Gtk::Label l_containers{"Containers:"};
	dialog->get_vbox()->pack_start(l_containers, Gtk::PACK_SHRINK);
	
	vector<Gtk::Image*> c_files;
	vector<Gtk::Label*> c_names;

	Gtk::HBox c_photos;
	Gtk::HBox c_labels;

	for(int i = 0; i < containers.size(); i++)
	{
		if(containers[i].get_state_index() == 4)
		{
			c_files.push_back(containers[i].get_photo());
			Gtk::Label *buffer = new Gtk::Label{containers[i].name()};
			c_names.push_back(buffer);
		}
	}

	for(int i = 0; i < c_files.size(); i++)
	{
		c_photos.pack_start(*(c_files[i]), Gtk::PACK_SHRINK);
		Gtk::Label* l_buffer = c_names[i];
		l_buffer->set_width_chars(16);
		c_labels.pack_start(*(l_buffer), Gtk::PACK_SHRINK);
	}

	dialog->get_vbox()->pack_start(c_photos, Gtk::PACK_SHRINK);
	dialog->get_vbox()->pack_start(c_labels, Gtk::PACK_SHRINK);


	Gtk::Label l_toppings{"Toppings:"};
	dialog->get_vbox()->pack_start(l_toppings, Gtk::PACK_SHRINK);
	
	vector<Gtk::Image*> t_files;
	vector<Gtk::Label*> t_names;

	Gtk::HBox t_photos;
	Gtk::HBox t_labels;

	for(int i = 0; i < toppings.size(); i++)
	{
		if(toppings[i].get_state_index() == 4)
		{
			t_files.push_back(toppings[i].get_photo());
			Gtk::Label *buffer = new Gtk::Label{toppings[i].name()};
			t_names.push_back(buffer);
		}
	}

	for(int i = 0; i < t_files.size(); i++)
	{
		t_photos.pack_start(*(t_files[i]), Gtk::PACK_SHRINK);
		Gtk::Label* l_buffer = t_names[i];
		l_buffer->set_width_chars(16);
		t_labels.pack_start(*(l_buffer), Gtk::PACK_SHRINK);
	}

	dialog->get_vbox()->pack_start(t_photos, Gtk::PACK_SHRINK);
	dialog->get_vbox()->pack_start(t_labels, Gtk::PACK_SHRINK);
	

	// Show dialog
	dialog->add_button("Tasty!", 0);
	dialog->show_all();
	int result = dialog->run();

	dialog->close();
	while (Gtk::Main::events_pending())  Gtk::Main::iteration();

	return;
}

void Emporium::add_photos()
{
	for(int i = 0; i < scoops.size(); i++) if(!scoops[i].check_photo()) scoops[i].set_photo("Scoop");
	for(int i = 0; i < containers.size(); i++) if(!containers[i].check_photo()) containers[i].set_photo("Container");
	for(int i = 0; i < toppings.size(); i++) if(!toppings[i].check_photo()) toppings[i].set_photo("Topping");
}

void Emporium::test_photos()
{
	scoops[0].test_photo("chocolate.png");
	scoops[1].test_photo("vanilla.png");
	scoops[2].test_photo("strawberry.png");
	containers[0].test_photo("cone.png");
	containers[1].test_photo("waffle.png");
	toppings[0].test_photo("cherry.png");
	toppings[1].test_photo("sauce.png");
	toppings[2].test_photo("cream.png");
}

void Emporium::change_photos()
{
	Gtk::Dialog *dialog = new Gtk::Dialog();
	dialog->set_title("Change Photo");

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

	if(item == 0)
	{
		if(scoops.size() == 0) return;

		Gtk::Dialog *s_dialog = new Gtk::Dialog();
		dialog->set_title("Change Scoop Photo");

		Gtk::ComboBoxText s_names;
		c_type.set_size_request(160);
		
		for(int i = 0; i < scoops.size(); i++) s_names.append(scoops[i].name());

		s_dialog->get_vbox()->pack_start(s_names, Gtk::PACK_SHRINK);

		s_dialog->add_button("Cancel", 0);
		s_dialog->add_button("Ok", 1);
		s_dialog->show_all();

		int s_result = s_dialog->run();
		if(s_result == 0)
		{
			s_dialog->close();
			return;
		}
		int s_chosen = c_type.get_active_row_number();

		scoops[s_chosen].change_photo();

		s_dialog->close();
		while (Gtk::Main::events_pending())  Gtk::Main::iteration();

		return;
	}

	if(item == 1)
	{
		if(containers.size() == 0) return;

		Gtk::Dialog *s_dialog = new Gtk::Dialog();
		dialog->set_title("Change Container Photo");

		Gtk::ComboBoxText s_names;
		c_type.set_size_request(160);
		
		for(int i = 0; i < containers.size(); i++) s_names.append(containers[i].name());

		s_dialog->get_vbox()->pack_start(s_names, Gtk::PACK_SHRINK);

		s_dialog->add_button("Cancel", 0);
		s_dialog->add_button("Ok", 1);
		s_dialog->show_all();

		int s_result = s_dialog->run();
		if(s_result == 0)
		{
			s_dialog->close();
			return;
		}
		int s_chosen = c_type.get_active_row_number();

		containers[s_chosen].change_photo();

		s_dialog->close();
		while (Gtk::Main::events_pending())  Gtk::Main::iteration();

		return;
	}

	if(item == 2)
	{
		if(toppings.size() == 0) return;

		Gtk::Dialog *s_dialog = new Gtk::Dialog();
		dialog->set_title("Change Container Photo");

		Gtk::ComboBoxText s_names;
		c_type.set_size_request(160);
		
		for(int i = 0; i < toppings.size(); i++) s_names.append(toppings[i].name());

		s_dialog->get_vbox()->pack_start(s_names, Gtk::PACK_SHRINK);

		s_dialog->add_button("Cancel", 0);
		s_dialog->add_button("Ok", 1);
		s_dialog->show_all();

		int s_result = s_dialog->run();
		if(s_result == 0)
		{
			s_dialog->close();
			return;
		}
		int s_chosen = c_type.get_active_row_number();

		toppings[s_chosen].change_photo();

		s_dialog->close();
		while (Gtk::Main::events_pending())  Gtk::Main::iteration();

		return;
	}

}
void Emporium::edit_item()
{
	Gtk::Dialog *dialog = new Gtk::Dialog();
	dialog->set_title("Change Item");

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

	if(item == 0)
	{
		if(scoops.size() == 0) return;

		Gtk::Dialog *s_dialog = new Gtk::Dialog();
		s_dialog->set_title("Change Scoop Info");

		Gtk::ComboBoxText s_names;
		c_type.set_size_request(160);
		
		for(int i = 0; i < scoops.size(); i++) s_names.append(scoops[i].name());

		s_dialog->get_vbox()->pack_start(s_names, Gtk::PACK_SHRINK);

		s_dialog->add_button("Cancel", 0);
		s_dialog->add_button("Ok", 1);
		s_dialog->show_all();

		int s_result = s_dialog->run();
		if(s_result == 0)
		{
			s_dialog->close();
			return;
		}
		int s_chosen = c_type.get_active_row_number();

		int y = scoops[s_chosen].edit(0,0);

		s_dialog->close();
		while (Gtk::Main::events_pending())  Gtk::Main::iteration();

		return;
	}

	if(item == 1)
	{
		if(containers.size() == 0) return;

		Gtk::Dialog *s_dialog = new Gtk::Dialog();
		s_dialog->set_title("Change Container Info");

		Gtk::ComboBoxText s_names;
		c_type.set_size_request(160);
		
		for(int i = 0; i < containers.size(); i++) s_names.append(containers[i].name());

		s_dialog->get_vbox()->pack_start(s_names, Gtk::PACK_SHRINK);

		s_dialog->add_button("Cancel", 0);
		s_dialog->add_button("Ok", 1);
		s_dialog->show_all();

		int s_result = s_dialog->run();
		if(s_result == 0)
		{
			s_dialog->close();
			return;
		}
		int s_chosen = c_type.get_active_row_number();

		int x = containers[s_chosen].max_scoops();
		int y = containers[s_chosen].edit(1,x);
		containers[s_chosen].edit_scoops(y);

		s_dialog->close();
		while (Gtk::Main::events_pending())  Gtk::Main::iteration();

		return;
	}

	if(item == 2)
	{
		if(toppings.size() == 0) return;

		Gtk::Dialog *s_dialog = new Gtk::Dialog();
		s_dialog->set_title("Change Container Info");

		Gtk::ComboBoxText s_names;
		c_type.set_size_request(160);
		
		for(int i = 0; i < toppings.size(); i++) s_names.append(toppings[i].name());

		s_dialog->get_vbox()->pack_start(s_names, Gtk::PACK_SHRINK);

		s_dialog->add_button("Cancel", 0);
		s_dialog->add_button("Ok", 1);
		s_dialog->show_all();

		int s_result = s_dialog->run();
		if(s_result == 0)
		{
			s_dialog->close();
			return;
		}
		int s_chosen = c_type.get_active_row_number();

		int y = toppings[s_chosen].edit(2,0);

		s_dialog->close();
		while (Gtk::Main::events_pending())  Gtk::Main::iteration();

		return;
	}
}

void Emporium::edit_salary()
{
	if(servers.size() == 0) return;

	Gtk::Dialog *s_dialog = new Gtk::Dialog();
	s_dialog->set_title("Change Salary");

	Gtk::ComboBoxText c_servers;
	c_servers.set_size_request(160);
	
	for(int i = 0; i < servers.size(); i++) c_servers.append(servers[i].get_name());

	s_dialog->get_vbox()->pack_start(c_servers, Gtk::PACK_SHRINK);

	s_dialog->add_button("Cancel", 0);
	s_dialog->add_button("Ok", 1);
	s_dialog->show_all();

	int s_result = s_dialog->run();
	if(s_result == 0)
	{
		s_dialog->close();
		return;
	}
	int s_chosen = c_servers.get_active_row_number();

	servers[s_chosen].set_wage();

	s_dialog->close();
	while (Gtk::Main::events_pending())  Gtk::Main::iteration();
}

void Emporium::manage_stock(int option)
{
	Gtk::Dialog *dialog = new Gtk::Dialog();
	dialog->set_title("Change Stock");

	Gtk::ComboBoxText c_type;
	c_type.set_size_request(160);
	c_type.append("Scoops");
	c_type.append("Containers");
	
	dialog->get_vbox()->pack_start(c_type, Gtk::PACK_SHRINK);

	dialog->add_button("Cancel", 0);
	dialog->add_button("Ok", 1);
	dialog->show_all();

	int result = dialog->run();
	int item = c_type.get_active_row_number();


	dialog->close();
	while (Gtk::Main::events_pending())  Gtk::Main::iteration();

	if((result == 0) || (item == -1)) return;

	if(item == 0)
	{
		if(scoops.size() == 0) return;

		Gtk::Dialog *s_dialog = new Gtk::Dialog();
		s_dialog->set_title("Change Scoop Stock");

		Gtk::ComboBoxText s_names;
		s_names.set_size_request(160);
		
		for(int i = 0; i < scoops.size(); i++){
            if(scoops[i].get_state() != "retired"){
              s_names.append(scoops[i].name());
            }
        }
		s_dialog->get_vbox()->pack_start(s_names, Gtk::PACK_SHRINK);

		s_dialog->add_button("Cancel", 0);
		s_dialog->add_button("Ok", 1);
		s_dialog->show_all();

		int s_result = s_dialog->run();
		if(s_result == 0)
		{
			s_dialog->close();
			return;
		}
		int s_chosen = s_names.get_active_row_number();

		double cost = scoops[s_chosen].edit_stock(option);
		loss += cost;
		cash_register -= cost;

		s_dialog->close();
		while (Gtk::Main::events_pending())  Gtk::Main::iteration();

		return;
	}

	if(item == 1)
	{
		if(containers.size() == 0) return;

		Gtk::Dialog *s_dialog = new Gtk::Dialog();
		s_dialog->set_title("Change Container Info");

		Gtk::ComboBoxText s_names;
		s_names.set_size_request(160);
		
		for(int i = 0; i < containers.size(); i++){
           if(containers[i].get_state() != "retired"){
             s_names.append(containers[i].name());
           }
        }
		s_dialog->get_vbox()->pack_start(s_names, Gtk::PACK_SHRINK);

		s_dialog->add_button("Cancel", 0);
		s_dialog->add_button("Ok", 1);
		s_dialog->show_all();

		int s_result = s_dialog->run();
		if(s_result == 0)
		{
			s_dialog->close();
			return;
		}
		int s_chosen = s_names.get_active_row_number();

		double cost = containers[s_chosen].edit_stock(option);
		loss +=cost;
		cash_register -= cost;

		s_dialog->close();
		while (Gtk::Main::events_pending())  Gtk::Main::iteration();

		return;
	}

}

double Emporium::get_register(){
   return cash_register;
}

void Emporium::pay_order(int order_index)
{
	orders[order_index].pay();
	double price = orders[order_index].price();
    	cash_register += price;
	profit += price;
}

void Emporium::pay_server_fill(int server_choice)
{
	servers[server_choice].increase_orders();
    if(servers[server_choice].get_orders() % 10 == 0)
    {
		int wage = servers[server_choice].get_wage();
		loss += wage;
        cash_register -= wage;
    }
}

void Emporium::fill_order(int order_index, int server_index)
{
	orders[order_index].fill(servers[server_index]);
//    servers[server_index].increase_orders();
	vector<Serving> servings = orders[order_index].get_servings();

	for(int i = 0; i < servings.size(); i++)
	{
		int c_index = servings[i].get_c_index();
		containers[c_index].consume(1);
		(c_stock[c_index])--;

		vector<int> req = servings[i].get_s_req();
		for(int j = 0; j < s_stock.size(); j++)
		{
			int s_amount = req[j];
			s_stock[j] -= s_amount;
		    scoops[j].consume(s_amount);
		}
	}
}
