# Felhasználói dokumentáció
### Program leírása
A program egy logikai hálózatot modellez. Ebben komponensek vannak, amiknek több bemenete, de csak egy kimenete van (például AND kapu). A be és kimenetek vezetékre csatlakoznak, amik a jelet ütemezve továbbítják a többi komponens felé.

A programban megvalósuló osztályok:
- AND, XOR, OR, NOT bináris kapuk
- Wire: Komponenseket összekötő vezeték 
- INP: Konstans jelet adó komponens
- STD_INP: Olyan INP, ami a jelet első frissítéskor a standard bemenetről olvassa be
- LogicNetwork: A vezetékeket és komponenseket egybefoglaló logikai hálózat osztály
- LogicNetworkConfigurer: Olyan logikai hálózat osztály, aminek a felépítését fájlból lehet beolvasni és visszaírni

### Szimuláció működése

Az időbeli szimulálás miatt a vezetékeknek két része van. A vezeték egyes részeire akárhány komponens csatlakozhat, így csomópontként is funkcionál. A vezeték „elejére” csak írni lehet, a „végéről” pedig csak olvasni lehet a jelet.

A hálózat frissítése („órajele”) két fázisból áll. Első lépésben a komponensek leolvassák a bemenetükre kötött vezetékek végéről az adatot. Az eredmény kirakják a rájuk kötött vezetékek elejére. A nagyobb jelszint felülírja a kisebbet.

A második fázisban minden vezeték átrakja a jelet az elejéről a végére. Így a frissítés sorrendjétől független lesz a hálózat viselkedése.

Ennek megfelelően egy egész logikai hálózat frissítése először az összes komponens, majd az összes vezeték frissítéséből áll. (Ezt valósítja meg a logikai hálózat osztály update() függvénye)

A logikai hálózatnak van bulk_update() függvénye, ami egymás után több frissítést végez el. Az egyes frissítések kezdetét a kimeneten jelzi.

### Hálózat létrehozása
Hálózatot a main.cpp fájl példái alapján lehet létrehozni kódban a logikai hálózatok tagfüggvényeivel, vagy pedig szöveges fájl alapján is. A fájl szerinti beolvasásra is van példa a main.cpp-ben.

Hálózat létrehozásakor meg kell adni a kábelek számát, és az adatfolyamot ahova a frissítéseket kezdetét jelző szöveget írni fogja. Fájlból olvasásnál a PRINT komponensek is ide írnak.

A fájlból beolvasásnál az első sorban a kábelek, majd a komponensek számát kell megadni, utána soronként az egyes komponenseket a nekik megfelelő formátumban. A bemenetek a kábel sorszámát jelzik a hálózatban (0-tól indexelve):
- AND / OR / XOR \[1. bemenet\] \[2. bemenet\] \[kimenet\]
- NOT \[bemenet\] \[kimenet\]
- INP \[kimenet\] \[kimeneti jel\]
- STD_INP \[kimenet\] \[tetszőleges címke\]
- PRINT \[bemenet\] \[tetszőleges címke\]

## Programozói dokumentáció
### Hibák, kivételek
- A logikai hálózat beolvasása ha nem sikerült, szövegesen eldobja, hol érzékelt hibát.
- A logikai hálózatban a vezeték lekérésekor szöveges hibát dob, ha nincs elég kábel.
- STD_INP komponens szöveges hibát dob, ha a bejövő jel nem 0 vagy 1. Bár a program tudna más jeleket is kezelni, a megvalósított komponensek csak ezt a két értéket értelmezik.

### Tesztesetek
A main.cpp fájlban vannak a gtest_lite-al megvalósított tesztek. Az utolsó teszteset standard bemenetről olvas, amihez példabemenetet kap a Jporta.

### Egyéb megjegyzések
A komponensek mutatókkal tárolják, melyik vezetékhez kapcsolódnak. Emiatt minden osztálynál le van tiltva a másoló konstruktor és az értékadó operátor, mivel nem lehet / nincs értelme ugyan olyan objektumokat létrehozni.

### Új komponens felvétele
Az új komponens felvételéhez az osztálynak a többi komponenshez hasonlóan a Component leszármazottjának kell lennie. Ezen felül tetszőlegesen megvalósítható a beolvasás / kiírás.
A beolvasást a LogicNetworkConfigurer read_logic_network() függvényében kell megvalósítani a többihez hasonlóan. A komponens nevében nem szerepelhet whitespace, és legfeljebb 100 karakter hosszú lehet.
\n
\n
\n
\n
\n
\n
\n
## UML diagram