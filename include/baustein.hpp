#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "schnittstelle.hpp"

class Baustein //<-- abstrakte Klasse. Objekterzeugung nicht moeglich
{
    friend void test2(Baustein* baustein);
    friend class Test;
private:
    /* data */
protected:
    std::string name;
    std::vector <Schnittstelle*> eingang{}; //hier erzeugen wir ein dynamisches array für die Eingänge
    std::vector <Schnittstelle*> ausgang{}; //hier für die Ausgänge
    
public:
    void addEingang(Schnittstelle* schnittstelle); //wir übgergeben diese als Zeiger damit wir direkt auf die Informationen im Speicher zugreifen können
    void addAusgang(Schnittstelle* schnittstellet);    
    virtual void print();
    virtual void update() = 0; //deklaration als abstrakte Klasse
};

void Baustein::addEingang(Schnittstelle* schnittstelle){
    eingang.push_back(schnittstelle); //die jeweilige Schnittstelle wird dann mithilfe von push_back an das Array drangehängt
}

void Baustein::addAusgang(Schnittstelle* schnittstelle){
        ausgang.push_back(schnittstelle);
}
