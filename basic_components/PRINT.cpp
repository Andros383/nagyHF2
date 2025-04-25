#include "PRINT.h"

#define DEBUG
#include "../memtrace.h"

PRINT::PRINT(Wire* inpA, const char* outer_label, std::ostream& os) : os(os) {
    // egységesség miatt 1 elemhosszú tömbként
    inputs = new Wire*[1];
    inputs[0] = inpA;
    label = outer_label;
}
void PRINT::update() {
    os << label << ": " << inputs[0]->get_signal() << std::endl;
}