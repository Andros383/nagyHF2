#ifndef COMPONENT_H
#define DEBUG
#define COMPONENT_H
#include <iostream>

#include "memtrace.h"
#include "wire.h"

// nincs component.cpp?

class Component {
    // a gyerekek állítják be, hogy mik legyenek a be és kimenetek
    // szerintem így jobb, mintha függvénnyel lenne
   protected:
    Wire** inputs;
    Wire* output;

   public:
    Component() : inputs(nullptr), output(nullptr) {};
    // NOTE nem konst sehol sem, mert lehessen olyat, aminek van belső állapota
    virtual void update() = 0;
    virtual ~Component();
    virtual const char* get_name() { return "Some_component_is_unnamed!"; }

#ifdef DEBUG
    virtual void debug() {
        std::cout << "Default component debug" << std::endl;
    };
#endif
};
#endif