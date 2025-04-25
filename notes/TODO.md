Megoldani a fordításokat
Bekapcsolni a warningot, -fsanitize=address?, meg egyéb memtrace szerű dolgokat
.cpp fájlokra kell-e include guard
A fájlnevek nagybetűsek legyenek-e 

Minden fileba
#include "memtrace.h"


Az includeok rendezése

csomó helyen van olyan, hogy ki akarok írni valamit csak debugban, ezért behívom az iostreamet
bevinni az includeokat a debugba?

a debug cuccokat vagy kivenni a végén teljesen, vagy valahogy megoldani, hogy a compile-al jól menjenek meg a virtuális függvénnyel is

mindenhol jó-e az output stream OS cucc (nem véltelen cout-ra megy ki)

szóköz ne lehessen a print kapuk nevében
meg legyen benne a specben hogy a kapuk szerializációjánál se lehessen

átnevezni, mert technikailag deszerializáció ha kiírni tudom csak