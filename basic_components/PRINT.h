
#include <iostream>
#define DEBUG

#include "../component.h"
#include "../memtrace.h"
class PRINT : public Component {
    std::ostream& os;
    const char* label;
    // am lehetne struct is, ha már nincs privát tagja
   public:
    // TODO init lista ahol maga a függvény van?
    // alapértékek itt is ott is?
    PRINT(Wire* inpA, const char* label = "unnamed_output", std::ostream& os = std::cout);
    void update();
    const char* get_name() { return "PRINT"; }

#ifdef DEBUG
    void debug() {
        std::cout << "PRINT gate: " << (void*)this << std::endl
                  << "\tinp: " << (void*)inputs[0] << "\tval: " << inputs[0]->get_signal() << std::endl;
    }
#endif
};