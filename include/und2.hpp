#pragma once
#include "baustein.hpp"
#include "schnittstelle.hpp"

class Und2 : Baustein
{
private:
    /* data */
public:
    Und2(Schnittstelle* e0, Schnittstelle* e1, Schnittstelle* a0);
    ~Und2();
    void update();
};

Und2::Und2(Schnittstelle* e0, Schnittstelle* e1, Schnittstelle* a0)
{
    name = "Und2";
    addEingang(e0);
    addEingang(e1);
    addAusgang(a0);
}
void Und2::update(){
    /*hier rufen wir mit .at() eine bestimmte Position des Vectors auf und vergleichen sie mit dem was wir in Schnittstelle definiert haben
    Die Logik hier ist, wenn entweder der erste oder zweite Eingang undefiniert ist, soll auch der Ausgang undefiniert sein*/
    if (eingang.at(0)->getPegel() == Schnittstelle::UNDEFINED || eingang.at(1)->getPegel() == Schnittstelle::UNDEFINED) 
    {
        ausgang.at(0)->setPegel(Schnittstelle::UNDEFINED);
    }

    /*Wenn einer der beiden Eingänge High ist soll auch der Ausgang auf High geschaltet werden*/
    else if ((eingang.at(0)->getPegel() == Schnittstelle::HIGH && eingang.at(1)->getPegel() == Schnittstelle::LOW) || (eingang.at(0)->getPegel() == Schnittstelle::LOW && eingang.at(1)->getPegel() == Schnittstelle::HIGH))
    {
        ausgang.at(0)->setPegel(Schnittstelle::LOW);
    }
    //Wenn beide Pegel auf High sind, soll er auf 0 Stellen
    else if (eingang.at(0)->getPegel() == Schnittstelle::HIGH && eingang.at(1)->getPegel() == Schnittstelle::HIGH)
    {
        ausgang.at(0)->setPegel(Schnittstelle::HIGH);
    }
}
