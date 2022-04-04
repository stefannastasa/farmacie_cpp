#pragma once
#include "../repository/repository.h"
#include "../validators/validator.h"
#include "../errors/errors.h"
#include <iostream>
class service_tests;

class service{
    friend class service_tests;
    private:
        repository repo;
        validator val;
    public:
        void adauga(entity to_add);
        void sterge(entity to_sters);
        void modifica(entity current, entity modifications);
        entity cauta(std::string denumire, std::string producator);
        pair<IT, IT> all();
        entity dataConverter(std::string nume, std::string pret, std::string producator, std::string substanta_activa);
        unsigned long size();
        
};