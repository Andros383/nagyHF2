
#include <iostream>
#define DEBUG

#include "../component.h"
#include "../memtrace.h"
class PRINT : public Component {
    std::ostream& os;
    char* label;

   public:
    PRINT(Wire* inpA, const char* label = "unnamed_output", std::ostream& os = std::cout);
    void update();
    void write(Wire* base_address, std::ostream& os = std::cout);
    ~PRINT();
#ifdef DEBUG
    void debug() {
        std::cout << "PRINT gate: " << (void*)this << std::endl
                  << "\tinp: " << (void*)inputs[0] << "\tval: " << inputs[0]->get_signal() << std::endl;
    }
#endif
};