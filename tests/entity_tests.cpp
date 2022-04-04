
#include <assert.h>
#include "entity_tests.h"

entity_tests::entity_tests(){
    tests.push_back(&entity_tests::test_equality);
    tests.push_back(&entity_tests::test_assignment);
}

entity_tests::~entity_tests(){
    tests.clear();
}

void entity_tests::destroy(){
    return;
}

void entity_tests::build(){
    a.denumire = "asdf";
    a.pret = 1000;
    a.producator = "asdfasdf";
    a.substanta_activa = "subst_activa";

    b.denumire = "hopa";
    b.pret = 2000;
    b.producator = "ggdsf";
    b.substanta_activa = "substanta";
}

void entity_tests::run(){
    for(auto i : tests){
        build();

        (this->*i)();

        destroy();

    }
}

void entity_tests::test_equality(){
    
    assert(a!=b);
    assert(a==a);
}

void entity_tests::test_assignment(){
    
    a=b;
    assert(a==b);
}
