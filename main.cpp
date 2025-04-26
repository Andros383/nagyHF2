// TODO kivenni
#define DEBUG
#include <fstream>
#include <iostream>

#include "basic_components.h"
#include "fstream"
#include "logic_network.h"
#include "logic_network_configurer.h"
#include "memtrace.h"
#include "wire.h"
using std::cout;
using std::endl;
void asd(std::ostream& os) {
    os << "teszt" << std::endl;
}
void manual_koteses_test() {
    Wire a, b, c;
    INP inp_a(&a, 0);
    INP inp_b(&b, 1);
    XOR xor_gate(&a, &b, &c);
    PRINT print_component(&c, "Output");

    // bemenetek a wire-re kirakják a jelet
    inp_a.update();
    inp_b.update();
    // a wire-ok átviszik a jelet
    a.update();
    b.update();
    // a xor kapu leolvassa, és kirakja a jelet
    xor_gate.update();
    // a kimeneti wire átviszi a jelet
    c.update();
    // a print leveszi, majd kiírja a jelet
    print_component.update();
}
void halozat_teszt() {
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    LogicNetwork n(100);
    n.add_component(new STD_INP(n.get_wire(0), "A"));
    n.add_component(new STD_INP(n.get_wire(1), "B"));
    n.add_component(new XOR(n.get_wire(0), n.get_wire(1), n.get_wire(2)));
    n.add_component(new PRINT(n.get_wire(2), "XOR"));

    n.add_component(new OR(n.get_wire(0), n.get_wire(1), n.get_wire(3)));
    n.add_component(new PRINT(n.get_wire(3), "OR"));

    n.add_component(new AND(n.get_wire(0), n.get_wire(1), n.get_wire(4)));
    n.add_component(new PRINT(n.get_wire(4), "AND"));

    n.add_component(new NOT(n.get_wire(0), n.get_wire(5)));
    n.add_component(new PRINT(n.get_wire(5), "NOT_A"));

    n.bulk_update(3);
}
void txt_betoltes_mentes_test() {
    /* test_input.txt
    40 12
    STD_INP 0 A
    STD_INP 1 B
    PRINT 0 A
    PRINT 1 B
    XOR 0 1 2
    PRINT 2 XOR
    OR 0 1 3
    PRINT 3 OR
    AND 0 1 4
    PRINT 4 AND
    NOT 0 5
    PRINT 5 NOT_A
    */
    // betölt egy konfigurációt amit utána futtat, és vissza is ment
    cout << endl;
    cout << endl;
    cout << endl;

    LogicNetworkConfigurer ln;
    std::ifstream f("test_input.txt");

    ln.read_logic_network(f);
    f.close();

    std::ofstream o("test_output.txt");
    ln.write_logic_network(o);

    o.close();

    ln.bulk_update(3);
}
void manualisan_letrehozott_lementese() {
    // a sima hálózat teszt csak átírva logikai hálózatra
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    LogicNetworkConfigurer lnc(100);
    lnc.add_component(new STD_INP(lnc.get_wire(0), "A"));
    lnc.add_component(new STD_INP(lnc.get_wire(1), "B"));
    lnc.add_component(new XOR(lnc.get_wire(0), lnc.get_wire(1), lnc.get_wire(2)));
    lnc.add_component(new PRINT(lnc.get_wire(2), "XOR"));

    lnc.add_component(new OR(lnc.get_wire(0), lnc.get_wire(1), lnc.get_wire(3)));
    lnc.add_component(new PRINT(lnc.get_wire(3), "OR"));

    lnc.add_component(new AND(lnc.get_wire(0), lnc.get_wire(1), lnc.get_wire(4)));
    lnc.add_component(new PRINT(lnc.get_wire(4), "AND"));

    lnc.add_component(new NOT(lnc.get_wire(0), lnc.get_wire(5)));
    lnc.add_component(new PRINT(lnc.get_wire(5), "NOT_A"));

    lnc.bulk_update(3);

    std::ofstream of("lnc_output.txt");

    lnc.write_logic_network(of);

    of.close();
}
int main() {
    // mindenféle tesztek, használati módok a fenti függvényekben vannak
    // egyéb tesztek a random_test.cpp-ben (nem érdekes)
    return 0;
}