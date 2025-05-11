#ifndef COMPONENT_H
#define COMPONENT_H
#include <iostream>

#include "memtrace.h"
#include "wire.h"

class Component {
    static const char* component_name;
    // a gyerekek állítják be, hogy mik legyenek a be és kimenetek
    // szerintem így jobb, mintha függvénnyel lenne
   protected:
    Wire** inputs;
    Wire* output;

   public:
    // NOTE nem konst sehol sem, mert lehessen olyat, aminek van belső állapota
    Component() : inputs(nullptr), output(nullptr) {};
    // minden leszármazottnak egymástól független, de explicit megkövetelt update függvénye
    // ez felel azért, hogy frissítéskor elvégezzék a dolgaikat
    virtual void update() = 0;
    // ez a fájlba mentés módja, kiírja magát a kapu a megfelelő formátumban
    // nem akartam külön osztályokat létrehozni / származtatni őket,
    // mert akkor a LogicNetworkConfigurer nem tartalmazhatja a LogicNetwork-ot, mert
    // akkor kiírható komponenseket kéne tartalmaznia, nem sima komponenseket, szóval minden osztályból csak kettő lenne
    // base_address: a kezdőcíme a kábelek tömbjének, hogy ez alapján ki tudják írni hanyas wire-on csatlakoznak egy-egy bemeneten
    virtual void write(Wire* base_address, std::ostream& os = std::cout) = 0;
    virtual ~Component();
};
#endif