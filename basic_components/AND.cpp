#include "AND.h"
#define DEBUG

#include "../memtrace.h"

AND::AND(Wire* inpA, Wire* inpB, Wire* out) {
    inputs = new Wire*[2];
    inputs[0] = inpA;
    inputs[1] = inpB;
    output = out;
}
void AND::update() {
    bool a = inputs[0]->get_signal() == 1;
    bool b = inputs[1]->get_signal() == 1;
    int out_signal = (a && b) ? 1 : 0;
    output->set_signal(out_signal);
}
void AND::write(Wire* base_address, std::ostream& os) {
    os << "AND " << inputs[0] - base_address << " " << inputs[1] - base_address << " " << output - base_address;
}
