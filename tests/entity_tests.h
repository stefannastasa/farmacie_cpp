#pragma once
#include "../entities/entity.h"
#include <vector>
class entity_tests{

    private:
        typedef void (entity_tests::*function)() ;
        
        entity a, b;
        //Write constructor and deconstructor here
        
        void build();
        void destroy();
        //Write tests here
        void test_equality();
        void test_assignment();
        std::vector<function> tests;

    public:

        entity_tests();

        void run();

        ~entity_tests();
};