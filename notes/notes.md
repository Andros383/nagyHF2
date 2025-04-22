Vannak komponensek, ezek saját maguk által definiáltak
Teljesen leírná őket a bemenetekre adott kimenetek

Ezen kívül van wire, ami a jelek összekötésére, továbbítására szolgál.
Van egy bemenete, és egy kimenete.
Modellezésre egy wire kimenetén a bemeneti jelek közül a legnagyobb jelenik meg.

A szimuláció egy lépése két allépéssel történik:
1) Minden Wire a bemenetén lévő adatot átrakja a kimenetére
2) Minden komponens leolvassa a bemenetére rakott adatot, kiszámítja a kimenetet, és ráírja a kimenet Wire-re.


Ami mindenképp lesz:
Konstans jeladó komponens
Wire
NAND kapu (valamiért ez kell)
Késleltető komponens (~regiszter, beolvassa és ki is adja az adatot) 

