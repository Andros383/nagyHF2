#define DEBUG
#include "logic_network_configurer.h"

#include <fstream>

#include "basic_components.h"
#include "memtrace.h"

// segédfüggvény
// beolvassa innentől a sor/stream végéig a karaktereket a megadott pointerbe
// utána a hívónak fel kell szabadítania a pointert
void read_label(std::istream& is, char** buffer) {
    char* label = new char[1];
    label[0] = '\0';
    size_t size = 0;
    while (true) {
        char c = is.get();
        // ha a sor / stream vége van, kilép, visszaadja az értéket
        if (c == '\n' || is.eof()) break;
        size++;

        char* new_label = new char[size + 1];

        strcpy(new_label, label);

        delete[] label;

        label = new_label;
        label[size - 1] = c;
        label[size] = '\0';
    }
    *buffer = label;
}

void LogicNetworkConfigurer::read_logic_network(std::istream& is) {
    // előző adatok törlése
    delete[] wires;

    for (size_t i = 0; i < components_size; i++) {
        delete components[i];
    }

    delete[] components;

    size_t wires_cnt;
    is >> wires_cnt;

    wires_size = wires_cnt;
    wires = new Wire[wires_size];
    components_size = 0;
    components = nullptr;

    // minden komponenst egyesével a végére fűzzük a hálózatnak
    size_t components_cnt;
    is >> components_cnt;

    if (!is.good())
        throw "Hiba a komponensek és kábelek számának beolvasásakor";
    for (size_t i = 0; i < components_cnt; i++) {
        char gate_name[101];
        is >> gate_name;
        if (strcmp(gate_name, AND::get_name()) == 0) {
            size_t ina, inb, out;
            is >> ina >> inb >> out;
            this->add_component(new AND(this->get_wire(ina), this->get_wire(inb), this->get_wire(out)));
        } else if (strcmp(gate_name, OR::get_name()) == 0) {
            size_t ina, inb, out;
            is >> ina >> inb >> out;
            this->add_component(new OR(this->get_wire(ina), this->get_wire(inb), this->get_wire(out)));
        } else if (strcmp(gate_name, XOR::get_name()) == 0) {
            size_t ina, inb, out;
            is >> ina >> inb >> out;
            this->add_component(new XOR(this->get_wire(ina), this->get_wire(inb), this->get_wire(out)));
        } else if (strcmp(gate_name, NOT::get_name()) == 0) {
            size_t in, out;
            is >> in >> out;
            this->add_component(new NOT(this->get_wire(in), this->get_wire(out)));
        } else if (strcmp(gate_name, INP::get_name()) == 0) {
            size_t out;
            int val;
            is >> out >> val;
            this->add_component(new INP(this->get_wire(out), val));
        } else if (strcmp(gate_name, STD_INP::get_name()) == 0) {
            size_t out;
            is >> out;
            char* label;
            // space beolvasása a szám után
            is.get();
            read_label(is, &label);
            this->add_component(new STD_INP(this->get_wire(out), label));
            delete[] label;
        } else if (strcmp(gate_name, PRINT::get_name()) == 0) {
            size_t in;
            is >> in;
            char* label;
            // space beolvasása a szám után
            is.get();
            read_label(is, &label);
            this->add_component(new PRINT(this->get_wire(in), label, os));
            delete[] label;
        }
        if (!is.good()) {
            if (i == components_cnt - 1)
                throw "Hiba az utolso komponens beolvasasanal, lemaradt a sorvege jel?";
            else
                throw "Hiba a beolvasas kozben";
        }
        // ez szól ha túl hamar van vége / nem jó formátumút olvas be
    }
}

void LogicNetworkConfigurer::write_logic_network(std::ostream& os) {
    os << wires_size << " " << components_size << '\n';
    for (size_t i = 0; i < components_size; i++) {
        components[i]->write(wires, os);
        os << '\n';
    }
}