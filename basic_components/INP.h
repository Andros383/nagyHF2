/**
 * @file INP.h
 * @brief Kábelre konstans értéket író komponens
 */
#ifndef INP_H
#define INP_H

#include "../component.h"
#include "../memtrace.h"

class INP : public Component {
    static const char* name;
    int signal;
    // copy constructor és értékadó operátor letiltása
    // mert memóriahibát okozna, és nincs értelme ugyan azt a komponenst létrehozni
    // pontosan ugyan azt csinálná két ugyan oda kötött komponens, mint egy
    INP(const INP&);
    INP& operator=(const INP&);

   public:
    /**
     * @brief INP komponens konstruktora
     *
     * @param out Kimenet
     */
    INP(Wire* out, int signal);
    /**
     * @brief A belső jelet kirakja a kimeneti kábelre
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