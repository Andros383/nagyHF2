
#include "../component.h"
#include "../memtrace.h"
#define DEBUG

// mindig a standard bemenetről olvassa be, hogy mit adjon ki
class STD_INP : public Component {
    int signal;
    bool is_signal_set;
    char* label;

   public:
    STD_INP(Wire* out, const char* label = "unnamed_input");
    void update();
    void write(Wire* base_address, std::ostream& os = std::cout);
    ~STD_INP();
#ifdef DEBUG
    void debug() {
        std::cout << "INP gate: " << (void*)this << std::endl
                  << "\tsignal: " << signal << std::endl
                  << "\tout: " << (void*)output << "\tval: " << output->get_signal() << std::endl;
    }
#endif
};