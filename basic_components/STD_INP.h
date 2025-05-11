

#ifndef STD_INP_H
#define STD_INP_H

#include "../component.h"
#include "../memtrace.h"

// mindig a standard bemenetről olvassa be, hogy mit adjon ki
class STD_INP : public Component {
    static const char* name;
    int signal;
    bool is_signal_set;
    char* label;

    // copy constructor és értékadó operátor letiltása
    // mert memóriahibát okozna, és nincs értelme ugyan azt a komponenst létrehozni
    // pontosan ugyan azt csinálná két ugyan oda kötött komponens, mint egy
    STD_INP(const STD_INP&);
    STD_INP& operator=(const STD_INP&);

   public:
    STD_INP(Wire* out, const char* label = "unnamed_input");
    void update();
    void write(Wire* base_address, std::ostream& os = std::cout);
    static const char* get_name() {
        return name;
    }
    ~STD_INP();
};

#endif