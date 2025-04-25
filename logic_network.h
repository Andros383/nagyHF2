#include <iostream>

#include "component.h"
#include "memtrace.h"
#include "wire.h"
#define DEBUG
class LogicNetwork {
    // lehet privátan kéne? majd átírom, ha igen
    // kiíratás miatt
    // lehetne mindent függvénybe adni, csak az tök felesleges
   protected:
    // UML-ben frissíteni, ez wire tömböt tárol, nem Wire*[]-t
    // mert asszem végül nem lehet felüldefelni a wire-t?
    Wire* wires;
    size_t wires_size;
    // ide kell a **, mert heterogén kollekció
    // ezeket is birtokolja, törli ha törlődik
    Component** components;
    size_t components_size;
    std::ostream& os;

    // protecteden, mert nem kell tudnia a felhasználónak, hogy mennyi van a komponensekből, meg hogy mik azok
    // viszont ki szeretném írni

   public:
    LogicNetwork(size_t wires_size, std::ostream& os = std::cout);
    void update();
    void bulk_update(size_t update_count);
    // visszaad egy wire pointert manuális kötésre
    // ha nincs, létrehoz annyit, hogy legyen
    Wire* get_wire(size_t wire_id);
    void add_component(Component* component);
#ifdef DEBUG
    void debug() {
        std::cout << "Logic network" << std::endl
                  << "Containts " << wires_size << " wires" << std::endl;
        for (size_t i = 0; i < wires_size; i++) {
            wires[i].debug();
        }
        std::cout << "Contains " << components_size << " components" << std::endl;
        for (size_t i = 0; i < components_size; i++) {
            components[i]->debug();
        }
    }
#endif
    ~LogicNetwork();
};