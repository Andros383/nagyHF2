
#ifndef XOR_H
#define XOR_H

#include "../component.h"
#include "../memtrace.h"

class XOR : public Component {
    static const char* name;

    // copy constructor és értékadó operátor letiltása
    // mert memóriahibát okozna, és nincs értelme ugyan azt a komponenst létrehozni
    // pontosan ugyan azt csinálná két ugyan oda kötött komponens, mint egy
    XOR(const XOR&);
    XOR& operator=(const XOR&);

   public:
    XOR(Wire* inpA, Wire* inpB, Wire* out);
    void update();
    void write(Wire* base_address, std::ostream& os = std::cout);
    static const char* get_name() {
        return name;
    }
};

#endif