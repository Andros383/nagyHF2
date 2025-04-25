#ifndef SERIALIZED_COMPONENT_H
#define SERIALIZED_COMPONENT_H
#include <iostream>

#include "memtrace.h"
#include "wire.h"
class SerializedComponent {
   public:
    // csak a kiíratásért felel
    // kap egy Wire* pointert, az alapján ki tudja írni hogy hanyadik wire-t kapta meg
    virtual void write(std::ostream& os, Wire* base_address) = 0;
};
#endif