// TODO mindenhova kell a rohadt debug?
// buta lsp
#define DEBUG
#include <iostream>

#include "basic_components.h"
#include "logic_network.h"
#include "memtrace.h"
#include "wire.h"
using std::cout;
using std::endl;
void wire_test() {
    Wire w1 = Wire();
    w1.debug();
    w1.set_signal(1);
    w1.debug();
    cout << "Signal get " << w1.get_signal() << endl;
    w1.update();
    w1.debug();
    cout << "Signal get " << w1.get_signal() << endl;
}
void XOR_test() {
    Wire a, b, c;
    a.set_signal(1);
    b.set_signal(0);
    a.debug();
    b.debug();
    c.debug();

    a.update();
    b.update();
    c.update();

    XOR x1(&a, &b, &c);
    x1.update();
    x1.debug();

    a.debug();
    b.debug();
    c.debug();
}

void inp_test() {
    Wire a;
    INP i1(&a, 1);
    i1.debug();
    a.debug();

    i1.update();
    a.debug();
    a.update();
    i1.debug();
}

void not_test() {
    Wire a, b;
    a.set_signal(0);
    a.update();
    a.debug();
    b.debug();
    NOT n(&a, &b);
    n.update();
    n.debug();
    a.debug();
    b.debug();
}

void or_test() {
    Wire a, b, c;
    a.set_signal(0);
    b.set_signal(1);
    a.debug();
    b.debug();
    c.debug();

    a.update();
    b.update();
    c.update();

    OR x1(&a, &b, &c);
    x1.update();
    x1.debug();

    a.debug();
    b.debug();
    c.debug();
    c.update();
    cout << "Végső output: " << c.get_signal() << endl;
}

void and_test() {
    Wire a, b, c;
    a.set_signal(1);
    b.set_signal(1);
    a.debug();
    b.debug();
    c.debug();

    a.update();
    b.update();
    c.update();

    AND x1(&a, &b, &c);
    x1.update();
    x1.debug();

    a.debug();
    b.debug();
    c.debug();
    c.update();
    cout << "Végső output: " << c.get_signal() << endl;
}

void print_test() {
    Wire a, b, c;
    a.set_signal(1);
    b.set_signal(2);
    c.set_signal(0);
    a.update();
    b.update();
    c.update();
    PRINT p(&b, "sajat_labelem");
    p.update();
}

void logic_network_test() {
    // valamiért beleír az indító parancsba
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;

    LogicNetwork network;
    network.add_component(new INP(network.get_wire(0), 1));
    network.add_component(new PRINT(network.get_wire(0)));
    network.bulk_update(4);
}