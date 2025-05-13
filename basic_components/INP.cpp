#include "INP.h"

#include "../memtrace.h"

// kapu neve a beolvasáshoz / kiíráshoz
const char* INP::name = "INP";
// annyira nem baj
INP::INP(Wire* out, int outer_signal) {
    output = out;
    signal = outer_signal;
}
void INP::update() {
    int out_signal = signal;
    output->set_signal(out_signal);
}
void INP::write(Wire* base_address, std::ostream& os) {
    os << name << " " << output - base_address << " " << signal;
}