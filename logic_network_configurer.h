#ifndef LOGIC_NETWORK_CONFIGURER_H
#define LOGIC_NETWORK_CONFIGURER_H

#define DEBUG
#include <iostream>

#include "logic_network.h"
#include "memtrace.h"
class LogicNetworkConfigurer : public LogicNetwork {
    // TODO kell mindenféle copy konstruktor, stb

   public:
    // TODO olyan függvények, amik ezeket wrappelik és txt-be írnak ki
    void read_logic_network(std::istream& is);
    void write_logic_network(std::ostream& os);
};

#endif