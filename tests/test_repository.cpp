#include "test_repository.h"
#include <assert.h>

void test_addElem(){
    generator gen;
    repository test_subject;
    for(int i=0;i<10000;++i){
        entity aux = gen.genEntity();

        int code = test_subject.addElem(aux);
        assert(test_subject.getElem(code) == aux);
        assert(test_subject.getNrElems() - 1 == i);
    }
    assert(test_subject.getNrElems() == 10000);

}

void test_removeElem(){
    generator gen;
    repository test_subject;
    vector<int>codes;
    for(int i=0;i<10000;++i){

        entity aux = gen.genEntity();
        codes.push_back(test_subject.addElem(aux));
    }
    
    for(int i=0;i<10000;i+=2){
        test_subject.removeElem(codes[i]);
    }
    assert(test_subject.getNrElems() == 5000);
    
    for(int i=1;i<10000;i+=2){
        test_subject.removeElem(codes[i]);
    }
    assert(test_subject.getNrElems() == 0);

}

void test_changeElement(){
    generator gen;
    repository test_subject;
    vector<entity> memory;
    vector<int>codes;

    for(int i=0;i<10000;++i){
        entity aux = gen.genEntity();
        memory.push_back(aux);

        codes.push_back(test_subject.addElem(aux));
    }
    for(int i=0;i<10000;++i){
        entity aux = gen.genEntity();

        if(i % 2 == 0){
            test_subject.changeElement(codes[i], aux);
            assert(aux == test_subject.getElem(codes[i]));
        }
        else
            assert(memory[i] == test_subject.getElem(codes[i]));
    }

}


void test_getAll(){
    generator gen;
    repository test_subject;
    vector<int>codes;

    for(int i=0;i<10000;++i){
        entity aux = gen.genEntity();

        codes.push_back(test_subject.addElem(aux));
    }

    iter_pair res = test_subject.getAll();


    for(int i=0;i<test_subject.getNrElems() && res.first != res.second; ++res.first, ++i){
        assert(*(res.first) == test_subject.getElem(codes[i]));
    }

}
void test_sort(){
    repository auxiliary;
    vector<int>codes;
    codes.push_back(auxiliary.addElem(entity("aaaa",100,"bbbb","cccc")));
    codes.push_back(auxiliary.addElem(entity("aaaa",200,"bbbb","aaaa")));
    codes.push_back(auxiliary.addElem(entity("bbbb",300,"aaaa","bbbb")));
    codes.push_back(auxiliary.addElem(entity("cccc",400,"aaaa","cccc")));

    auxiliary.sortElems(0);
    assert(auxiliary.getElem(codes[0]).getPrice() == 100);
    auxiliary.sortElems(1);
    assert(auxiliary.getElem(codes[0]).getPrice() == 300);
    auxiliary.sortElems(2);
    assert(auxiliary.getElem(codes[0]).getPrice() == 200);

}

void test_repository(){
    test_addElem();
    test_removeElem();
    test_changeElement();
    test_getAll();
    test_sort();
    
}