#include "test_repository.h"
#include <assert.h>

void test_addElem(){
    generator gen;
    repository test_subject;
    for(int i=0;i<10000;++i){
        entity aux = gen.genEntity();

        test_subject.addElem(aux);
        assert(test_subject.getElem(i) == aux);
        assert(test_subject.getNrElems() - 1 == i);
    }
    assert(test_subject.getNrElems() == 10000);

}

void test_removeElem(){
    generator gen;
    repository test_subject;
    for(int i=0;i<10000;++i){

        entity aux = gen.genEntity();
        test_subject.addElem(aux);
    }
    
    for(int i=0;i<10000;i+=2){
        test_subject.removeElem(i);
    }
    assert(test_subject.getNrElems() == 5000);
    
    for(int i=1;i<10000;i+=2){
        test_subject.removeElem(i);
    }
    assert(test_subject.getNrElems() == 0);

}

void test_changeElement(){
    generator gen;
    repository test_subject;
    vector<entity> memory;
    for(int i=0;i<10000;++i){
        entity aux = gen.genEntity();
        memory.push_back(aux);

        test_subject.addElem(aux);
    }
    for(int i=0;i<10000;i+=2){
        entity aux = gen.genEntity();

        test_subject.changeElement(i, aux);

        if(i % 2 == 0)
            assert(aux == test_subject.getElem(i));
        else
            assert(memory[i] == test_subject.getElem(i));
    }

}


void test_getAll(){
    generator gen;
    repository test_subject;

    for(int i=0;i<10000;++i){
        entity aux = gen.genEntity();

        test_subject.addElem(aux);
    }

    iter_pair res = test_subject.getAll();


    for(int i=0;i<test_subject.getNrElems() && res.first != res.second; ++res.first, ++i){
        assert(*(res.first) == test_subject.getElem(i));
    }

}
void test_sort(){
    repository auxiliary;
    auxiliary.addElem(entity("aaaa",100,"bbbb","cccc"));
    auxiliary.addElem(entity("aaaa",200,"bbbb","aaaa"));
    auxiliary.addElem(entity("bbbb",300,"aaaa","bbbb"));
    auxiliary.addElem(entity("cccc",400,"aaaa","cccc"));

    auxiliary.sortElems(0);
    assert(auxiliary.getElem(0).getPrice() == 100);
    auxiliary.sortElems(1);
    assert(auxiliary.getElem(0).getPrice() == 300);
    auxiliary.sortElems(2);
    assert(auxiliary.getElem(0).getPrice() == 200);

}

void test_repository(){
    test_addElem();
    test_removeElem();
    test_changeElement();
    test_getAll();
    test_sort();
    
}