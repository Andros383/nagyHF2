
/**
 * @file PRINT.h
 * @brief A kábel értéket kimenetre író komponens
 *
 */
#ifndef PRINT_H
#define PRINT_H

#include <iostream>

#include "../component.h"
#include "../memtrace.h"
class PRINT : public Component {
    static const char* name;
    std::ostream& os;
    char* label;

    // copy constructor és értékadó operátor letiltása
    // mert memóriahibát okozna, és nincs értelme ugyan azt a komponenst létrehozni
    // pontosan ugyan azt csinálná két ugyan oda kötött komponens, mint egy
    PRINT(const PRINT&);
    PRINT& operator=(const PRINT&);

   public:
    /**
     * @brief PRINT komponens konstruktora
     *
     * @param inpA Bemeneti kábel
     * @param label A címke, ami alapján meg lehet különböztetni a kimeneteket
     * @param os Az adatfolyam, amire a kimenetét írja
     */
    PRINT(Wire* inpA, const char* label = "unnamed_output", std::ostream& os = std::cout);
    /**
     * @brief Kiírja a bemeneti kábel értékét a megadott adatfolyamra
     *
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
    ~PRINT();
};

#endif