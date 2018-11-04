CXXFLAGS += --std=c++11

all: div main
rebuild: div clean main

debug: CXXFLAGS += -g
debug: rebuild



main: main.o main_window.o emporium.o controller.o item.o scoop.o container.o topping.o person.o server.o customer.o serving.o manager.o order.o dialogs.o
	$(CXX) $(CXXFLAGS) -o main main.o main_window.o emporium.o controller.o item.o scoop.o container.o topping.o server.o customer.o serving.o manager.o person.o order.o dialogs.o `/usr/bin/pkg-config gtkmm-3.0 --cflags --libs`
main.o: main.cpp *.h
	$(CXX) $(CXXFLAGS) -c main.cpp `/usr/bin/pkg-config gtkmm-3.0 --cflags --libs`
test_topping.o: test_topping.cpp *.h
	$(CXX) $(CXXFLAGS) -c test_topping.cpp
test_topping: test_topping.o topping.o item.o
	$(CXX) $(CXXFLAGS) -o test_topping test_topping.o topping.o item.o
test_scoop.o: test_scoop.cpp *.h
	$(CXX) $(CXXFLAGS) -c test_scoop.cpp
test_scoop: test_scoop.o scoop.o item.o
	$(CXX) $(CXXFLAGS) -o test_scoop test_scoop.o scoop.o item.o
test_container.o: test_container.cpp *.h
	$(CXX) $(CXXFLAGS) -c test_container.cpp
test_container: test_container.o container.o item.o
	$(CXX) $(CXXFLAGS) -o test_container test_container.o container.o item.o
test_server.o: test_server.cpp *.h
	$(CXX) $(CXXFLAGS) -c test_server.cpp
test_server: test_server.o server.o person.o
	$(CXX) $(CXXFLAGS) -o test_server test_server.o server.o person.o
test_customer.o: test_customer.cpp *.h
	$(CXX) $(CXXFLAGS) -c test_customer.cpp
test_customer: test_customer.o customer.o person.o 
	$(CXX) $(CXXFLAGS) -o test_customer test_customer.o customer.o person.o
test_order.o: test_order.cpp *.h
	$(CXX) $(CXXFLAGS) -c test_order.cpp
test_order: test_order.o item.o person.o container.o customer.o topping.o scoop.o serving.o server.o order.o state.h
	$(CXX) $(CXXFLAGS) -o test_order test_order.o item.o person.o customer.o container.o topping.o scoop.o serving.o server.o order.o state.h 
main_window.o: main_window.cpp main_window.h *.h
	$(CXX) $(CXXFLAGS) -c main_window.cpp `/usr/bin/pkg-config gtkmm-3.0 --cflags --libs`
emporium.o: emporium.cpp emporium.h *.h
	$(CXX) $(CXXFLAGS) -c emporium.cpp `/usr/bin/pkg-config gtkmm-3.0 --cflags --libs`
controller.o: controller.cpp controller.h *.h
	$(CXX) $(CXXFLAGS) -c controller.cpp `/usr/bin/pkg-config gtkmm-3.0 --cflags --libs`
item.o: item.cpp item.h *.h
	$(CXX) $(CXXFLAGS) -c item.cpp `/usr/bin/pkg-config gtkmm-3.0 --cflags --libs`
scoop.o: scoop.cpp scoop.h *.h
	$(CXX) $(CXXFLAGS) -c scoop.cpp `/usr/bin/pkg-config gtkmm-3.0 --cflags --libs`
container.o: container.cpp container.h *.h
	$(CXX) $(CXXFLAGS) -c container.cpp `/usr/bin/pkg-config gtkmm-3.0 --cflags --libs`
topping.o: topping.cpp topping.h *.h
	$(CXX) $(CXXFLAGS) -c topping.cpp `/usr/bin/pkg-config gtkmm-3.0 --cflags --libs`
dialogs.o: dialogs.cpp *.h
	$(CXX) $(CXXFLAGS) -c dialogs.cpp `/usr/bin/pkg-config gtkmm-3.0 --cflags --libs`
person.o: person.cpp person.h *.h
	$(CXX) $(CXXFLAGS) -c person.cpp `/usr/bin/pkg-config gtkmm-3.0 --cflags --libs`
server.o: server.cpp server.h *.h
	$(CXX) $(CXXFLAGS) -c server.cpp `/usr/bin/pkg-config gtkmm-3.0 --cflags --libs`
customer.o: customer.cpp customer.h *.h
	$(CXX) $(CXXFLAGS) -c customer.cpp `/usr/bin/pkg-config gtkmm-3.0 --cflags --libs`
manager.o: manager.cpp manager.h *.h
	$(CXX) $(CXXFLAGS) -c manager.cpp `/usr/bin/pkg-config gtkmm-3.0 --cflags --libs`    
order.o: order.cpp order.h *.h
	$(CXX) $(CXXFLAGS) -c order.cpp `/usr/bin/pkg-config gtkmm-3.0 --cflags --libs`
serving.o: serving.cpp serving.h *.h
	$(CXX) $(CXXFLAGS) -c serving.cpp `/usr/bin/pkg-config gtkmm-3.0 --cflags --libs`
test_serving.o: test_serving.cpp *.h
	$(CXX) $(CXXFLAGS) -c test_serving.cpp
test_serving: test_serving.o serving.o item.o scoop.o topping.o container.o
	$(CXX) $(CXXFLAGS) -o test_serving test_serving.o serving.o item.o scoop.o topping.o container.o
clean:
	-rm -f *.o *~ main test_container test_scoop test_topping test_server test_customer test_order test_serving
div:
	# 'X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-'
	# '-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X'
	# 'X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-'
	# '-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X'
