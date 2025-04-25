#include "NOT.h"
#define DEBUG
#include "../memtrace.h"

NOT::NOT(Wire* inpA, Wire* out) {
    // egységesség miatt 1 elemhosszú tömbként
    inputs = new Wire*[1];
    inputs[0] = inpA;
    output = out;
}
void NOT::update() {
    bool a = inputs[0]->get_signal() == 1;
    bool out_signal = (a == 0) ? 1 : 0;
    output->set_signal(out_signal);
}