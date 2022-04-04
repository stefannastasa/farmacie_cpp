#pragma once
#include "../repository/repository.h"
#include <vector>
class repository_tests{
    private:
        
        typedef void (repository_tests::*function)() ;
        
        repository test_repo;
        entity list_of_entities[50];// NOLINT
        //Write constructor and deconstructor here
        
        void build();
        void destroy();
        std::vector<function> tests;
        //Write tests here
        void test_create_entity();
        void test_adauga_repo();
        void test_cauta_repo();
        void test_sterge_repo();
        void test_modifica_repo();
        void test_get_all_repo();
        void test_get_elem_repo();
        void test_is_elem_in_repo();

    public:

        repository_tests();

        void run();

        ~repository_tests();
};