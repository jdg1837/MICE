#ifndef ITEM_H
#define ITEM_H

#include <string>
#include <gtkmm.h>
#include "dialogs.h"
#include "state.h"
using namespace std;

class Item {
  public:
    Item(std::string name, std::string description, double cost, double price, State state);
    void restock(int quantity = 25);
    void consume(int quantity = 1);
    virtual std::string type();
    std::string name() const;
    std::string description();
    double cost();
    double price() const;
    int quantity();
    void set_photo(string);
    void change_photo();
    void test_photo(string);
    void load_photo(string);
    Gtk::Image* get_photo();
    string get_photo_name();
    bool check_photo();
    int edit(int, int);
    double edit_stock(int);
    void load_stock(int);
    string get_state();
    void change_state();
    void set_state_index(string);
    int get_state_index();

  private:
    std::string _name;
    std::string _description;
    State _state;
    int state_index = 4;
    double _cost;
    double _price;
    int _quantity;
    string filename = "";
    bool has_photo;
    Gtk::Image* _photo;
};
#endif
