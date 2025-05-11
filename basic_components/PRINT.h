
#ifndef PRINT_H
#define PRINT_H

#include <iostream>

#include "../component.h"
#include "../memtrace.h"
class PRINT : public Component {
    static const char* name;
    std::ostream& os;
    char* label;

    // copy constructor és értékadó operátor letiltása
    // mert memóriahibát okozna, és nincs értelme ugyan azt a komponenst létrehozni
    // pontosan ugyan azt csinálná két ugyan oda kötött komponens, mint egy
    PRINT(const PRINT&);
    PRINT& operator=(const PRINT&);

   public:
    PRINT(Wire* inpA, const char* label = "unnamed_output", std::ostream& os = std::cout);
    void update();
    void write(Wire* base_address, std::ostream& os = std::cout);
    static const char* get_name() {
        return name;
    }
    ~PRINT();
};

#endif