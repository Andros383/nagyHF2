/**
 * @file logic_network.h
 * @brief Logikai hálózatot megvalósító osztály. Eltárolja a neki átadott komponenseket, használat után törli azokat.
 */
#ifndef LOGIC_NETWORK_H
#define LOGIC_NETWORK_H
#include <iostream>

#include "component.h"
#include "memtrace.h"
#include "wire.h"
class LogicNetwork {
   protected:
    Wire* wires;
    size_t wires_size;

    Component** components;
    size_t components_size;
    // protecteden, mert nem kell tudnia a felhasználónak, hogy mennyi van a komponensekből, meg hogy mik azok
    // viszont ki szeretném írni

    std::ostream& os;

    // ne lehessen lemásolni, mert nehéz?
    LogicNetwork(const LogicNetwork&);
    LogicNetwork& operator=(const LogicNetwork&);

   public:
    /**
     * @brief Logikai hálózat konstruktora
     *
     * @param wires_size A hálózatban lévő kábelek maximális száma
     * @param os Az adatfolyam, ahova a frissítéseket elválasztó üzeneteket írja
     */
    LogicNetwork(size_t wires_size, std::ostream& os = std::cout);
    /**
     * @brief A hálózat elemeinek frissítése: először kábelek, majd komponensek sorrendben
     */
    void update();
    /**
     * @brief Egyszerre több frissítés futtatása. Kiírja az egyes frissítések kezdetét az adatfolyamra.
     *
     * @param update_count A frissítések száma
     */
    void bulk_update(size_t update_count);

    /**
     * @brief Visszaad egy mutatót az eltárolt vezetékekre sorszám alapján
     *
     * @throw const_char* Ha nincsen wire_id számú kábel, "Nincs elég kábel!" kivételt dob
     *
     * @param wire_id Vezeték sorszáma
     * @return Wire*
     */
    Wire* get_wire(size_t wire_id);
    /**
     * @brief Hozzáad egy komponenst a hálózathoz. A komponenst a hálózat fogja felszabadítani.
     *
     * @param component Az új komponens mutatóval, amit hozzáad
     */
    void add_component(Component* component);

    /**
     * @brief Kitöröl egy komponenst a hálózatból a sorszáma alapján. A törlés felszabadítja a memóriát.
     *
     * @param index Az törlendő komponens belső sorszáma
     * @throw const_char* Hibát dob, ha nincs ilyen komponens
     */
    void remove_component(size_t index);
    /**
     * @brief Kitöröl egy komponenst a hálózatból a mutatója alapján. A törlés felszabadítja a memóriát. Ha nem találta, nem szabadítja fel.
     *
     * @param index Mutató a törlendő komponensre
     * @throw const_char* Hibát dob, ha nincs ilyen komponens
     */
    void remove_component(Component* component);

    /**
     * @brief Visszaadja a kimeneti adatfolyamot, amire a frissítések kezdetét jelző szöveget írja ki
     *
     * @return std::ostream&
     */
    std::ostream& get_os() { return os; }
    virtual ~LogicNetwork();
};
#endif