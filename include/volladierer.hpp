#pragma once
#include "schnittstelle.hpp"
#include "schaltung.hpp"
#include "baustein.hpp"
#include "xor2.hpp"
#include "oder2.hpp"
#include "und2.hpp"

class Volladdierer : Schaltung
{
private:
    /* data */
public:
    Volladdierer(Schnittstelle* e0, Schnittstelle* e1, Schnittstelle* e2, Schnittstelle* a0, Schnittstelle* a1);
};

Volladdierer::Volladdierer(Schnittstelle* e0, Schnittstelle* e1, Schnittstelle* e2, Schnittstelle* a0, Schnittstelle* a1)
{
    intern.push_back(e0);
    intern.push_back(e1);
    intern.push_back(e2);
    intern.push_back(a0);
    intern.push_back(a1);

}
