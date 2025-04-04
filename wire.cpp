
#include "wire.h"

Wire& Wire::operator=(const Wire& w) {
    return *this;
}

void Wire::tick() {
    output = input;
}
