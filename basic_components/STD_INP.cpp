
#include "STD_INP.h"

#include <cstring>

#include "../memtrace.h"
// kapu neve a beolvasáshoz / kiíráshoz
const char* STD_INP::name = "STD_INP";
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
        if (!std::cin.good() || !(signal == 0 || signal == 1)) throw "Hibás bemenet egy STD_INP kapunak";
        is_signal_set = true;
    }
    int out_signal = signal;
    output->set_signal(out_signal);
}
void STD_INP::write(Wire* base_address, std::ostream& os) {
    os << name << " " << output - base_address << " " << label;
}
STD_INP::~STD_INP() {
    delete[] label;
}