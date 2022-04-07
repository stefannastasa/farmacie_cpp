#pragma once
#include "../service/service.h"
#include "../errors/errors.h"
#include <iostream>
#include <memory>
#include <vector>
using namespace std;
class console{
// typedef void(console::&comm)();
    private:
        service farmacie;

        void afiseazaLista();
    public:
        // console();

        void adauga();

        void sterge();

        void modifica();
        
        void cautare();
        
        void afisare();

        void iesire();

        void filtrare();

        void sortare();

        void run();
};