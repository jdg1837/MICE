#include "dialogs.h"

// A message is like cout, simply displaying information to the user
void Dialogs::message(string msg, string title) {
    Gtk::MessageDialog *dialog = new Gtk::MessageDialog(title);
    dialog->set_secondary_text(msg, true);
    dialog->run();

    dialog->close();
    while (Gtk::Main::events_pending())  Gtk::Main::iteration();

    delete dialog;
}

// A question is a message that allows the user to respond with a button
int Dialogs::question(string msg, string title,
             vector<string> buttons) {
    Gtk::Dialog *dialog = new Gtk::Dialog();
    dialog->set_title(title);

    Gtk::Label *label = new Gtk::Label(msg);
    label->set_use_markup(true);
    dialog->get_content_area()->pack_start(*label);
    label->show();

    for(int i=0; i<buttons.size(); ++i) dialog->add_button(buttons[i], i);

    int result = dialog->run();

    dialog->close();
    while (Gtk::Main::events_pending())  Gtk::Main::iteration();

    delete label;
    delete dialog;

    return result;
}

// A request for a line of text input
string Dialogs::input(string msg, string title, string default_text, 
             string cancel_text) {
    Gtk::Dialog *dialog = new Gtk::Dialog();
    dialog->set_title(title);

    Gtk::Label *label = new Gtk::Label(msg);
    label->set_use_markup(true);
    dialog->get_content_area()->pack_start(*label);
    label->show();

    dialog->add_button("Cancel", 0);
    dialog->add_button("OK", 1);
    dialog->set_default_response(1);

    Gtk::Entry *entry = new Gtk::Entry{};
    entry->set_text(default_text);
    entry->set_max_length(50);
    entry->show();
    dialog->get_vbox()->pack_start(*entry);

    int result = dialog->run();
    string text = entry->get_text();

    dialog->close();
    while (Gtk::Main::events_pending())  Gtk::Main::iteration();

    delete entry;
    delete label;
    delete dialog;

    if (result == 1)
        return text;
    else
        return cancel_text;
}

// Display an image from a disk file
void Dialogs::image(string filename, string title, string msg) {
    Gtk::Dialog *dialog = new Gtk::Dialog();
    dialog->set_title(title);

    Gtk::Label *label = new Gtk::Label(msg);
    label->set_use_markup(true);
    dialog->get_content_area()->pack_start(*label);
    label->show();

    dialog->add_button("Close", 0);
    dialog->set_default_response(0);

    Gtk::Image *image = new Gtk::Image{filename};
    image->show();
    dialog->get_vbox()->pack_start(*image);

    int result = dialog->run();

    dialog->close();
    while (Gtk::Main::events_pending())  Gtk::Main::iteration();

    delete image;
    delete label;
    delete dialog;

    return;
}



/*
void Dialogs::get_publication(int item)
{
	string name = " ";
	string description = " ";
	int scoop = 0;
	double cost = 0.0;
	double price = 0.0;
	int stock = 0;

 while(true)
 {

	string title, author, copyright, isbn;
	int _genre, _media, _age;
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

	Gtk::Label l_name{item};
	l_name.set_width_chars(25);
	b_name.pack_start(l_name, Gtk::PACK_SHRINK);

	Gtk::Entry e_name;
	e_name.set_max_length(50);
	b_name.pack_start(e_title, Gtk::PACK_SHRINK);
	dialog->get_vbox()->pack_start(b_name, Gtk::PACK_SHRINK);

	// Description
	Gtk::HBox b_desc;

	Gtk::Label l_desc{"Description:"};
	l_desc.set_width_chars(25);
	b_desc.pack_start(l_desc, Gtk::PACK_SHRINK);

	Gtk::Entry e_desc;
	e_desc.set_max_length(50);
	b_desc.pack_start(e_author, Gtk::PACK_SHRINK);
	dialog->get_vbox()->pack_start(b_desc, Gtk::PACK_SHRINK);

	
	// Scoops
	Gtk::HBox b_scoops;	
	if(item == 1)
	{

	Gtk::Label l_scoops{"How many scoops can the container hold?:"};
	l_copyright.set_width_chars(15);
	b_copyright.pack_start(l_copyright, Gtk::PACK_SHRINK);

	Gtk::Entry e_copyright;
	e_copyright.set_max_length(50);
	b_copyright.pack_start(e_copyright, Gtk::PACK_SHRINK);
	dialog->get_vbox()->pack_start(b_copyright, Gtk::PACK_SHRINK);

	}

	// Cost
	Gtk::HBox b_cost;

	Gtk::Label l_cost{"Enter wholesale cost:"};
	l_age.set_width_chars(25);
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
		Glib::ustring s = "Error."
		if(item == 1) += " The input for scoops must be a fully numerical value.";
		s += " The input for cost and price must be numerical, but can be decimal in nature. Use a period (.) to separate the non-decimal part from the decimal part (ex, 7.35). Values asumed in USD. Do not use \"$\"";
		Gtk::MessageDialog dlg(*this, s, true, Gtk::MESSAGE_INFO, Gtk::BUTTONS_OK, true);
		dlg.run();
		continue;
	}


	if (result == 1)
	{
		if(item == 0)
		{
	                Scoop scoop{name, description, cost, price};
                        storefront.add_Scoop(scoop);
                        return;
		}

		if(item == 1)
		{
                        Container container{name, description, scoops, cost, price};
                        storefront.add_Container(container);
                        return;
		}

		if(item == 2)
		{
                        Topping topping{name, description, cost, price};
                        storefront.add_Topping(topping);
                        return;
		}
	}
	break;
 }
 return;
}

*/
