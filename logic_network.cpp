#include "logic_network.h"

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
        os << " --- Update " << i + 1 << " ---" << std::endl;
        this->update();
        os << std::endl;
    }
}
Wire* LogicNetwork::get_wire(size_t wire_id) {
    if (wire_id >= wires_size) {
        throw "Nincs elég kábel!";
    }
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

void LogicNetwork::remove_component(size_t index) {
    if (index >= components_size) throw "Törlési index határon kívül";

    Component** new_components = new Component*[components_size - 1];
    size_t ujindex = 0;
    for (size_t i = 0; i < components_size; i++) {
        if (i == index) {
            delete components[i];
        } else {
            new_components[ujindex] = components[i];
            ujindex++;
        }
    }
    components_size--;

    // nem kell törölni az elemeket
    delete[] components;
    components = new_components;
}
void LogicNetwork::remove_component(Component* component) {
    int remove_index = -1;
    for (size_t i = 0; i < components_size; i++) {
        if (components[i] == component) {
            remove_index = i;
            break;
        }
    }
    if (remove_index == -1) {
        throw "Nincs ilyen komponens a hálózatban";
    }
    this->remove_component(remove_index);
}

LogicNetwork::~LogicNetwork() {
    delete[] wires;

    for (size_t i = 0; i < components_size; i++) {
        delete components[i];
    }

    delete[] components;
}