#include "repository_tests.h"
#include <assert.h>
#include "../generator/generator.h"
#include <algorithm>

repository_tests::repository_tests(){
    tests.push_back(&repository_tests::test_create_entity);
    tests.push_back(&repository_tests::test_adauga_repo);
    tests.push_back(&repository_tests::test_cauta_repo);
    tests.push_back(&repository_tests::test_sterge_repo);
    tests.push_back(&repository_tests::test_modifica_repo);
    tests.push_back(&repository_tests::test_get_all_repo);
    tests.push_back(&repository_tests::test_get_elem_repo);
    tests.push_back(&repository_tests::test_is_elem_in_repo);
}
    

void repository_tests::test_create_entity(){
    entity a = test_repo.create_entity("asdf",200,"gwege","ageges");

    assert(a.denumire == "asdf");
    assert(a.pret == 200);
    assert(a.producator == "gwege");
    assert(a.substanta_activa == "ageges");
}

void repository_tests::build(){
    randomGenerator gen;
    
    for(int i=0;i<50;++i){
        list_of_entities[i] = test_repo.create_entity(gen.genString(50),gen.genFloat(),gen.genString(50),gen.genString(50));// NOLINT
    }
    for(int i=0;i<50;++i){
        test_repo.adauga_repo(list_of_entities[i]);// NOLINT
    }
    
    // std::reverse(test_repo.repo_list.begin(), test_repo.repo_list.end());

}

void repository_tests::test_adauga_repo(){
    assert(test_repo.size() == 50);

    for(int i=0;i<50;++i){
        entity test_against = test_repo.repo_list[i];
        assert(test_against == list_of_entities[i]);// NOLINT
    }
    
}

void repository_tests::test_cauta_repo(){
    
    for(int i=0;i<50;++i){
        IT res = test_repo.cauta_repo(list_of_entities[i]);// NOLINT
        assert(*res == list_of_entities[i]);// NOLINT
    }

}

void repository_tests::test_sterge_repo(){
    for(int i=0;i<50;++i){
        IT res = test_repo.cauta_repo(list_of_entities[i]);// NOLINT
        test_repo.sterge_repo(res);
        assert(test_repo.size() ==(unsigned long) 50-i-1);
    }
    assert(test_repo.size() == 0);
}

void repository_tests::test_modifica_repo(){
    randomGenerator gen;
    entity newList[50]; // NOLINT
    for(int i=0;i<50;++i){
        newList[i] = test_repo.create_entity(gen.genString(50),gen.genFloat(),gen.genString(50),gen.genString(50)); // NOLINT
    }
    for(int i=0;i<50;++i){
        IT res = test_repo.cauta_repo(list_of_entities[i]); // NOLINT
        test_repo.modifica_repo(res, newList[i]); // NOLINT

        assert(newList[i] == *res);// NOLINT
    }
}

void repository_tests::test_get_all_repo(){
    pair<IT, IT> res = test_repo.get_all_repo();
    
    assert(res.second - res.first == 50);
}

void repository_tests::test_get_elem_repo(){
    pair<IT, IT> res = test_repo.get_all_repo();
    for(int i=0;i<50 && res.first!=res.second;++res.first, ++i){
        assert(test_repo.get_elem_repo(res.first) == list_of_entities[i]);// NOLINT
    }
}
void repository_tests::test_is_elem_in_repo(){
    randomGenerator gen;
    for(int i=0;i<50; ++i){
        assert(test_repo.is_elem_in_repo(list_of_entities[i]) == 1);// NOLINT
    }
    assert(test_repo.is_elem_in_repo(test_repo.create_entity(gen.genString(50), gen.genFloat(),gen.genString(50),gen.genString(50)))==0);
}

void repository_tests::destroy(){
    test_repo.repo_list.clear();
}

void repository_tests::run(){
    for(auto i : tests){
        build();

        (this->*i)();

        destroy();

    }
}

repository_tests::~repository_tests(){
    return;
}
