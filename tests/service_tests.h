#pragma once

#include "../service/service.h"
#include "../generator/generator.h"
#include <assert.h>
class service_tests{
    private:
        typedef void (service_tests::*function)() ;
        
        service test_serv;
        entity ent_list[50];// NOLINT
        //Write constructor and deconstructor here
        
        void build();
        void destroy();

        
        //Write tests here
        // void test_dataConverter();
        void test_cauta_adauga();
        void test_sterge();
        void test_modifica();
        // void test_cauta();
        std::vector<function> tests;

    public:

        service_tests();

        void run();

        ~service_tests();

};