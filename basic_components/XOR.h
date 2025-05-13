/**
 * @file XOR.h
 * @brief XOR kaput megvalósító komponens
 */
#ifndef XOR_H
#define XOR_H

#include "../component.h"
#include "../memtrace.h"

class XOR : public Component {
    static const char* name;

    // copy constructor és értékadó operátor letiltása
    // mert memóriahibát okozna, és nincs értelme ugyan azt a komponenst létrehozni
    // pontosan ugyan azt csinálná két ugyan oda kötött komponens, mint egy
    XOR(const XOR&);
    XOR& operator=(const XOR&);

   public:
    /**
     * @brief XOR komponens konstruktora
     *
     * @param inpA Első bemenet
     * @param inpB Második bemenet
     * @param out Kimenet
     */
    XOR(Wire* inpA, Wire* inpB, Wire* out);
    /**
     * @brief Kimeneti jel a bemeneteken végzett XOR eredménye
     */
    void update();
    void write(Wire* base_address, std::ostream& os = std::cout);
    /**
     * @brief Visszaadja a komponens elmentésekor használt nevet
     *
     * @return A komponens neve
     */
    static const char* get_name() {
        return name;
    }
};

#endif