#pragma once
#include "schnittstelle.hpp"
#include "schaltung.hpp"
#include "baustein.hpp"
#include "xor2.hpp"
#include "oder2.hpp"
#include "und2.hpp"

class Halbaddierer : public Schaltung
{
private:
    /* data */
public:
    Halbaddierer(Schnittstelle* e0, Schnittstelle* e1, Schnittstelle* a0, Schnittstelle* a1);
    void update();
};

Halbaddierer::Halbaddierer(Schnittstelle* e0, Schnittstelle* e1, Schnittstelle* a0, Schnittstelle* a1) : Schaltung() //Initialisierung der Schaltung
{
    name = "Halbaddierer";
    addEingang(e0);
    addEingang(e1);
    addAusgang(a0);
    addAusgang(a1);

    //Erstellung der erforderlichen Bausteine
    Xor2* xor2 = new Xor2(e0, e1, a0);
    baustein.push_back(xor2);

    Und2* und2 = new Und2(e0, e1, a1);
    baustein.push_back(und2);
}

void Halbaddierer::update(){
        //hier rufen wir die jeweiligen bausteine auf
        baustein[0]->update(); //xor
        baustein[1]->update(); //and
         
}
