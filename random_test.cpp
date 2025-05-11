// // TODO mindenhova kell a rohadt debug?
// // buta lsp
// #define DEBUG
// #include <fstream>
// #include <iostream>

// #include "basic_components.h"
// #include "logic_network.h"
// #include "logic_network_configurer.h"
// #include "memtrace.h"
// #include "wire.h"

// using std::cout;
// using std::endl;

// // Itt találhatóak azok a tesztek amiket futtattam a kód írása közben, hogy működik-e
// // Nem teljesen normális tesztek, mert csak kipróbálgattam ami eszembe jut
// void wire_test() {
//     Wire w1 = Wire();
//     w1.debug();
//     w1.set_signal(1);
//     w1.debug();
//     cout << "Signal get " << w1.get_signal() << endl;
//     w1.update();
//     w1.debug();
//     cout << "Signal get " << w1.get_signal() << endl;
// }
// void XOR_test() {
//     Wire a, b, c;
//     a.set_signal(1);
//     b.set_signal(0);
//     a.debug();
//     b.debug();
//     c.debug();

//     a.update();
//     b.update();
//     c.update();

//     XOR x1(&a, &b, &c);
//     x1.update();
//     x1.debug();

//     a.debug();
//     b.debug();
//     c.debug();
// }

// void inp_test() {
//     Wire a;
//     INP i1(&a, 1);
//     i1.debug();
//     a.debug();

//     i1.update();
//     a.debug();
//     a.update();
//     i1.debug();
// }

// void not_test() {
//     Wire a, b;
//     a.set_signal(0);
//     a.update();
//     a.debug();
//     b.debug();
//     NOT n(&a, &b);
//     n.update();
//     n.debug();
//     a.debug();
//     b.debug();
// }

// void or_test() {
//     Wire a, b, c;
//     a.set_signal(0);
//     b.set_signal(1);
//     a.debug();
//     b.debug();
//     c.debug();

//     a.update();
//     b.update();
//     c.update();

//     OR x1(&a, &b, &c);
//     x1.update();
//     x1.debug();

//     a.debug();
//     b.debug();
//     c.debug();
//     c.update();
//     cout << "Végső output: " << c.get_signal() << endl;
// }

// void and_test() {
//     Wire a, b, c;
//     a.set_signal(1);
//     b.set_signal(1);
//     a.debug();
//     b.debug();
//     c.debug();

//     a.update();
//     b.update();
//     c.update();

//     AND x1(&a, &b, &c);
//     x1.update();
//     x1.debug();

//     a.debug();
//     b.debug();
//     c.debug();
//     c.update();
//     cout << "Végső output: " << c.get_signal() << endl;
// }

// void print_test() {
//     Wire a, b, c;
//     a.set_signal(1);
//     b.set_signal(2);
//     c.set_signal(0);
//     a.update();
//     b.update();
//     c.update();
//     PRINT p(&b, "sajat_labelem");
//     p.update();
// }

// void logic_network_test() {
//     // valamiért beleír az indító parancsba
//     cout << endl;
//     cout << endl;
//     cout << endl;
//     cout << endl;

//     LogicNetwork network(10);
//     network.add_component(new INP(network.get_wire(0), 1));
//     network.add_component(new PRINT(network.get_wire(0)));
//     network.bulk_update(4);
// }

// void write_trait_test() {
//     // valamiért beleír az indító parancsba
//     cout << endl;
//     cout << endl;
//     cout << endl;
//     cout << endl;

//     Wire* wires = new Wire[3];
//     XOR x(&wires[0], &wires[1], &wires[2]);
//     x.write(wires);
//     delete[] wires;
// }
// void lnc_read_write_test() {
//     LogicNetworkConfigurer ln;
//     std::ifstream f("test_input.txt");
//     ln.read_logic_network(f);
//     f.close();

//     std::ofstream o("test_output.txt");
//     ln.write_logic_network(o);
//     ln.bulk_update(2);
// }

// void input_test() {
//     cout << endl;
//     cout << endl;
//     cout << endl;
//     cout << endl;
//     LogicNetwork n(100);
//     n.add_component(new STD_INP(n.get_wire(0), "A"));
//     n.add_component(new STD_INP(n.get_wire(1), "B"));
//     n.add_component(new XOR(n.get_wire(0), n.get_wire(1), n.get_wire(2)));
//     n.add_component(new PRINT(n.get_wire(2), "XOR"));

//     n.add_component(new OR(n.get_wire(0), n.get_wire(1), n.get_wire(3)));
//     n.add_component(new PRINT(n.get_wire(3), "OR"));

//     n.add_component(new AND(n.get_wire(0), n.get_wire(1), n.get_wire(4)));
//     n.add_component(new PRINT(n.get_wire(4), "AND"));

//     n.add_component(new NOT(n.get_wire(0), n.get_wire(5)));
//     n.add_component(new PRINT(n.get_wire(5), "NOT_A"));

//     n.bulk_update(3);
// }