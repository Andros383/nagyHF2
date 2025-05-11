#ifndef WIRE_H
#define WIRE_H
#include <iostream>

#include "memtrace.h"
class Wire {
    int input;
    int output;

   public:
    Wire() : input(0), output(0) {}
    // elejéről a végére rakja a jelet
    void update();
    // beállítja a jelet a bemenetén
    void set_signal(int signal);
    // visszaadja a kimenetén lévő jelet
    int get_signal() const {
        return output;
    }
};

#endif