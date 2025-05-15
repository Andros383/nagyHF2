#define DEBUG
#include "logic_network_configurer.h"

#include <cstring>
#include <fstream>
#include <sstream>

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
        if (c == '\n' || c == '\r' || is.eof()) break;
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

// template típusonként
// különböző konstruktorok miatt nem lehet egy fügvénnyel megoldani, példányosodásnál hibát dobna akkor is, ha nem arról a típusról van szó

// AND, OR, XOR
template <typename GenericComponent>
void read_3_wire_component(const char* name, std::istream& is, LogicNetworkConfigurer& lnc) {
    if (strcmp(name, GenericComponent::get_name()) != 0) return;
    size_t ina, inb, out;
    is >> ina >> inb >> out;
    lnc.add_component(new GenericComponent(lnc.get_wire(ina), lnc.get_wire(inb), lnc.get_wire(out)));
}

// NOT
template <typename GenericComponent>
void read_2_wire_component(const char* name, std::istream& is, LogicNetworkConfigurer& lnc) {
    if (strcmp(name, GenericComponent::get_name()) != 0) return;
    size_t in, out;
    is >> in >> out;
    lnc.add_component(new NOT(lnc.get_wire(in), lnc.get_wire(out)));
}

// INP
template <typename GenericComponent>
void read_1_wire_1_int_component(const char* name, std::istream& is, LogicNetworkConfigurer& lnc) {
    if (strcmp(name, GenericComponent::get_name()) != 0) return;
    size_t out;
    int val;
    is >> out >> val;
    lnc.add_component(new GenericComponent(lnc.get_wire(out), val));
}

// STD_INP
template <typename GenericComponent>
void read_1_wire_1_label_component(const char* name, std::istream& is, LogicNetworkConfigurer& lnc) {
    if (strcmp(name, GenericComponent::get_name()) != 0) return;
    size_t out;
    is >> out;
    char* label;
    // space beolvasása a szám után
    is.get();
    read_label(is, &label);
    lnc.add_component(new GenericComponent(lnc.get_wire(out), label));
    delete[] label;
}

// PRINT
template <typename GenericComponent>
void read_1_wire_1_label_1_stream_component(const char* name, std::istream& is, LogicNetworkConfigurer& lnc) {
    if (strcmp(name, GenericComponent::get_name()) != 0) return;
    size_t in;
    is >> in;
    char* label;
    // space beolvasása a szám után
    is.get();
    read_label(is, &label);
    lnc.add_component(new GenericComponent(lnc.get_wire(in), label, lnc.get_os()));
    delete[] label;
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

        // kapuk bemenet típusonként bontva
        read_3_wire_component<AND>(gate_name, is, *this);
        read_3_wire_component<OR>(gate_name, is, *this);
        read_3_wire_component<XOR>(gate_name, is, *this);
        read_2_wire_component<NOT>(gate_name, is, *this);
        read_1_wire_1_int_component<INP>(gate_name, is, *this);
        read_1_wire_1_label_component<STD_INP>(gate_name, is, *this);
        read_1_wire_1_label_1_stream_component<PRINT>(gate_name, is, *this);

        if (!is.good()) {
            if (i == components_cnt - 1)
                throw "Hiba az utolso komponens beolvasasanal, lemaradt a sorvege jel?";
            else
                throw "Hiba a beolvasas kozben";
        }
        // ez szól ha túl hamar van vége / nem jó formátumút olvas be
    }
}

void LogicNetworkConfigurer::write_logic_network(std::ostream& os) const {
    os << wires_size << " " << components_size << '\n';
    for (size_t i = 0; i < components_size; i++) {
        components[i]->write(wires, os);
        os << '\n';
    }
}

// nem a legszebb, de valójában ugyan ezt csinálná a másik megoldás is
// az egyes komponenseknek minden információt ki kell adni magukból
// ez lehetne egy függvény, csak akkor a visszatérési érték nagyon bonyolult lenne, leszármazottanként változna
// vagy felveszi saját maga másolatát az új hálózatra, de az a megoldás se szép, mert az új hálózat létrehozás felelőssége a komponensekre hárul
// egyértelműen nem lehet klónozni, mert mutatókat használ
LogicNetworkConfigurer::LogicNetworkConfigurer(const LogicNetworkConfigurer& rhs) : LogicNetwork(0, rhs.os) {
    std::stringstream temp;
    rhs.write_logic_network(temp);
    this->read_logic_network(temp);
}
LogicNetworkConfigurer& LogicNetworkConfigurer::operator=(const LogicNetworkConfigurer& rhs) {
    if (this != &rhs) {
        std::stringstream temp;
        rhs.write_logic_network(temp);
        this->read_logic_network(temp);
        // a streamet direkt nem másolja át, így hasznosabb
        // meg amúgy nem is lehetne, csak valami okosmutatókkal
    }
    return *this;
}