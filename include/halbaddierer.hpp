#pragma once
#include "schnittstelle.hpp"
#include "schaltung.hpp"
#include "baustein.hpp"
#include "xor2.hpp"
#include "oder2.hpp"
#include "und2.hpp"

class Halbaddierer : Schaltung
{
private:
    /* data */
public:
    Halbaddierer(Schnittstelle* e0, Schnittstelle* e1, Schnittstelle* a0, Schnittstelle* a1);
    void update();
};

Halbaddierer::Halbaddierer(Schnittstelle* e0, Schnittstelle* e1, Schnittstelle* a0, Schnittstelle* a1)
{
    
    intern.push_back(e0);
    intern.push_back(e1);
    intern.push_back(a0);
    intern.push_back(a1);

    Xor2 xor2(e0, e1, a0);
    //baustein.push_back(xor2);
    Und2 und2(e0, e1, a1);
    //baustein.pushback(und2);
    //name = "Halbaddierer";
}
void Halbaddierer::update(){

}
