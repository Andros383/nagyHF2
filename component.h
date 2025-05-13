/**
 * @file component.h
 * @brief A komponensek absztrakt bázisosztálya
 */

#ifndef COMPONENT_H
#define COMPONENT_H
#include <iostream>

#include "memtrace.h"
#include "wire.h"

class Component {
    static const char* component_name;
    // a leszármazottak állítják be, hogy mik legyenek a be és kimenetek
   protected:
    Wire** inputs;
    Wire* output;

   public:
    Component() : inputs(nullptr), output(nullptr) {};
    /**
     * @brief Kaputól függően a frissítés elvégzése: \n Bementi jelekből a kimeneti jelek kiszámítása / egyéb műveletek végrehajtása
     *
     */
    virtual void update() = 0;
    /**
     * @brief Komponens kiírása a fájlba mentéshez
     *
     * @param base_address A logikai hálózat vezetékeket tároló tömbjének kezdőcíme
     * @param os A kimeneti adatfolyam, amire a kapu kiírja magát
     */
    virtual void write(Wire* base_address, std::ostream& os = std::cout) = 0;
    virtual ~Component();
};
#endif