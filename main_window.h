#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

//#include <gtkmm.h>
#include "controller.h"
//#include "view.h"
//#include "emporium.h"


class Main_window : public Gtk::Window {
   public:
      Main_window(Controller& c);
      virtual ~Main_window();
   protected:
      void on_create_order_click();
      void on_addflavor_click();
      void on_addcontainer_click();
      void on_addtopping_click();
      void on_addserver_click();
      void on_suspendserver_click();
      void on_restoreserver_click();
      void on_addcustomer_click();
      void on_addmanager_click();
      void on_manageorder_click();
      void on_serverreport_click();
      void on_customerreport_click();
      void on_profitreport_click();
      void on_inventoryreport_click();
      void on_orderreport_click();
      void on_fullorderreport_click();
      void on_payorder_click();
      void on_about_click();
      void on_quit_click();
      void on_save_click();
      void on_load_click();
      void on_testdata_click();
      void on_addphotos_click();
      void on_changephotos_click();
      void on_testphotos_click();
      void on_showmenu_click();
      void on_edititem_click();
      void on_editsalary_click();
      void on_restock_click();
      void on_editstock_click();
      void on_retireitem_click();

   private:
      Gtk::Label *msg;
      Gtk::ComboBoxText c_role;
      Controller _controller;

};
#endif
