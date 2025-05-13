/**
 * @file OR.h
 * @brief OR kaput megvalósító komponens
 */

#ifndef OR_H
#define OR_H
#include "../component.h"
#include "../memtrace.h"

class OR : public Component {
    static const char* name;
    // copy constructor és értékadó operátor letiltása
    // mert memóriahibát okozna, és nincs értelme ugyan azt a komponenst létrehozni
    // pontosan ugyan azt csinálná két ugyan oda kötött komponens, mint egy
    OR(const OR&);
    OR& operator=(const OR&);

   public:
    /**
     * @brief OR komponens konstruktora
     *
     * @param inpA Első bemenet
     * @param inpB Második bemenet
     * @param out Kimenet
     */
    OR(Wire* inpA, Wire* inpB, Wire* out);
    /**
     * @brief Kimeneti jel a bemeneteken végzett OR eredménye
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
