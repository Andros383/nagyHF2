#include "component.h"

#include <iostream>
#define DEBUG

#include "memtrace.h"

// magát az inputs pointert törli, amikre mutat, azt nem
Component::~Component() {
    delete[] inputs;
}