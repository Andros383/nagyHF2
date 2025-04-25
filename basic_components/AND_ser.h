#ifndef AND_SER_H
#define AND_SER_H

#include "../serialized_component.h"
#include "AND.h"
#include "memtrace.h"
// elméletben jó a public öröklés, mert nincs "gyémánt struktúra" (kapu és a szerializáció közös őse)
class AND_ser : public SerializedComponent, public AND {
   public:
    virtual void write(std::ostream& os, Wire* base_address) {
		
    }
};

#endif