#include "INP.h"
#define DEBUG

#include "../memtrace.h"

// TODO init listával megoldani? csak akkor az output-ot nem lehet beállítani
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
    os << "INP " << output - base_address << " " << signal;
}