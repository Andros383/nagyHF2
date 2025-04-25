
#include "../component.h"
#include "../memtrace.h"
#define DEBUG

class OR : public Component {
    // am lehetne struct is, ha már nincs privát tagja
   public:
    OR(Wire* inpA, Wire* inpB, Wire* out);
    void update();
    const char* get_name() { return "OR"; }

#ifdef DEBUG
    void debug() {
        std::cout << "OR gate: " << (void*)this << std::endl
                  << "\tinp1: " << (void*)inputs[0] << "\tval: " << inputs[0]->get_signal() << std::endl
                  << "\tinp2: " << (void*)inputs[1] << "\tval: " << inputs[1]->get_signal() << std::endl
                  << "\tout: " << (void*)output << "\tval: " << output->get_signal() << std::endl;
    }
#endif
};