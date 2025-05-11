
#ifndef INP_H
#define INP_H

#include "../component.h"
#include "../memtrace.h"

class INP : public Component {
    static const char* name;
    int signal;
    // copy constructor és értékadó operátor letiltása
    // mert memóriahibát okozna, és nincs értelme ugyan azt a komponenst létrehozni
    // pontosan ugyan azt csinálná két ugyan oda kötött komponens, mint egy
    INP(const INP&);
    INP& operator=(const INP&);

   public:
    INP(Wire* out, int signal);
    void update();
    void write(Wire* base_address, std::ostream& os = std::cout);
    static const char* get_name() {
        return name;
    }
};

#endif