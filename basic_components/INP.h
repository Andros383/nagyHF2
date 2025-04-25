
#include "../component.h"
#include "../memtrace.h"
#define DEBUG

class INP : public Component {
    int signal;
    // am lehetne struct is, ha már nincs privát tagja
   public:
    INP(Wire* out, int signal);
    // nem változik a belső állapot
    void update();
    const char* get_name() { return "INP"; }

#ifdef DEBUG
    void debug() {
        std::cout << "INP gate: " << (void*)this << std::endl
                  << "\tsignal: " << signal << std::endl
                  << "\tout: " << (void*)output << "\tval: " << output->get_signal() << std::endl;
    }
#endif
};