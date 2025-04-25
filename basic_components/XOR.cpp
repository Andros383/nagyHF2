#include "XOR.h"

#include "../memtrace.h"
#define DEBUG

XOR::XOR(Wire* inpA, Wire* inpB, Wire* out) {
    inputs = new Wire*[2];
    inputs[0] = inpA;
    inputs[1] = inpB;
    output = out;
}
void XOR::update() {
    bool a = inputs[0]->get_signal() == 1;
    bool b = inputs[1]->get_signal() == 1;
    bool out_signal = (a ^ b) ? 1 : 0;
    output->set_signal(out_signal);
}