#pragma once
class Schnittstelle
{
private:
    short pegel = LOW;
public:
    const static short LOW = 0;
    const static short HIGH = 1;
    const static short UNDEFINED = -1;

    short getPegel();
    bool setPegel(short pegel);

    Schnittstelle(/* args */);
    ~Schnittstelle();
};

short Schnittstelle::getPegel(){
        return pegel;
}

bool Schnittstelle::setPegel(short pegel){
        switch (pegel)
        {
        case HIGH:
            pegel = HIGH;
            return true;
            break;

        case LOW:
            pegel = LOW;
            return true;
            break;
        
        default:
            pegel = UNDEFINED;
            return false;
            break;
        }
}