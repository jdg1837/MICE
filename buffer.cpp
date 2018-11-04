
Gtk::Dialog *get_scoop_number = new Gtk::Dialog();
get_scoop_number->set_transient_for(*this);
get_scoop_number->set_title("Scoops");

Gtk::HBox b_scoops;

Gtk::Label l_scoops{"How many scoops?"};
l_scoops.set_width_chars(15);
b_scoops.pack_start(l_scoops, Gtk::PACK_SHRINK);

int j = c_container.get_active_row_number();
int n = containters[j].max_scoops();

Gtk::ComboBoxText c_scoops;
c_scoops.set_size_request(160);

for(int k = 1; k <= n; k++)
{
	c_scoops.append(to_string(k));
}

b_scoops.pack_start(c_scoops, Gtk::PACK_SHRINK);	
get_scoop_number->get_vbox()->pack_start(b_scoops, Gtk::PACK_SHRINK);


get_scoop_number->add_button("Cancel", 0);
get_scoop_number->add_button("Ok", 1);
get_scoop_number->show_all();

int result = get_scoop_number->run();
int num_scoops = c_scoops.get_active_row_number();

get_scoop_number->close();
while (Gtk::Main::events_pending())  Gtk::Main::iteration();

delete get_scoop_number;

if(result == 0) return;

vector<Item> scoops = emporium.get_scoops();


for(k = 1; k <= num_scoops; k++)
{
Gtk::Dialog *get_scoop = new Gtk::Dialog();
get_scoop->set_transient_for(*this);
get_scoop->set_title("Choose a scoops");

Gtk::HBox b_choose_scoop;

Gtk::ComboBoxText c_choose_scoop;
c_choose_scoop.set_size_request(160);

for(int z = 1; z <= ; z++)
{
	c_choose_scoop.append(scoops.name());
}

b_choose_scoop.pack_start(c_choose_scoop, Gtk::PACK_SHRINK);	
get_scoop_number->get_vbox()->pack_start(b_choose_scoop, Gtk::PACK_SHRINK);

get_scoop->add_button("Cancel", 0);
get_scoop->add_button("Ok", 1);
get_scoop->show_all();

int result = get_scoop->run();
int scoop_index = c_choose_scoop.get_active_row_number();

get_scoop->close();
while (Gtk::Main::events_pending())  Gtk::Main::iteration();

if(result == 0) return;

delete get_scoop_number;

serving.push_scoop(scoops[result]);
}
}
