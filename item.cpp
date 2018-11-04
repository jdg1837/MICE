#include "item.h"

Item::Item(std::string name, std::string description, double cost, double price, State state)
     : _name{name}, _description{description}, _cost{cost}, _price{price}, _state{state}, _quantity{0}, has_photo(false), _photo{NULL} { }
std::string Item::type() {return "Item";}
void Item::restock(int quantity) {_quantity  = quantity;}
void Item::consume(int quantity) {_quantity -= quantity;}
std::string Item::name() const {return _name;}
std::string Item::description() {return _description;}
double Item::cost() {return _cost;}
double Item::price() const {return _price;}
int Item::quantity() {return _quantity;}
Gtk::Image* Item::get_photo() {return _photo;}
string Item::get_photo_name() {return filename;}
void Item::set_photo(string type){
	string message = "Enter filename for " + type + ":" + name() + " photo";
	filename = Dialogs::input(message, "Add a photo");
	if(filename == "CANCEL") return;
	_photo = new Gtk::Image{filename};
	has_photo = true;
}
void Item::change_photo(){
	string message = "Enter new filename";
	filename = Dialogs::input(message, "Add a photo");
	if(filename == "CANCEL") return;
	_photo = new Gtk::Image{filename};
	has_photo = true;
}
void Item::load_photo(string Filename){
	_photo = new Gtk::Image{Filename};
	filename = Filename;
	has_photo = true;
}

void Item::test_photo(string Filename){
	_photo = new Gtk::Image{Filename};
	filename = Filename;
	has_photo = true;
}
string Item::get_state(){
    return _state.to_string();
}

void Item::change_state(){
    _state = 5;
    state_index = 5;
}

void Item::set_state_index(string state){
    state_index = stoi(state);
}

int Item::get_state_index(){
    return state_index;
}

bool Item::check_photo() {return has_photo;}

int Item::edit(int item, int max_scoops){
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

	if(item == 0) dialog->set_title("Edit Flavor");
	else if(item == 1) dialog->set_title("Edit Container");
	else if(item == 2) dialog->set_title("Edit Topping");

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
	e_name.set_text(_name);
	b_name.pack_start(e_name, Gtk::PACK_SHRINK);
	dialog->get_vbox()->pack_start(b_name, Gtk::PACK_SHRINK);

	// Description
	Gtk::HBox b_desc;

	Gtk::Label l_desc{"Description:"};
	l_desc.set_width_chars(25);
	b_desc.pack_start(l_desc, Gtk::PACK_SHRINK);

	Gtk::Entry e_desc;
	e_desc.set_max_length(50);
	e_desc.set_text(_description);
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
	e_scoops.set_text(to_string(max_scoops));
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
	e_cost.set_text(to_string(_cost));
	b_cost.pack_start(e_cost, Gtk::PACK_SHRINK);
	dialog->get_vbox()->pack_start(b_cost, Gtk::PACK_SHRINK);

	// Price
	Gtk::HBox b_price;

	Gtk::Label l_price{"Enter retail price:"};
	l_price.set_width_chars(25);
	b_price.pack_start(l_price, Gtk::PACK_SHRINK);

	Gtk::Entry e_price;
	e_price.set_max_length(50);
	e_price.set_text(to_string(_price));
	b_price.pack_start(e_price, Gtk::PACK_SHRINK);
	dialog->get_vbox()->pack_start(b_price, Gtk::PACK_SHRINK);

	// Show dialog
	dialog->add_button("Cancel", 0);
	dialog->add_button("OK", 1);
	dialog->show_all();
	int result = dialog->run();

	dialog->close();
	while (Gtk::Main::events_pending())  Gtk::Main::iteration();

	if(result == 0) return 0;

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
		Dialogs::message(s, "Error");
		continue;
	}

	_name = name;
	_description = description;
	_cost = cost;
	_price = price;
	if(item == 1) return scoops;
	
	break;
 }
 return 0;
}

double Item::edit_stock(int option)
{
	int new_stock;
 while(true)
 {
	string title, message, message2;
	if(option == 0){title = "Restock"; message2 = "Enter quantity to add to stock:";}
	if(option == 1){title = "Edit Stock"; message2 = "Enter new stock:";}
	message = "Current " + _name + " Stock: " + to_string(_quantity);
	string stock_in = Dialogs::input(message + '\n' + message2, title);
	if(stock_in == "CANCEL") return 0;
	try
	{
		new_stock = stoi(stock_in);
		if(new_stock < 0)
		{Dialogs::message("Stock cannot be a negative number", "Error"); continue;}
	}
	catch(exception e)
	{
		Dialogs::message("Stock must be numerical", "Error");
		continue;
	}
	break;
 }
	if(option == 0) _quantity += new_stock;
	if(option == 1) _quantity = new_stock;

	return new_stock*_cost;
}

void Item::load_stock(int new_stock)
{
	_quantity = new_stock;
}
