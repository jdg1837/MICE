#ifndef __STATE_H
#define __STATE_H

#include "string"
using namespace std;

class State {
   public:
     State(int val) : value(val) { }

     static const int unfilled = 0;
     static const int filled = 1;
     static const int paid = 2;
     static const int canceled = 3;
     static const int active = 4;
     static const int retired = 5;

     //STATE MACHINE
     string to_string() {
        switch(value){
           case(unfilled):return "unfilled";
           case(filled):return "filled";
           case(paid):return "paid";
           case(canceled):return "canceled";
           case(active):return "active";
           case(retired):return "retired";
           default: return "UNKNOWN";

        }

     }
   
     void change_state(int val){
         value = val;
     }

   private:
     int value;
};
#endif
