// TODO kivenni
#define DEBUG
#include <fstream>
#include <iostream>

#include "basic_components.h"
#include "logic_network.h"
#include "memtrace.h"
#include "wire.h"
using std::cout;
using std::endl;
void asd(std::ostream& os) {
    os << "teszt" << std::endl;
}

int main() {
    // valamiért beleír az indító parancsba
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;

    LogicNetwork network;
    network.add_component(new INP(network.get_wire(0), 1));
    network.add_component(new PRINT(network.get_wire(0)));
    network.add_component(new PRINT(network.get_wire(100)));
    network.bulk_update(4);
    return 0;
}