#ifndef LOGIC_NETWORK_H
#define LOGIC_NETWORK_H
#include <iostream>

#include "component.h"
#include "memtrace.h"
#include "wire.h"
class LogicNetwork {
    // ne lehessen lemásolni, mert nincs sok értelme
    // és lehetetlen lenne lemásolni a mutatók miatt, valójában kirakná egy streamre és visszaolvasná
    // automatikusan a configurert se lehet lemásolni
    LogicNetwork(const LogicNetwork&);
    LogicNetwork& operator=(const LogicNetwork&);

   protected:
    // UML-ben frissíteni, ez wire tömböt tárol, nem Wire*[]-t
    // mert asszem végül nem lehet felüldefelni a wire-t?
    Wire* wires;
    size_t wires_size;

    Component** components;
    size_t components_size;
    // protecteden, mert nem kell tudnia a felhasználónak, hogy mennyi van a komponensekből, meg hogy mik azok
    // viszont ki szeretném írni

    std::ostream& os;

   public:
    // létrehozáskor meg kell adni a kábelek számát, hogy rá lehessen kötni a kapukat
    LogicNetwork(size_t wires_size, std::ostream& os = std::cout);
    // lefrissíti először a wireokat, utána a komponenseket
    void update();
    // egyszerre több frissítést futtat
    void bulk_update(size_t update_count);
    // visszaad egy wire-t manuális kötéshez
    // ha nincs elég wire, akkor hibát dob
    Wire* get_wire(size_t wire_id);
    // hozzáad egy komponenst mutatója alapján a hálózathoz
    void add_component(Component* component);

    // visszaadja a streamet amire kiír
    std::ostream& get_os() { return os; }
    virtual ~LogicNetwork();
};
#endif