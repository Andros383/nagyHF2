/**
 * @file logic_network_configurer.h
 * @brief Fájlba menthető és fájlból beolvasható logikai hálózat osztály
 */
#ifndef LOGIC_NETWORK_CONFIGURER_H
#define LOGIC_NETWORK_CONFIGURER_H

#include <iostream>

#include "logic_network.h"
#include "memtrace.h"
class LogicNetworkConfigurer : public LogicNetwork {
   public:
    LogicNetworkConfigurer(size_t wires_size = 0, std::ostream& os = std::cout) : LogicNetwork(wires_size, os) {}
    /**
     * @brief Beolvassa a kapott bemeneti adatfolyamról a hálózatot
     *
     * @throw const_char* A különböző hibaeseteket leíró cstringet dob, ha nem sikerült a beolvasás.
     *
     * @param is A bemeneti adatfolyam
     */
    void read_logic_network(std::istream& is);
    /**
     * @brief Kiírja egy kimeneti adatfolyamra a hálózatot
     *
     * @param os A kimeneti adatfolyam
     */
    void write_logic_network(std::ostream& os);
};

#endif