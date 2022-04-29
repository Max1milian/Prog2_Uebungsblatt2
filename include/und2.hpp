#ifndef UND2_HPP_
#define UND2_HPP_
#include "baustein.hpp"
#include "schnittstelle.hpp"

class Und2 : public Baustein //<-- : heißt: erbt von
{
private:
    /* data */
public:
    Und2(Schnittstelle* e0, Schnittstelle* e1, Schnittstelle* a0);
    void update();
    void print();
};

Und2::Und2(Schnittstelle* e0, Schnittstelle* e1, Schnittstelle* a0)
{
    name = "Und2";
    addEingang(e0);
    addEingang(e1);
    addAusgang(a0);
}

void Und2::print(){
    std::cout << name << std::endl;
    std::cout << "Eingang 0: Pegel = " << eingang.at(0)->getPegel() << std::endl;
    std::cout << "Eingang 1: Pegel = " << eingang.at(1)->getPegel() << std::endl;
    std::cout << "Ausgang 0: Pegel = " << ausgang.at(0)->getPegel() << std::endl;
}

void Und2::update(){
    /*hier rufen wir mit .at() eine bestimmte Position des Vectors auf und vergleichen sie mit dem was wir in Schnittstelle definiert haben
    Die Logik hier ist, wenn entweder der erste oder zweite Eingang undefiniert ist, soll auch der Ausgang undefiniert sein*/
    if (eingang.at(0)->getPegel() == Schnittstelle::UNDEFINED || eingang.at(1)->getPegel() == Schnittstelle::UNDEFINED) 
    {
        ausgang.at(0)->setPegel(Schnittstelle::UNDEFINED);
    }

    /*Wenn einer der beiden Eingänge High ist soll der Ausgang auf LOW geschaltet werden*/
    else if ((eingang.at(0)->getPegel() == Schnittstelle::HIGH && eingang.at(1)->getPegel() == Schnittstelle::LOW) || (eingang.at(0)->getPegel() == Schnittstelle::LOW && eingang.at(1)->getPegel() == Schnittstelle::HIGH))
    {
        ausgang.at(0)->setPegel(Schnittstelle::LOW);
    }
    //Wenn beide Pegel auf High sind, soll er auf HIGH Stellen
    else if (eingang.at(0)->getPegel() == Schnittstelle::HIGH && eingang.at(1)->getPegel() == Schnittstelle::HIGH)
    {
        ausgang.at(0)->setPegel(Schnittstelle::HIGH);
    }
}
#endif
