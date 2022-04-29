#ifndef ODER2_HPP_
#define ODER2_HPP_
#include "schnittstelle.hpp"
#include "baustein.hpp"
class Oder2 : public Baustein
{
private:
    /* data */
public:
    Oder2(Schnittstelle* e0, Schnittstelle* e1, Schnittstelle* a0);
    void update();
    void print();
};

Oder2::Oder2(Schnittstelle* e0, Schnittstelle* e1, Schnittstelle* a0)
{
    name = "Oder2";
    addEingang(e0);
    addEingang(e1);
    addAusgang(a0);
}

void Oder2::print(){
    std::cout << name << std::endl;
    std::cout << "Eingang 0: Pegel = " << eingang.at(0)->getPegel() << std::endl;
    std::cout << "Eingang 1: Pegel = " << eingang.at(1)->getPegel() << std::endl;
    std::cout << "Ausgang 0: Pegel = " << ausgang.at(0)->getPegel() << std::endl;
}

void Oder2::update(){
    /*hier rufen wir mit .at() eine bestimmte Position des Vectors auf und vergleichen sie mit dem was wir in Schnittstelle definiert haben
    Die Logik hier ist, wenn entweder der erste oder zweite Eingang undefiniert ist, soll auch der Ausgang undefiniert sein*/
    if (eingang.at(0)->getPegel() == Schnittstelle::UNDEFINED || eingang.at(1)->getPegel() == Schnittstelle::UNDEFINED) 
    {
        ausgang.at(0)->setPegel(Schnittstelle::UNDEFINED);
    }

    /*Wenn einer der beiden Eingänge High ist soll auch der Ausgang auf High geschaltet werden*/
    else if ((eingang.at(0)->getPegel() == Schnittstelle::HIGH && eingang.at(1)->getPegel() == Schnittstelle::LOW) || (eingang.at(0)->getPegel() == Schnittstelle::LOW && eingang.at(1)->getPegel() == Schnittstelle::HIGH))
    {
        ausgang.at(0)->setPegel(Schnittstelle::HIGH);
    }
    //Wenn beide Pegel auf High sind, soll er auf HIGH schalten
    else if (eingang.at(0)->getPegel() == Schnittstelle::HIGH && eingang.at(1)->getPegel() == Schnittstelle::HIGH)
    {
        ausgang.at(0)->setPegel(Schnittstelle::HIGH);
    }
    
}
#endif
