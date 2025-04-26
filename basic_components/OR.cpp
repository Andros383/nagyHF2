#include "OR.h"

#include "../memtrace.h"
#define DEBUG

OR::OR(Wire* inpA, Wire* inpB, Wire* out) {
    inputs = new Wire*[2];
    inputs[0] = inpA;
    inputs[1] = inpB;
    output = out;
}
void OR::update() {
    bool a = inputs[0]->get_signal() == 1;
    bool b = inputs[1]->get_signal() == 1;
    int out_signal = (a || b) ? 1 : 0;
    output->set_signal(out_signal);
}
void OR::write(Wire* base_address, std::ostream& os) {
    os << "OR " << inputs[0] - base_address << " " << inputs[1] - base_address << " " << output - base_address;
}
