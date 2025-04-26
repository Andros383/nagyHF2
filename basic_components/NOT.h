
#include "../component.h"
#include "../memtrace.h"
#define DEBUG

class NOT : public Component {
   public:
    NOT(Wire* inpA, Wire* out);
    void update();
    void write(Wire* base_address, std::ostream& os = std::cout);

#ifdef DEBUG
    void debug() {
        std::cout << "NOT gate: " << (void*)this << std::endl
                  << "\tinp: " << (void*)inputs[0] << "\tval: " << inputs[0]->get_signal() << std::endl
                  << "\tout: " << (void*)output << "\tval: " << output->get_signal() << std::endl;
    }
#endif
};