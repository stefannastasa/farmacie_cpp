#pragma once
#include <string>


/*
    Modul pentru definirea entitatii de baza a 
    programului.
*/

class entity{
    public:
        entity();

        entity(entity&a);


        std::string denumire;
        float pret=0;
        std::string producator;
        std::string substanta_activa;

        //Definirea operatorului "="
        entity& operator=(const entity& a);

        //Definirea operatorului "="
        bool operator==(const entity& a) const;

        bool operator!=(const entity& a) const;
        ~entity();
};

entity NULL_ENTITY();