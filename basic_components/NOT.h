/**
 * @file NOT.h
 * @brief NOT kaput megvalósító komponens
 */
#ifndef NOT_H
#define NOT_H

#include "../component.h"
#include "../memtrace.h"

class NOT : public Component {
    static const char* name;

    // copy constructor és értékadó operátor letiltása
    // mert memóriahibát okozna, és nincs értelme ugyan azt a komponenst létrehozni
    // pontosan ugyan azt csinálná két ugyan oda kötött komponens, mint egy
    NOT(const NOT&);
    NOT& operator=(const NOT&);

   public:
    /**
     * @brief NOT komponens konstruktora
     *
     * @param inpA Bemenet
     * @param out Kimenet
     */
    NOT(Wire* inpA, Wire* out);
    /**
     * @brief Kimeneti jel a bemeneten végzett NOT eredménye
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