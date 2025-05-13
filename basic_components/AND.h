
#ifndef AND_H
#define AND_H

#include "../component.h"
#include "../memtrace.h"

class AND : public Component {
    static const char* name;
    // copy constructor és értékadó operátor letiltása
    // mert memóriahibát okozna, és nincs értelme ugyan azt a komponenst létrehozni
    // pontosan ugyan azt csinálná két ugyan oda kötött komponens, mint egy
    AND(const AND&);
    AND& operator=(const AND&);

   public:
   public:
    /**
     * @brief AND komponens konstruktora
     *
     * @param inpA Első bemenet
     * @param inpB Második bemenet
     * @param out Kimenet
     */
    AND(Wire* inpA, Wire* inpB, Wire* out);
    /**
     * @brief Kimeneti jel a bemeneteken végzett AND eredménye
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