#include "test_service.h"

void test_addElemS(){
    service test_subject;
    generator gen;

    for(int i=0;i<1000;++i){
        test_subject.addElem(gen.genString(),"1000",gen.genString(), gen.genString());
        assert(test_subject.getNrElems() == i + 1);
    }

    try{
        test_subject.addElem(gen.genString(),"10a0",gen.genString(), gen.genString());
    }catch(ValidationError& e){
        assert(e.getMessage() =="Pretul nu poate contine litere");
    }
    try{
        test_subject.addElem("1254","1000",gen.genString(), gen.genString());
    }catch(ValidationError& e){
        assert(e.getMessage() == "Numele nu poate contine valori numerice");
    }
    try{
        test_subject.addElem(gen.genString(),"1000","123", gen.genString());
    }catch(ValidationError& e){
        assert(e.getMessage() == "Producatorul nu poate contine valori numerice");
    }
    
    try{
        test_subject.addElem(gen.genString(),"1000",gen.genString(), "");
    }catch(ValidationError& e){
        assert(e.getMessage() =="Nicio substanta primita");
    }

}

void test_deleteElemS(){
    service test_subject;
    generator gen;

    for(int i=0;i<1000;++i){
        test_subject.addElem(gen.genString(),"1000",gen.genString(), gen.genString());
        
    }
    for(int i=0;i<100;++i){
        test_subject.deleteElem(i);
    }
    assert(test_subject.getNrElems() == 900);
}

void test_changeElemS(){
    service test_subject;
    generator gen;

    for(int i=0;i<1000;++i){
        test_subject.addElem(gen.genString(),"1000",gen.genString(), gen.genString());
    }
    for(int i=0;i<1000;++i){
        entity aux(gen.genString(),1000,gen.genString(), gen.genString());
        test_subject.changeElem(i,aux.getName(),"1000", aux.getManufacturer(), gen.genString());
        assert(test_subject.getElem(i) == aux);
    }

}

void test_searchElemS(){
    service test_subject;
    // generator gen;

    test_subject.addElem("asdf", "1000", "asdf", "asdf");
    test_subject.addElem("oooo", "1000", "asdf", "asdf");
    test_subject.addElem("bbbb", "1000", "asdf", "asdf");
    test_subject.addElem("cccc", "1000", "asdf", "asdf");

    assert(test_subject.searchElem("oooo","asdf") == entity("oooo", 1000, "asdf", "asdf"));
    assert(test_subject.searchElem("bbbb","asdf") == entity("bbbb", 1000, "asdf", "asdf"));
    assert(test_subject.searchElem("cccc","asdf") == entity("cccc", 1000, "asdf", "asdf"));
}

void test_service(){
    test_addElemS();
    test_deleteElemS();
    test_changeElemS();
    test_searchElemS();
}