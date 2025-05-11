#ifndef LOGIC_NETWORK_CONFIGURER_H
#define LOGIC_NETWORK_CONFIGURER_H

#include <iostream>

#include "logic_network.h"
#include "memtrace.h"
class LogicNetworkConfigurer : public LogicNetwork {
   public:
    LogicNetworkConfigurer(size_t wires_size = 0, std::ostream& os = std::cout) : LogicNetwork(wires_size, os) {}
    // beolvassa egy bemeneti streamről a hálózatot
    void read_logic_network(std::istream& is);
    // kiírja egy kimeneti streamre a hálózatot
    void write_logic_network(std::ostream& os);

};

#endif