#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "schnittstelle.hpp"

class Baustein
{
private:
    /* data */
protected:
std::string name;
std::vector <Schnittstelle*> eingang{};
std::vector <Schnittstelle*> ausgang{};
    
public:
    void addEingang(Schnittstelle* schnittstelle);
    void addAusgang(Schnittstelle* schnittstellet);    
    virtual void print() = 0;
    virtual void update() = 0;
};

void Baustein::addEingang(Schnittstelle* schnittstelle){
    eingang.push_back(*schnittstelle->getPegel);
}

void Baustein::addAusgang(Schnittstelle* schnittstelle){

}