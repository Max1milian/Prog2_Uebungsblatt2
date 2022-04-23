#pragma once
#include "schnittstelle.hpp"
#include "baustein.hpp"
class Xor2 : Baustein
{
private:
    /* data */
public:
    Xor2(Schnittstelle* e0, Schnittstelle* e1, Schnittstelle* a0);
    ~Xor2();
};

Xor2::Xor2(Schnittstelle* e0, Schnittstelle* e1, Schnittstelle* a0)
{
    if (eingang.at(0)->getPegel() == Schnittstelle::UNDEFINED || eingang.at(1)->getPegel() == Schnittstelle::UNDEFINED) 
    {
        ausgang.at(0)->setPegel(Schnittstelle::UNDEFINED);
    }

    /*Wenn einer der beiden Eingänge High ist soll auch der Ausgang auf High geschaltet werden*/
    else if ((eingang.at(0)->getPegel() == Schnittstelle::HIGH && eingang.at(1)->getPegel() == Schnittstelle::LOW) || (eingang.at(0)->getPegel() == Schnittstelle::LOW && eingang.at(1)->getPegel() == Schnittstelle::HIGH))
    {
        ausgang.at(0)->setPegel(Schnittstelle::HIGH);
    }
    //Wenn beide Pegel auf High sind, soll er auf LOW schalten
    else if (eingang.at(0)->getPegel() == Schnittstelle::HIGH && eingang.at(1)->getPegel() == Schnittstelle::HIGH)
    {
        ausgang.at(0)->setPegel(Schnittstelle::LOW);
    }
}

