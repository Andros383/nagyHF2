#include "STD_INP.h"
#define DEBUG

#include "../memtrace.h"

// standard bemenetről tujda beolvasni a signal-t amit kirak
STD_INP::STD_INP(Wire* out, const char* outer_label) {
    output = out;
    is_signal_set = false;
    label = new char[strlen(outer_label) + 1];
    strcpy(label, outer_label);
}
void STD_INP::update() {
    if (!is_signal_set) {
        std::cout << "Input signal for " << label << ": ";
        std::cin >> signal;
        is_signal_set = true;
    }
    int out_signal = signal;
    output->set_signal(out_signal);
}
void STD_INP::write(Wire* base_address, std::ostream& os) {
    os << "STD_INP " << output - base_address << " " << label;
}
STD_INP::~STD_INP() {
    delete[] label;
}