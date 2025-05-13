/**
 * @file main.cpp
 * @brief Main file az összes teszttel
 * Minden teszt gtest_lita-al írt. Az utolsó teszteset standard bemenetről olvas.
 *
 */

#include <fstream>
#include <iostream>
#include <sstream>

#include "basic_components.h"
#include "gtest_lite.h"
#include "logic_network.h"
#include "logic_network_configurer.h"
#include "memtrace.h"
#include "wire.h"
int main() {
    // TODO kivenni, rossz a konzolom
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;

    TEST(WIRE, update) {
        Wire a;
        EXPECT_EQ(0, a.get_signal()) << "Default signal értéke nem 0" << std::endl;
        a.set_signal(1);
        EXPECT_EQ(0, a.get_signal()) << "Amikor jelet kap, egyből kirakja a kimenetre" << std::endl;
        a.update();
        EXPECT_EQ(1, a.get_signal()) << "Update nem frissíti a kimeneti értéket" << std::endl;
        a.update();
        EXPECT_EQ(0, a.get_signal()) << "Update után nem tűnik el a kimeneti érték" << std::endl;

        Wire b;
        b.set_signal(1);
        b.set_signal(2025);
        b.update();
        EXPECT_EQ(2025, b.get_signal()) << "A magasabb jel nem írta felül az alacsonyabbat" << std::endl;

        Wire c;
        c.set_signal(2025);
        c.set_signal(1);
        c.update();
        EXPECT_EQ(2025, c.get_signal()) << "A későbbi jel felülírja az előbbit" << std::endl;
    }
    END
    TEST(Komponensek, INP) {
        Wire a;
        INP i(&a, 1);
        i.update();
        a.update();
        EXPECT_EQ(1, a.get_signal()) << "Nem írta rá a vezetékre a jelet" << std::endl;
        a.update();
        EXPECT_EQ(0, a.get_signal()) << "Frissítés nélkül rákerült a jel a vezetékre" << std::endl;
        i.update();
        a.update();
        EXPECT_EQ(1, a.get_signal()) << "Másodjára nem került a vezetékre a jel" << std::endl;
    }
    END
    TEST(Komponensek, AND értékek) {
        Wire i, h, ohh, ohi, oih, oii;
        AND hh(&h, &h, &ohh);
        AND hi(&h, &i, &ohi);
        AND ih(&i, &h, &oih);
        AND ii(&i, &i, &oii);
        // vezetékre teszi a jelet
        i.set_signal(1);
        h.set_signal(0);
        // bemenetekre rakja a jeleket
        i.update();
        h.update();

        // kapuk számítása
        hh.update();
        hi.update();
        ih.update();
        ii.update();

        // kimeneti vezetékek frissítése
        ohh.update();
        ohi.update();
        oih.update();
        oii.update();

        EXPECT_EQ(0, ohh.get_signal());
        EXPECT_EQ(0, ohi.get_signal());
        EXPECT_EQ(0, oih.get_signal());
        EXPECT_EQ(1, oii.get_signal());
    }
    END
    TEST(Komponensek, OR értékek) {
        Wire i, h, ohh, ohi, oih, oii;
        OR hh(&h, &h, &ohh);
        OR hi(&h, &i, &ohi);
        OR ih(&i, &h, &oih);
        OR ii(&i, &i, &oii);
        // vezetékre teszi a jelet
        i.set_signal(1);
        h.set_signal(0);
        // bemenetekre rakja a jeleket
        i.update();
        h.update();

        // kapuk számítása
        hh.update();
        hi.update();
        ih.update();
        ii.update();

        // kimeneti vezetékek frissítése
        ohh.update();
        ohi.update();
        oih.update();
        oii.update();

        EXPECT_EQ(0, ohh.get_signal());
        EXPECT_EQ(1, ohi.get_signal());
        EXPECT_EQ(1, oih.get_signal());
        EXPECT_EQ(1, oii.get_signal());
    }
    END
    TEST(Komponensek, XOR értékek) {
        Wire i, h, ohh, ohi, oih, oii;
        XOR hh(&h, &h, &ohh);
        XOR hi(&h, &i, &ohi);
        XOR ih(&i, &h, &oih);
        XOR ii(&i, &i, &oii);
        // vezetékre teszi a jelet
        i.set_signal(1);
        h.set_signal(0);
        // bemenetekre rakja a jeleket
        i.update();
        h.update();

        // kapuk számítása
        hh.update();
        hi.update();
        ih.update();
        ii.update();

        // kimeneti vezetékek frissítése
        ohh.update();
        ohi.update();
        oih.update();
        oii.update();

        EXPECT_EQ(0, ohh.get_signal());
        EXPECT_EQ(1, ohi.get_signal());
        EXPECT_EQ(1, oih.get_signal());
        EXPECT_EQ(0, oii.get_signal());
    }
    END
    TEST(Komponensek, NOT értékek) {
        Wire i, h, ohh, oii;
        NOT hh(&h, &ohh);
        NOT ii(&i, &oii);
        // vezetékre teszi a jelet
        i.set_signal(1);
        h.set_signal(0);
        // bemenetekre rakja a jeleket
        i.update();
        h.update();

        // kapuk számítása
        hh.update();
        ii.update();

        // kimeneti vezetékek frissítése
        ohh.update();
        oii.update();

        EXPECT_EQ(1, ohh.get_signal());
        EXPECT_EQ(0, oii.get_signal());
    }
    END
    TEST(Komponensek, PRINT) {
        Wire a;
        std::stringstream ss;
        PRINT print(&a, "Teszt kapu", ss);
        a.set_signal(1);
        a.update();
        print.update();
        // helyesen fordított sorrendben lennének az argumentumok, hibát dob a gtest
        EXPECT_EQ(ss.str(), "Teszt kapu: 1\n") << "Helytelen a print kiírása";

        std::stringstream ss2;
        a.set_signal(2025);
        a.update();
        PRINT nagy_print(&a, "Nagy teszt kapu", ss2);
        nagy_print.update();
        EXPECT_EQ(ss2.str(), "Nagy teszt kapu: 2025\n") << "A print nem tud tetszőleges kimenetet kezelni";
    }
    END
    TEST(LogicNetwork, and test) {
        std::stringstream ss;
        LogicNetwork ln(40, ss);
        ln.add_component(new INP(ln.get_wire(0), 1));
        ln.add_component(new INP(ln.get_wire(1), 1));
        ln.add_component(new PRINT(ln.get_wire(2), "AND output", ln.get_os()));
        ln.add_component(new AND(ln.get_wire(0), ln.get_wire(1), ln.get_wire(2)));
        // az első update-ban az INP-ről bekerülnek a wire elejére, majd végére a jelek
        // másodikban bekerülnek az AND kapuba, majd a 2-es wire végére
        // harmadikban tudja csak levolasni az igaz jelet a PRINT kapu
        // az INP kapuk folyamatosan adják a jelet, így a következő frissítésekben is marad a jel

        ln.bulk_update(4);
        EXPECT_EQ(ss.str(),
                  " --- Update 1 ---\n"
                  "AND output: 0\n\n"
                  " --- Update 2 ---\n"
                  "AND output: 0\n\n"
                  " --- Update 3 ---\n"
                  "AND output: 1\n\n"
                  " --- Update 4 ---\n"
                  "AND output: 1\n\n");
    }
    END
    TEST(LogicNetwork, xor blink test) {
        std::stringstream ss;
        LogicNetwork ln(40, ss);
        ln.add_component(new INP(ln.get_wire(0), 1));
        ln.add_component(new PRINT(ln.get_wire(1), "XOR output", ln.get_os()));
        ln.add_component(new XOR(ln.get_wire(0), ln.get_wire(1), ln.get_wire(1)));

        ln.bulk_update(6);
        EXPECT_EQ(ss.str(),
                  " --- Update 1 ---\n"
                  "XOR output: 0\n\n"
                  " --- Update 2 ---\n"
                  "XOR output: 0\n\n"
                  " --- Update 3 ---\n"
                  "XOR output: 1\n\n"
                  " --- Update 4 ---\n"
                  "XOR output: 0\n\n"
                  " --- Update 5 ---\n"
                  "XOR output: 1\n\n"
                  " --- Update 6 ---\n"
                  "XOR output: 0\n\n");
    }
    END

    TEST(LogicNetwork, sok wire) {
        LogicNetwork ln(40);
        EXPECT_NO_THROW(ln.get_wire(39)) << "Hibát dob amikor még elég drótnak kéne lennie";
        EXPECT_THROW(ln.get_wire(40), const char*) << "Nem dob hibát ha túl sok drótot használunk";
    }
    END

    TEST(LogicNetworkConfigurer, kapuk beolvasása és kimentése) {
        std::stringstream logic_network_output;

        // 0 wire elég, mert úgy is felülírja a beolvasó függvény
        LogicNetworkConfigurer lnc(0, logic_network_output);

        std::stringstream input_configuration;
        input_configuration << "6 10\n"
                               "INP 0 0\n"
                               "INP 1 1\n"
                               "AND 0 1 2\n"
                               "XOR 0 1 3\n"
                               "OR 0 1 4\n"
                               "NOT 1 5\n"
                               "PRINT 2 AND kapu kimenet\n"
                               "PRINT 3 XOR kapu kimenet\n"
                               "PRINT 4 OR kapu kimenet\n"
                               "PRINT 5 NOT kapu kimenet\n";

        // EXPECT_NO_THROW(lnc.read_logic_network(input_configuration));
        lnc.read_logic_network(input_configuration);

        lnc.bulk_update(3);
        // a NOT kapu első update-nál kirak egy 1-est a hozzá tartozó PRINT-re
        // mert még nem érkezett meg a jele az 1-es INP-től
        EXPECT_EQ(logic_network_output.str(),
                  " --- Update 1 ---\n"
                  "AND kapu kimenet: 0\n"
                  "XOR kapu kimenet: 0\n"
                  "OR kapu kimenet: 0\n"
                  "NOT kapu kimenet: 0\n\n"
                  " --- Update 2 ---\n"
                  "AND kapu kimenet: 0\n"
                  "XOR kapu kimenet: 0\n"
                  "OR kapu kimenet: 0\n"
                  "NOT kapu kimenet: 1\n\n"
                  " --- Update 3 ---\n"
                  "AND kapu kimenet: 0\n"
                  "XOR kapu kimenet: 1\n"
                  "OR kapu kimenet: 1\n"
                  "NOT kapu kimenet: 0\n\n")
            << "Nem sikerült a hálózat beolvasása";
        std::stringstream config_vissza;
        lnc.write_logic_network(config_vissza);
        // vigyázni kell a tesztelésnél, utolsó sortörés elhagyható a beolvasásnál
        EXPECT_EQ(config_vissza.str(), input_configuration.str());
    }
    END

    TEST(LogicNetworkConfigurer, manuális kiírás) {
        // előző tesztben lévő hálózat manuális megépítése és kiírása

        // nem kell logikai hálózatnak stream, mert nem írunk ki rá (alapból std::cout-ra ír)
        LogicNetworkConfigurer lnc(6);
        lnc.add_component(new INP(lnc.get_wire(0), 0));
        lnc.add_component(new INP(lnc.get_wire(1), 1));
        lnc.add_component(new AND(lnc.get_wire(0), lnc.get_wire(1), lnc.get_wire(2)));
        lnc.add_component(new XOR(lnc.get_wire(0), lnc.get_wire(1), lnc.get_wire(3)));
        lnc.add_component(new OR(lnc.get_wire(0), lnc.get_wire(1), lnc.get_wire(4)));
        lnc.add_component(new NOT(lnc.get_wire(1), lnc.get_wire(5)));
        lnc.add_component(new PRINT(lnc.get_wire(2), "AND kapu kimenet"));
        lnc.add_component(new PRINT(lnc.get_wire(3), "XOR kapu kimenet"));
        lnc.add_component(new PRINT(lnc.get_wire(4), "OR kapu kimenet"));
        lnc.add_component(new PRINT(lnc.get_wire(5), "NOT kapu kimenet"));

        std::stringstream write_output;
        lnc.write_logic_network(write_output);
        EXPECT_EQ(write_output.str(),
                  "6 10\n"
                  "INP 0 0\n"
                  "INP 1 1\n"
                  "AND 0 1 2\n"
                  "XOR 0 1 3\n"
                  "OR 0 1 4\n"
                  "NOT 1 5\n"
                  "PRINT 2 AND kapu kimenet\n"
                  "PRINT 3 XOR kapu kimenet\n"
                  "PRINT 4 OR kapu kimenet\n"
                  "PRINT 5 NOT kapu kimenet\n")
            << "Nem sikerült a hálózat kiírása";
    }
    END
    TEST(LogicNetworkConfigurer, túl sok wire) {
        LogicNetworkConfigurer lnc;
        std::stringstream config;
        // az egyetlen wire ami létezik a 0-s, így hibát dob
        config << "1 1\nAND 1 1 1";

        EXPECT_THROW(lnc.read_logic_network(config), const char*);
    }
    END
    TEST(LogicNetworkConfigurer, túl hamar vége) {
        LogicNetworkConfigurer lnc;
        std::stringstream config;
        // 3 komponenst próbál beolvasni, de csak egy van
        config << "10 3\nAND 1 1 1";
        EXPECT_THROW(lnc.read_logic_network(config), const char*);
    }
    END
    TEST(LogicNetworkConfigurer, értelmetlen bemenet) {
        LogicNetworkConfigurer lnc;
        std::stringstream config;
        // 3 komponenst próbál beolvasni, de csak egy van
        config << "10 1\nAND 1 macska 1";
        EXPECT_THROW(lnc.read_logic_network(config), const char*);
    }
    END
    TEST(LogicNetworkConfigurer, sorvége) {
        std::stringstream input_configuration;
        // lemaradt az utolsó komponens utáni sorvége jel
        // ha az utolsó komponenssel van a hiba, külön felhívja erre a gyakori hibára a figyelmet
        input_configuration << "1 2\n"
                               "PRINT 0 Kimenet\n"
                               "INP 0 1";
        LogicNetworkConfigurer lnc;
        EXPECT_THROW(lnc.read_logic_network(input_configuration), const char*);
    }
    END
    TEST(LogicNetworkConfigurer, kezdeti paraméterek) {
        std::stringstream input_configuration;
        // a kábelek száma helyett értelmetlen szöveget van
        input_configuration << "macska 2\n"
                               "PRINT 0 Kimenet\n"
                               "INP 0 1\n";
        LogicNetworkConfigurer lnc(0);
        EXPECT_THROW(lnc.read_logic_network(input_configuration), const char*);
    }
    END

    TEST(LogicNetworkConfigurer, standard bemenet) {
    }
    std::stringstream ss;
    LogicNetworkConfigurer lnc(0, ss);
    std::ifstream f("fivetest.txt");
    try {
        lnc.read_logic_network(f);
        lnc.bulk_update(6);
    } catch (const char* error) {
        std::cout << "Futtatás közbeni hiba: " << std::endl;
        std::cout << error << '\n';
    }
    EXPECT_EQ(ss.str(),
              " --- Update 1 ---\n"
              "Ha a bemenet 5 volt valamikor itt a kimenet 1 lesz: 0\n\n"
              " --- Update 2 ---\n"
              "Ha a bemenet 5 volt valamikor itt a kimenet 1 lesz: 0\n\n"
              " --- Update 3 ---\n"
              "Ha a bemenet 5 volt valamikor itt a kimenet 1 lesz: 0\n\n"
              " --- Update 4 ---\n"
              "Ha a bemenet 5 volt valamikor itt a kimenet 1 lesz: 0\n\n"
              " --- Update 5 ---\n"
              "Ha a bemenet 5 volt valamikor itt a kimenet 1 lesz: 0\n\n"
              " --- Update 6 ---\n"
              "Ha a bemenet 5 volt valamikor itt a kimenet 1 lesz: 1\n\n");
    f.close();
    END

        return 0;
}