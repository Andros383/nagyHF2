

#ifndef OR_H
#define OR_H
#include "../component.h"
#include "../memtrace.h"

class OR : public Component {
    static const char* name;
    // copy constructor és értékadó operátor letiltása
    // mert memóriahibát okozna, és nincs értelme ugyan azt a komponenst létrehozni
    // pontosan ugyan azt csinálná két ugyan oda kötött komponens, mint egy
    OR(const OR&);
    OR& operator=(const OR&);

   public:
    OR(Wire* inpA, Wire* inpB, Wire* out);
    void update();
    void write(Wire* base_address, std::ostream& os = std::cout);
    static const char* get_name() {
        return name;
    }
};

#endif
