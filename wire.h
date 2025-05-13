/**
 * @file wire.h
 * @brief Vezetéket megvalósító osztály
 */
#ifndef WIRE_H
#define WIRE_H
#include <iostream>

#include "memtrace.h"
class Wire {
    int input;
    int output;

   public:
    Wire() : input(0), output(0) {}
    /**
     * @brief A vezeték elejéről a végére rakja a jelet, elejét 0-ra állítja
     *
     */
    void update();
    /**
     * @brief Beállítja a bemenetén a jelet, a kapott és a már ott lévő érték közül a nagyobbra.
     *
     * @param signal
     */
    void set_signal(int signal);
    /**
     * @brief Visszaadja a kimenetén lévő jelet
     *
     * @return int
     */
    int get_signal() const {
        return output;
    }
};

#endif