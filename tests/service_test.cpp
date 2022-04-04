#include "service_tests.h"


service_tests::service_tests(){
    tests.push_back(&service_tests::test_cauta_adauga);
    // tests.push_back(&service_tests::test_dataConverter);
    tests.push_back(&service_tests::test_sterge);
    tests.push_back(&service_tests::test_modifica);
}
service_tests::~service_tests(){

}

void service_tests::run(){
    for(auto i:tests){
        build();
        (this->*i)();
        destroy();
    }
}

void service_tests::build(){
    randomGenerator gen;

    for(int i=0;i<50;++i){
        ent_list[i] = test_serv.dataConverter(gen.genString(50), std::to_string(gen.genFloat()), gen.genString(50), gen.genString(50));// NOLINT
        test_serv.adauga(ent_list[i]); // NOLINT
    }
}

void service_tests::test_cauta_adauga(){
    for(int i=0;i<50;++i){
        entity asdf = test_serv.cauta(ent_list[i].denumire, ent_list[i].producator);// NOLINT
        assert(asdf == ent_list[i]);// NOLINT
    }
}

void service_tests::test_sterge(){
    for(int i=0;i<50;++i){
        test_serv.sterge(ent_list[i]);// NOLINT
        assert(test_serv.size() == (unsigned long)50-i-1);
    }
        assert(test_serv.size() == 0);

}

void service_tests::test_modifica(){
    entity newLst[50]; // NOLINT
    randomGenerator gen;
    for(int i=0;i<50;++i){
        newLst[i] = test_serv.dataConverter(gen.genString(50), std::to_string(gen.genFloat()), gen.genString(50), gen.genString(50));// NOLINT
        test_serv.modifica(ent_list[i],newLst[i]);// NOLINT
        assert(newLst[i] == test_serv.cauta(newLst[i].denumire, newLst[i].producator));// NOLINT
    
    }

}

void service_tests::destroy(){
    test_serv.repo.repo_list.clear();
}