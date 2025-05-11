#include "XOR.h"

#include "../memtrace.h"
// kapu neve a beolvasáshoz / kiíráshoz
const char* XOR::name = "XOR";
XOR::XOR(Wire* inpA, Wire* inpB, Wire* out) {
    inputs = new Wire*[2];
    inputs[0] = inpA;
    inputs[1] = inpB;
    output = out;
}
void XOR::update() {
    bool a = inputs[0]->get_signal() == 1;
    bool b = inputs[1]->get_signal() == 1;
    int out_signal = (a ^ b) ? 1 : 0;
    output->set_signal(out_signal);
}
void XOR::write(Wire* base_address, std::ostream& os) {
    os << name << " " << inputs[0] - base_address << " " << inputs[1] - base_address << " " << output - base_address;
}
