/**
 * @file STD_INP.h
 * @brief Olyan INP komponens, aminek az értékét a standard bemeneten lehet megadni
 */

#ifndef STD_INP_H
#define STD_INP_H

#include "../component.h"
#include "../memtrace.h"

// mindig a standard bemenetről olvassa be, hogy mit adjon ki
class STD_INP : public Component {
    static const char* name;
    int signal;
    bool is_signal_set;
    char* label;

    // copy constructor és értékadó operátor letiltása
    // mert memóriahibát okozna, és nincs értelme ugyan azt a komponenst létrehozni
    // pontosan ugyan azt csinálná két ugyan oda kötött komponens, mint egy
    STD_INP(const STD_INP&);
    STD_INP& operator=(const STD_INP&);

   public:
    /**
     * @brief STD_INP komponens konstruktora
     *
     * @param out Kimenet
     * @param label A bemenetek megkülönböztetésére használt címke
     */
    STD_INP(Wire* out, const char* label = "Nem elnevezett bemenet");
    /**
     * @brief Első frissítéskor elkéri, hogy mit rakjon a kimenetre. Ez után ilyen értékű INP kapuként működik
     * @throw const_char* Első frissítésnél "Hibás bemenet egy STD_INP kapunak" kivételt dob, ha a kapott érték nem 0 vagy 1
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
    ~STD_INP();
};

#endif