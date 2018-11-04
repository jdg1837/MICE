#include "main_window.h"
//#include "view.h"
#include "dialogs.h"

Main_window::Main_window(Controller& controller) : _controller{controller} {
   
    Gtk::Dialog *dialog = new Gtk::Dialog();
    dialog->set_title("Select your role");

    Gtk::HBox b_role;
  
    Gtk::Label l_role{"Pick your role: "};
    l_role.set_width_chars(15);
    b_role.pack_start(l_role, Gtk::PACK_SHRINK);

    c_role.append("Customer");
    c_role.append("Server");
    c_role.append("Manager");
    c_role.append("Owner");

    b_role.pack_start(c_role, Gtk::PACK_SHRINK);
    dialog->get_vbox()->pack_start(b_role, Gtk::PACK_SHRINK);
   
    dialog->add_button("Ok", 1);
    dialog->show_all();

    int result = dialog->run();

    int role_choice = c_role.get_active_row_number();

    dialog->close();
    while (Gtk::Main::events_pending())  Gtk::Main::iteration();


    set_default_size(400,200);

    Gtk::Box *vbox = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_VERTICAL, 0));
    add(*vbox);

    Gtk::MenuBar *menubar = Gtk::manage(new Gtk::MenuBar());
    vbox->pack_start(*menubar, Gtk::PACK_SHRINK, 0);

    //     F I L E
    // Create a File menu and add to the menu bar
    Gtk::MenuItem *menuitem_file = Gtk::manage(new Gtk::MenuItem("_File", true));
    menubar->append(*menuitem_file);
    Gtk::Menu *filemenu = Gtk::manage(new Gtk::Menu());
    menuitem_file->set_submenu(*filemenu);
    
    //        S A V E
    //  Append Save to the File menu
	if(role_choice == 1 || role_choice == 2 || role_choice == 3){
    Gtk::MenuItem *menuitem_save = Gtk::manage(new Gtk::MenuItem("_Save", true));
    menuitem_save->signal_activate().connect(sigc::mem_fun(*this, &Main_window::on_save_click));
    filemenu->append(*menuitem_save);

    //        L O A D
    //  Append Load to the File menu
    Gtk::MenuItem *menuitem_load = Gtk::manage(new Gtk::MenuItem("_Load", true));
    menuitem_load->signal_activate().connect(sigc::mem_fun(*this, &Main_window::on_load_click));
    filemenu->append(*menuitem_load);
    }
    //         Q U I T
    // Append Quit to the File menu
    Gtk::MenuItem *menuitem_quit = Gtk::manage(new Gtk::MenuItem("_Quit", true));
    menuitem_quit->signal_activate().connect(sigc::mem_fun(*this, &Main_window::on_quit_click));
    filemenu->append(*menuitem_quit);

    //	      N E W
    // Create a New menu and add to the menu bar
    Gtk::MenuItem *menuitem_new = Gtk::manage(new Gtk::MenuItem("_New", true));
    menubar->append(*menuitem_new);
    Gtk::Menu *newmenu = Gtk::manage(new Gtk::Menu());
    menuitem_new->set_submenu(*newmenu);

    //    A D D  F L A V O R
    // Append Add Flavor to the New menu
	if(role_choice == 2 || role_choice == 3){
    Gtk::MenuItem *menuitem_addflavor = Gtk::manage(new Gtk::MenuItem("_Add Flavor", true));
    menuitem_addflavor->signal_activate().connect(sigc::mem_fun(*this, &Main_window::on_addflavor_click));
    newmenu->append(*menuitem_addflavor);

//    A D D  T O P P I N G
    // Append Add Topping to the New menu
    Gtk::MenuItem *menuitem_addtopping = Gtk::manage(new Gtk::MenuItem("_Add Topping", true));
    menuitem_addtopping->signal_activate().connect(sigc::mem_fun(*this, &Main_window::on_addtopping_click));
    newmenu->append(*menuitem_addtopping);

//    A D D  C O N T A I N E R
    // Append Add Container to the New menu
    Gtk::MenuItem *menuitem_addcontainer = Gtk::manage(new Gtk::MenuItem("_Add Container", true));
    menuitem_addcontainer->signal_activate().connect(sigc::mem_fun(*this, &Main_window::on_addcontainer_click));
    newmenu->append(*menuitem_addcontainer);

//    A D D  S E R V E R
    // Append Add Server to the New menu
    Gtk::MenuItem *menuitem_addserver = Gtk::manage(new Gtk::MenuItem("_Add Server", true));
    menuitem_addserver->signal_activate().connect(sigc::mem_fun(*this, &Main_window::on_addserver_click));
    newmenu->append(*menuitem_addserver);

//    A D D  C U S T O M E R
    // Append Add Customer to the New menu
    Gtk::MenuItem *menuitem_addcustomer = Gtk::manage(new Gtk::MenuItem("_Add Customer", true));
    menuitem_addcustomer->signal_activate().connect(sigc::mem_fun(*this, &Main_window::on_addcustomer_click));
    newmenu->append(*menuitem_addcustomer);

//     A D D  M A N A G E R
//     Append Add Manager to the New menu
    Gtk::MenuItem *menuitem_addmanager = Gtk::manage(new Gtk::MenuItem("_Add Manager", true));
    menuitem_addmanager->signal_activate().connect(sigc::mem_fun(*this, &Main_window::on_addmanager_click));
    newmenu->append(*menuitem_addmanager);

//    A D D  I T E M  P H O T O S
      //Append Add Photos to Menu
    Gtk::MenuItem *menuitem_addphotos = Gtk::manage(new Gtk::MenuItem("_Add photos", true));
    menuitem_addphotos->signal_activate().connect(sigc::mem_fun(*this, &Main_window::on_addphotos_click));
    newmenu->append(*menuitem_addphotos);
}
//    C R E A T E   N E W   O R D E R
      //Append Create new order to the New menu
    Gtk::MenuItem *menuitem_neworder = Gtk::manage(new Gtk::MenuItem("_Create Order", true));
    menuitem_neworder->signal_activate().connect(sigc::mem_fun(*this, &Main_window::on_create_order_click));
    newmenu->append(*menuitem_neworder);

	//     M A N A G E
    // Create a Manage menu and add to the menu bar
	if(role_choice == 1 || role_choice == 2 || role_choice == 3){
    Gtk::MenuItem *menuitem_manage = Gtk::manage(new Gtk::MenuItem("_Manage", true));
    menubar->append(*menuitem_manage);
    Gtk::Menu *managemenu = Gtk::manage(new Gtk::Menu());
    menuitem_manage->set_submenu(*managemenu);

    // R E T I R E  I T E M
    // Append Retire Item to the manage menu
    Gtk::MenuItem *menuitem_retireitem = Gtk::manage(new Gtk::MenuItem("_Retire Item", true));
    menuitem_retireitem->signal_activate().connect(sigc::mem_fun(*this, &Main_window::on_retireitem_click));
    managemenu->append(*menuitem_retireitem);

    //  I N V E N T O R Y  R E P O R T
    //  Append Inventory Report to the Manage menu
    Gtk::MenuItem *menuitem_ireport = Gtk::manage(new Gtk::MenuItem("_Inventory Report", true));
    menuitem_ireport->signal_activate().connect(sigc::mem_fun(*this, &Main_window::on_inventoryreport_click));
    managemenu->append(*menuitem_ireport);

    //  S E R V E R  R E P O R T 
    // Append Server Report to the Manage menu
    Gtk::MenuItem *menuitem_sreport = Gtk::manage(new Gtk::MenuItem("_Server Report", true));
    menuitem_sreport->signal_activate().connect(sigc::mem_fun(*this, &Main_window::on_serverreport_click));
    managemenu->append(*menuitem_sreport);

//    S U S P E N D  S E R V E R
    // Append Suspend Server to the New menu
    Gtk::MenuItem *menuitem_suspendserver = Gtk::manage(new Gtk::MenuItem("_Suspend Server", true));
    menuitem_suspendserver->signal_activate().connect(sigc::mem_fun(*this, &Main_window::on_suspendserver_click));
    managemenu->append(*menuitem_suspendserver);

//    R E S T O R E  S E R V E R
    // Append Restore Server to the New menu
    Gtk::MenuItem *menuitem_restoreserver = Gtk::manage(new Gtk::MenuItem("_Restore Server", true));
    menuitem_restoreserver->signal_activate().connect(sigc::mem_fun(*this, &Main_window::on_restoreserver_click));
    managemenu->append(*menuitem_restoreserver);

    
    //  C U S T O M E R  R E P O R T 
    //  Append Customer report to the Manage menu
    Gtk::MenuItem *menuitem_creport = Gtk::manage(new Gtk::MenuItem("_Customer Report", true));
    menuitem_creport->signal_activate().connect(sigc::mem_fun(*this, &Main_window::on_customerreport_click));
    managemenu->append(*menuitem_creport);

    //  P R O F I T  R E P O R T 
    //  Append Profit report to the Manage menu
    Gtk::MenuItem *menuitem_preport = Gtk::manage(new Gtk::MenuItem("_Profit Report", true));
    menuitem_preport->signal_activate().connect(sigc::mem_fun(*this, &Main_window::on_profitreport_click));
    managemenu->append(*menuitem_preport);

    //  O R D E R  R E P O R T 
    //  Append Order report to the Manage menu
    Gtk::MenuItem *menuitem_foreport = Gtk::manage(new Gtk::MenuItem("_Order History", true));
    menuitem_foreport->signal_activate().connect(sigc::mem_fun(*this, &Main_window::on_fullorderreport_click));
    managemenu->append(*menuitem_foreport);

    //  F U L L O R D E R  R E P O R T 
    //  Append Order report to the Manage menu
    Gtk::MenuItem *menuitem_oreport = Gtk::manage(new Gtk::MenuItem("_Order Report", true));
    menuitem_oreport->signal_activate().connect(sigc::mem_fun(*this, &Main_window::on_orderreport_click));
    managemenu->append(*menuitem_oreport);

    //     F I L L O R D E R
    // Append Fill Order to the Manage menu
    Gtk::MenuItem *menuitem_morder = Gtk::manage(new Gtk::MenuItem("Fill Order", true));
    menuitem_morder->signal_activate().connect(sigc::mem_fun(*this, &Main_window::on_manageorder_click));
    managemenu->append(*menuitem_morder);

    //     P A Y O R D E R
    // Append Pay for Order to the Manage menu
    Gtk::MenuItem *menuitem_porder = Gtk::manage(new Gtk::MenuItem("Pay for Order", true));
    menuitem_porder->signal_activate().connect(sigc::mem_fun(*this, &Main_window::on_payorder_click));
    managemenu->append(*menuitem_porder);

    //     R E S T O C K
    // Append Restock Item to the Manage menu
    Gtk::MenuItem *menuitem_restock = Gtk::manage(new Gtk::MenuItem("Restock Item", true));
    menuitem_restock->signal_activate().connect(sigc::mem_fun(*this, &Main_window::on_restock_click));
    managemenu->append(*menuitem_restock);
    }

	if(role_choice == 1 || role_choice == 2 || role_choice == 3){
    //     E D I T
    // Create an Edit menu and add to the menu bar
    Gtk::MenuItem *menuitem_edit = Gtk::manage(new Gtk::MenuItem("_Edit", true));
    menubar->append(*menuitem_edit);
    Gtk::Menu *editmenu = Gtk::manage(new Gtk::Menu());
    menuitem_edit->set_submenu(*editmenu);

     //   C H A N G E  I T E M  I N F O
     //Append Edit Item to Menu
    Gtk::MenuItem *menuitem_edititem = Gtk::manage(new Gtk::MenuItem("_Edit Item", true));
    menuitem_edititem->signal_activate().connect(sigc::mem_fun(*this, &Main_window::on_edititem_click));
    editmenu->append(*menuitem_edititem);

    //   C H A N G E  I T E M  P H O T O S
    //Append Change Photos to Menu
    Gtk::MenuItem *menuitem_changephotos = Gtk::manage(new Gtk::MenuItem("_Change photos", true));
    menuitem_changephotos->signal_activate().connect(sigc::mem_fun(*this, &Main_window::on_changephotos_click));
    editmenu->append(*menuitem_changephotos);

	if(role_choice == 2){
    //   C H A N G E  S A L A R Y
    //Append Change Photos to Menu
    Gtk::MenuItem *menuitem_editsalary = Gtk::manage(new Gtk::MenuItem("_Edit Salary", true));
    menuitem_editsalary->signal_activate().connect(sigc::mem_fun(*this, &Main_window::on_editsalary_click));
    editmenu->append(*menuitem_editsalary);
    }

    //   C H A N G E  I T E M  S T O C K
    //Append Change Stock to Menu
    Gtk::MenuItem *menuitem_editstock = Gtk::manage(new Gtk::MenuItem("_Edit Stock", true));
    menuitem_editstock->signal_activate().connect(sigc::mem_fun(*this, &Main_window::on_editstock_click));
    editmenu->append(*menuitem_editstock);
}
    //     H E L P
    // Create a Help menu and add to the menu bar
    Gtk::MenuItem *menuitem_help = Gtk::manage(new Gtk::MenuItem("_Help", true));
    menubar->append(*menuitem_help);
    Gtk::Menu *helpmenu = Gtk::manage(new Gtk::Menu());
    menuitem_help->set_submenu(*helpmenu);

	if(role_choice == 1 || role_choice == 2 || role_choice == 3){
    //           T E S T  D A T A
    // Append Test Data to the Help menu
    Gtk::MenuItem *menuitem_test = Gtk::manage(new Gtk::MenuItem("Test Data", true));
    menuitem_test->signal_activate().connect(sigc::mem_fun(*this, &Main_window::on_testdata_click));
    helpmenu->append(*menuitem_test);

    //   A D D  T E S T  I T E M  P H O T O S
    //Append Add Test Photos to Menu
    Gtk::MenuItem *menuitem_testphotos = Gtk::manage(new Gtk::MenuItem("_Test photos", true));
    menuitem_testphotos->signal_activate().connect(sigc::mem_fun(*this, &Main_window::on_testphotos_click));
    helpmenu->append(*menuitem_testphotos);
    }

    //           A B O U T
    // Append About to the Help menu
    Gtk::MenuItem *menuitem_about = Gtk::manage(new Gtk::MenuItem("About", true));
    menuitem_about->signal_activate().connect(sigc::mem_fun(*this, &Main_window::on_about_click));
    helpmenu->append(*menuitem_about);

    //     S H O W
    Gtk::MenuItem *menuitem_show = Gtk::manage(new Gtk::MenuItem("_Show", true));
    menubar->append(*menuitem_show);
    Gtk::Menu *showmenu = Gtk::manage(new Gtk::Menu());
    menuitem_show->set_submenu(*showmenu);

    //          S H O W  M E N U
    // Append Items Menu to the Show menu
    Gtk::MenuItem *menuitem_itemsmenu = Gtk::manage(new Gtk::MenuItem("Menu", true));
    menuitem_itemsmenu->signal_activate().connect(sigc::mem_fun(*this, &Main_window::on_showmenu_click));
    showmenu->append(*menuitem_itemsmenu);

	//TOOLBAR
	Gtk::Toolbar *toolbar = Gtk::manage(new Gtk::Toolbar);
	vbox->add(*toolbar);
	Gtk::Toolbar *toolbar2 = Gtk::manage(new Gtk::Toolbar);
	vbox->add(*toolbar2);
	Gtk::Toolbar *toolbar3 = Gtk::manage(new Gtk::Toolbar);
	vbox->add(*toolbar3);
	Gtk::Toolbar *toolbar4 = Gtk::manage(new Gtk::Toolbar);
	vbox->add(*toolbar4);


    if(role_choice == 1 || role_choice == 2 || role_choice == 3){
	Gtk::Image *new_scoop_icon = Gtk::manage(new Gtk::Image("new_scoop_icon.png"));
	Gtk::ToolButton *new_scoop = Gtk::manage(new Gtk::ToolButton(*new_scoop_icon));
	new_scoop->set_tooltip_markup("Add a Flavor");
	new_scoop->signal_clicked().connect(sigc::mem_fun(*this, &Main_window::on_addflavor_click));
	toolbar->append(*new_scoop);

	Gtk::Image *new_container_icon = Gtk::manage(new Gtk::Image("new_container_icon.png"));
	Gtk::ToolButton *new_container = Gtk::manage(new Gtk::ToolButton(*new_container_icon));
	new_container->set_tooltip_markup("Add a Container");
	new_container->signal_clicked().connect(sigc::mem_fun(*this, &Main_window::on_addcontainer_click));
	toolbar->append(*new_container);

	Gtk::Image *new_topping_icon = Gtk::manage(new Gtk::Image("new_topping_icon.png"));
	Gtk::ToolButton *new_topping = Gtk::manage(new Gtk::ToolButton(*new_topping_icon));
	new_topping->set_tooltip_markup("Add a Topping");
	new_topping->signal_clicked().connect(sigc::mem_fun(*this, &Main_window::on_addtopping_click));
	toolbar->append(*new_topping);

	Gtk::Image *new_server_icon = Gtk::manage(new Gtk::Image("new_server_icon.png"));
	Gtk::ToolButton *new_server = Gtk::manage(new Gtk::ToolButton(*new_server_icon));
	new_server->set_tooltip_markup("Hire a Server");
	new_server->signal_clicked().connect(sigc::mem_fun(*this, &Main_window::on_addserver_click));
	toolbar2->append(*new_server);

	Gtk::Image *new_customer_icon = Gtk::manage(new Gtk::Image("new_customer_icon.png"));
	Gtk::ToolButton *new_costumer = Gtk::manage(new Gtk::ToolButton(*new_customer_icon));
	new_costumer->set_tooltip_markup("Add a Customer");
	new_costumer->signal_clicked().connect(sigc::mem_fun(*this, &Main_window::on_addcustomer_click));
	toolbar2->append(*new_costumer);
}

	Gtk::Image *show_menu_icon = Gtk::manage(new Gtk::Image("show_menu_icon.png"));
	Gtk::ToolButton *show_menu = Gtk::manage(new Gtk::ToolButton(*show_menu_icon));
	show_menu->set_tooltip_markup("Show Menu");
	show_menu->signal_clicked().connect(sigc::mem_fun(*this, &Main_window::on_showmenu_click));
	toolbar3->append(*show_menu);

	Gtk::Image *new_order_icon = Gtk::manage(new Gtk::Image("new_order_icon.png"));
	Gtk::ToolButton *new_order = Gtk::manage(new Gtk::ToolButton(*new_order_icon));
	new_order->set_tooltip_markup("Create an Order");
	new_order->signal_clicked().connect(sigc::mem_fun(*this, &Main_window::on_create_order_click));
	toolbar3->append(*new_order);

	if(role_choice == 1 || role_choice == 2 || role_choice == 3){

	Gtk::Image *fill_order_icon = Gtk::manage(new Gtk::Image("fill_order_icon.png"));
	Gtk::ToolButton *fill_order = Gtk::manage(new Gtk::ToolButton(*fill_order_icon));
	fill_order->set_tooltip_markup("Fill an Order");
	fill_order->signal_clicked().connect(sigc::mem_fun(*this, &Main_window::on_manageorder_click));
	toolbar3->append(*fill_order);

	Gtk::Image *pay_order_icon = Gtk::manage(new Gtk::Image("pay_order_icon.png"));
	Gtk::ToolButton *pay_order = Gtk::manage(new Gtk::ToolButton(*pay_order_icon));
	pay_order->set_tooltip_markup("Pay an Order");
	pay_order->signal_clicked().connect(sigc::mem_fun(*this, &Main_window::on_payorder_click));
	toolbar3->append(*pay_order);

	Gtk::Image *server_report_icon = Gtk::manage(new Gtk::Image("server_report_icon.png"));
	Gtk::ToolButton *server_report = Gtk::manage(new Gtk::ToolButton(*server_report_icon));
	server_report->set_tooltip_markup("Server Report");
	server_report->signal_clicked().connect(sigc::mem_fun(*this, &Main_window::on_serverreport_click));
	toolbar4->append(*server_report);

	Gtk::Image *customer_report_icon = Gtk::manage(new Gtk::Image("customer_report_icon.png"));
	Gtk::ToolButton *customer_report = Gtk::manage(new Gtk::ToolButton(*customer_report_icon));
	customer_report->set_tooltip_markup("Customer Report");
	customer_report->signal_clicked().connect(sigc::mem_fun(*this, &Main_window::on_customerreport_click));
	toolbar4->append(*customer_report);

	Gtk::Image *inventory_report_icon = Gtk::manage(new Gtk::Image("inventory_report_icon.png"));
	Gtk::ToolButton *inventory_report = Gtk::manage(new Gtk::ToolButton(*inventory_report_icon));
	inventory_report->set_tooltip_markup("Inventory Report");
	inventory_report->signal_clicked().connect(sigc::mem_fun(*this, &Main_window::on_inventoryreport_click));
	toolbar4->append(*inventory_report);

	Gtk::Image *profit_report_icon = Gtk::manage(new Gtk::Image("profit_report_icon.png"));
	Gtk::ToolButton *profit_report = Gtk::manage(new Gtk::ToolButton(*profit_report_icon));
	profit_report->set_tooltip_markup("Profit Report");
	profit_report->signal_clicked().connect(sigc::mem_fun(*this, &Main_window::on_profitreport_click));
	toolbar4->append(*profit_report);

	Gtk::Image *order_report_icon = Gtk::manage(new Gtk::Image("order_report_icon.png"));
	Gtk::ToolButton *order_report = Gtk::manage(new Gtk::ToolButton(*order_report_icon));
	order_report->set_tooltip_markup("Order Report");
	order_report->signal_clicked().connect(sigc::mem_fun(*this, &Main_window::on_orderreport_click));
	toolbar4->append(*order_report);

	Gtk::Image *order_history_icon = Gtk::manage(new Gtk::Image("order_history_icon.png"));
	Gtk::ToolButton *order_history = Gtk::manage(new Gtk::ToolButton(*order_history_icon));
	order_history->set_tooltip_markup("Order History");
	order_history->signal_clicked().connect(sigc::mem_fun(*this, &Main_window::on_fullorderreport_click));
	toolbar4->append(*order_history);
}

    vbox->show_all();  

}


Main_window::~Main_window() { }

void Main_window::on_create_order_click(){
   
 _controller.create_new_order();
    
}

void Main_window::on_quit_click()
{
	hide();
}

void Main_window::on_save_click(){
    _controller.open_file(0);
}

void Main_window::on_load_click(){
    _controller.open_file(1);
}
void Main_window::on_retireitem_click(){
    _controller.retire_item();
}

void Main_window::on_addflavor_click()
{
	_controller.add_item(0);
}

void Main_window::on_addcontainer_click()
{
	_controller.add_item(1);
}

void Main_window::on_addtopping_click()
{
	_controller.add_item(2);
}

void Main_window::on_addserver_click()
{
	_controller.add_server();
}

void Main_window::on_suspendserver_click()
{
	_controller.suspend_server();
}

void Main_window::on_restoreserver_click()
{
	_controller.restore_server();
}

void Main_window::on_addcustomer_click()
{
	_controller.add_customer();
}


void Main_window::on_addmanager_click(){
    _controller.add_manager();
}

void Main_window::on_manageorder_click(){
    _controller.fill_order();
}

void Main_window::on_payorder_click(){
    _controller.pay_for_order();
}

void Main_window::on_about_click() 
{
    Glib::ustring s = "===============================\n <b>Mavericks Ice Cream Emporium<sup>R</sup></b>\n===============================\n\n<i>Designed by Jonathan El-Khoury\n                           Juan Diego Gonzalez German\n                           Chelsea May</i>\nCopyright 2017\n\nAll icons created by Gonzalez \n";
    Gtk::MessageDialog dlg(*this, s, true, Gtk::MESSAGE_INFO, Gtk::BUTTONS_OK, true);
    dlg.run();
}

void Main_window::on_testdata_click()
{                                                                                            
        _controller.test_data();
}

void Main_window::on_addphotos_click()
{
	_controller.add_photos();
}

void Main_window::on_changephotos_click()
{
	_controller.change_photos();
}

void Main_window::on_testphotos_click()
{
	_controller.test_photos();
}

void Main_window::on_showmenu_click()
{
	_controller.print_menu();
}

void Main_window::on_edititem_click()
{
	_controller.edit_item();
}

void Main_window::on_editsalary_click()
{
	_controller.edit_salary();
}

void Main_window::on_restock_click()
{
	_controller.manage_stock(0);
}

void Main_window::on_editstock_click()
{
	_controller.manage_stock(1);
}

void Main_window::on_serverreport_click(){
    _controller.print_server_report();
}

void Main_window::on_customerreport_click(){
    _controller.print_customer_report();
}

void Main_window::on_profitreport_click(){
    _controller.print_profit_report();
}

void Main_window::on_inventoryreport_click(){
    _controller.print_inventory_report();
}

void Main_window::on_orderreport_click(){
    _controller.print_order_report(0);
}

void Main_window::on_fullorderreport_click(){
    _controller.print_order_report(1);
}
