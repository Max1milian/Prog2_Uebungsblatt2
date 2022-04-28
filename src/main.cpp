#include <iostream>
#include "baustein.hpp"
#include "halbaddierer.hpp"
#include "xor2.hpp"
#include "oder2.hpp"
#include "und2.hpp"
#include "schnittstelle.hpp"
#include "schaltung.hpp"
#include "volladierer.hpp"

class Test
{
public:
    void test(Baustein* baustein)
    {
        baustein->eingang[0]->setPegel(Schnittstelle::HIGH);
        baustein->eingang[1]->setPegel(Schnittstelle::HIGH);
        baustein->update();
        baustein->print();
    }
    void test(Volladdierer* volladdierer)
    {
        volladdierer->eingang[0]->setPegel(Schnittstelle::HIGH);
        volladdierer->eingang[1]->setPegel(Schnittstelle::LOW);
        volladdierer->eingang[2]->setPegel(Schnittstelle::HIGH);
        volladdierer->update();
        volladdierer->print();
    }

};

void test2(Baustein* baustein)
{
    baustein->eingang[0]->setPegel(Schnittstelle::HIGH);
    baustein->eingang[1]->setPegel(Schnittstelle::HIGH);
    baustein->update();
    baustein->print();
}
void testFull(Volladdierer* voll)
{
    voll->eingang[0]->setPegel(Schnittstelle::HIGH);
    voll->eingang[1]->setPegel(Schnittstelle::LOW);
    voll->eingang[2]->setPegel(Schnittstelle::HIGH);
    voll->update();
    voll->print();
}

int main()
{
    //hier deklarieren wir die schnitstellen für die Gatter damit wir diese "verdrahten können"
    Schnittstelle e0, e1, e2, a0, a1;
    Volladdierer* voll = new Volladdierer(&e0, &e1, &e2, &a0, &a1);
    Halbaddierer* halb = new Halbaddierer(&e0, &e1, &a0, &a1);

    Und2* u1 = new Und2(&e0, &e1, &a0);
    Xor2* xor1 = new Xor2(&e0, &e1, &a0);
    Oder2* o1 = new Oder2(&e0, &e1, &a0);

    //hier führen wir die Test aus, damit das Program richtig funktioniert
    Test t;
    t.test(voll);
    std::cout << std::endl;
    t.test(u1);
    std::cout << std::endl;
    test2(xor1);
    std::cout << std::endl;
    test2(o1);
    return 0;
}
