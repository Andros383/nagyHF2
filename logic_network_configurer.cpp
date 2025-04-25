#define DEBUG
#include "logic_network_configurer.h"

#include <fstream>

#include "basic_components.h"
#include "memtrace.h"
// TODO write és read a >> helyett, hogy ne legyen a \n\r-el baj!!!

void LogicNetworkConfigurer::read_logic_network(std::istream& is) {
    // minden komponenst egyesével a végére fűzzük a hálózatnak
    size_t components_size;
    is >> components_size;
    for (size_t i = 0; i < components_size; i++) {
        char* gate_name = new char[100];
        is >> gate_name;
        // sajnos szerintem így a legjobb megoldani?
        // a fájlformátumból adódóan nem tudja magát beolvasni egy-egy komponens
        // Ha nem így csinálnám, minden kapunak lenne egy párja, ami a beolvasást intézi
        // azaz lenne egy read függvénye, ami elkéri a networkot, lekéri a pointereket magának, és felirakozik rájuk
        // ez van ha az ember pointerekkel dolgozik...
        // csomó if mert nem fogok elifezni, és strcmp-vel vel nem lehet switchelni char*-ot
        if (strcmp(gate_name, "AND") == 0) {
            size_t ina, inb, out;
            is >> ina >> inb >> out;
            this->add_component(new AND(this->get_wire(ina), this->get_wire(inb), this->get_wire(inb)));
        }
        if (strcmp(gate_name, "OR") == 0) {
            size_t ina, inb, out;
            is >> ina >> inb >> out;
            this->add_component(new OR(this->get_wire(ina), this->get_wire(inb), this->get_wire(inb)));
        }
        if (strcmp(gate_name, "XOR") == 0) {
            size_t ina, inb, out;
            is >> ina >> inb >> out;
            this->add_component(new XOR(this->get_wire(ina), this->get_wire(inb), this->get_wire(inb)));
        }
        if (strcmp(gate_name, "NOT") == 0) {
            size_t in, out;
            is >> in >> out;
            this->add_component(new NOT(this->get_wire(in), this->get_wire(out)));
        }
        if (strcmp(gate_name, "INP") == 0) {
            size_t out;
            int val;
            is >> out >> val;
            this->add_component(new INP(this->get_wire(out), val));
        }
        if (strcmp(gate_name, "PRINT") == 0) {
            // TODO ha txt akkor kötelező a label?
            size_t in;
            // TODO bufferknek normál méret
            char* label = new char[100];
            is >> in >> label;
            this->add_component(new PRINT(this->get_wire(in), label));
        }
    }

    // is close-ja nem az ő feladata
}

void LogicNetworkConfigurer::write_logic_network(std::ostream& os) {
    os << components_size;
    os << '\n';
    for (size_t i = 0; i < components_size; i++) {
        os << components[i]->get_name();
        // pointeraritmetikával a
    }
}