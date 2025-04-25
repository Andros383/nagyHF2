#include "wire.h"
#define DEBUG

void Wire::update() {
    output = input;
    input = 0;
}
void Wire::set_signal(int signal) {
    input = input > signal ? input : signal;
}