#include "PRINT.h"

#include <cstring>

#include "../memtrace.h"
// kapu neve a beolvasáshoz / kiíráshoz
const char* PRINT::name = "PRINT";
PRINT::PRINT(Wire* inpA, const char* outer_label, std::ostream& os) : os(os) {
    // egységesség miatt 1 elemhosszú tömbként
    inputs = new Wire*[1];
    inputs[0] = inpA;
    label = new char[strlen(outer_label) + 1];
    strcpy(label, outer_label);
}
void PRINT::update() {
    os << label << ": " << inputs[0]->get_signal() << std::endl;
}
void PRINT::write(Wire* base_address, std::ostream& os) {
    os << name << " " << inputs[0] - base_address << " " << label;
}
PRINT::~PRINT() {
    delete[] label;
}
