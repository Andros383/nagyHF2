#define DEBUG
#include "logic_network.h"
#define DEBUG

#include "memtrace.h"
LogicNetwork::LogicNetwork(size_t wires_size, std::ostream& os) : wires(nullptr), wires_size(wires_size), components(nullptr), components_size(0), os(os) {
    // le kell foglalni előre, mert másolásnál nem lehet valid
    wires = new Wire[wires_size];
}

void LogicNetwork::update() {
    for (size_t i = 0; i < wires_size; i++) {
        wires[i].update();
    }
    for (size_t i = 0; i < components_size; i++) {
        components[i]->update();
    }
}
void LogicNetwork::bulk_update(size_t update_count) {
    for (size_t i = 0; i < update_count; i++) {
        os << "Update " << i << std::endl;
        this->update();
        os << std::endl;
    }
}
Wire* LogicNetwork::get_wire(size_t wire_id) {
    if (wires_size <= wire_id) {
        Wire* new_wires = new Wire[wire_id + 1];
        // elméletben mivel van defa konstruktor nem UB ha átindexelek 10-re, utána pedig a 9-est kérem le
        // TODO ellenőrizni
        for (size_t i = 0; i < wires_size; i++) {
            new_wires[i] = wires[i];
        }
        delete[] wires;
        wires = new_wires;
        wires_size = wire_id + 1;
    }
    // létrejött, visszaadható
    // wires + wire_id
    return &wires[wire_id];
}
void LogicNetwork::add_component(Component* new_component) {
    Component** new_components = new Component*[components_size + 1];
    for (size_t i = 0; i < components_size; i++) {
        new_components[i] = components[i];
    }
    new_components[components_size] = new_component;
    components_size++;

    // nem kell törölni az elemeket
    delete[] components;
    components = new_components;
}
LogicNetwork::~LogicNetwork() {
    delete[] wires;

    for (size_t i = 0; i < components_size; i++) {
        delete components[i];
    }

    delete[] components;
}