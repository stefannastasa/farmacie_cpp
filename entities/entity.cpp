#include "entity.h"
#include <iostream>

entity& entity::operator=(const entity& a){
    denumire = a.denumire;
    pret = a.pret;
    producator = a.producator;
    substanta_activa = a.substanta_activa;

    return *this;
}

bool entity::operator==(const entity& a) const{
    return (denumire == a.denumire && producator == a.producator);
}

bool entity::operator!=(const entity& a) const{
    return !(*this==a);
}

entity::entity(entity& a):denumire{a.denumire},pret{a.pret},producator{a.producator}, substanta_activa{a.substanta_activa}{

    std::cout<<denumire<<'\n';

}

entity::entity(){

}

entity NULL_ENTITY(){
    entity a;
    a.denumire = "";
    a.pret = 0;
    a.producator = "";
    a.substanta_activa = "";

    return a;
}
