#ifndef LOGIC_NETWORK_CONFIGURER_H
#define LOGIC_NETWORK_CONFIGURER_H

#define DEBUG
#include <iostream>

#include "logic_network.h"
#include "memtrace.h"
class LogicNetworkConfigurer : public LogicNetwork {
    // TODO kell mindenféle copy konstruktor, stb

   public:
    // TODO nem biztos hogy ide kéne a wires_size, meg default argumentumok miatt ilyen sorrendben
    // alapvetően 0-ra állítja be a méretet, majd beáll amikor egy txt-ből beolvas
    LogicNetworkConfigurer(size_t wires_size = 0, std::ostream& os = std::cout) : LogicNetwork(wires_size, os) {}
    // TODO olyan függvények, amik ezeket wrappelik és txt-be írnak ki
    // beolvassa egy bemeneti streamről a hálózatot
    void read_logic_network(std::istream& is);
    // kiírja egy kimeneti streamre magát
    void write_logic_network(std::ostream& os);
};

#endif