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
        //wir setzen einen Switch auf Pegel um zu überprüfen ob der Pegel HIGH, LOW oder UNDEFINED ist
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
        
        //anstatt alle Fälle durchzugehen setzen wir einfach für alles was nicht HIGH oder LOW ist auf UNDEFINED und geben ein false zurück
        default:
            pegel = UNDEFINED;
            return false;
            break;
        }
}