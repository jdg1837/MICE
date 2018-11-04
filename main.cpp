#include "controller.h"
#include "emporium.h"
#include "main_window.h"
#include <gtkmm.h>

int main(int argc, char* argv[]){
  Glib::RefPtr<Gtk::Application> app = Gtk::Application::create(argc, argv, "edu.uta.cse1325.MICE");
  Emporium emporium;
  Controller controller(emporium);
  Main_window win(controller);
  win.set_title("MICE");
  return app->run(win);
}
