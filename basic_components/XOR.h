
#include "../component.h"
#include "../memtrace.h"

#define DEBUG
class XOR : public Component {
   public:
    XOR(Wire* inpA, Wire* inpB, Wire* out);
    void update();
    void write(Wire* base_address, std::ostream& os = std::cout);
#ifdef DEBUG
    void debug() {
        std::cout << "XOR gate: " << (void*)this << std::endl
                  << "\tinp1: " << (void*)inputs[0] << "\tval: " << inputs[0]->get_signal() << std::endl
                  << "\tinp2: " << (void*)inputs[1] << "\tval: " << inputs[1]->get_signal() << std::endl
                  << "\tout: " << (void*)output << "\tval: " << output->get_signal() << std::endl;
    }
#endif
};