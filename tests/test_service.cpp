#include "test_service.h"

void test_addElemS() {
    service test_subject;
    generator gen;

    for (int i = 0; i < 100; ++i) {
        test_subject.addElem(gen.genString(), "100", gen.genString(), gen.genString());
        assert(test_subject.getNrElems() == i + 1);
    }
    // test invalid name
    try {
        test_subject.addElem("-1", "1000", gen.genString(), gen.genString());
    }
    catch (const ValidationError& e) {
        assert(e.getMessage() == "invalid");
    }
    try {
        test_subject.addElem("", "1000", gen.genString(), gen.genString());
    }
    catch (const ValidationError& e) {
        assert(e.getMessage() == "Niciun nume primit");
    }
    try {
        test_subject.addElem("1254", "1000", gen.genString(), gen.genString());
    }
    catch (const ValidationError& e) {
        assert(e.getMessage() == "Numele nu poate contine valori numerice");
    }

    //test invalid price
    try {
        test_subject.addElem(gen.genString(), "-1", gen.genString(), gen.genString());
    }
    catch (const ValidationError& e) {
        assert(e.getMessage() == "invalid");
    }
    try {
        test_subject.addElem(gen.genString(), "", gen.genString(), gen.genString());
    }
    catch (const ValidationError& e) {
        assert(e.getMessage() == "Niciun pret primit");
    }
    try {
        test_subject.addElem(gen.genString(), "10a0", gen.genString(), gen.genString());
    }
    catch (const ValidationError& e) {
        assert(e.getMessage() == "Pretul nu poate contine litere");
    }

    //test invalid manufacturer
    try {
        test_subject.addElem(gen.genString(), "1000", "-1", gen.genString());
    }
    catch (const ValidationError& e) {
        assert(e.getMessage() == "invalid");
    }
    try {
        test_subject.addElem(gen.genString(), "1000", "", gen.genString());
    }
    catch (const ValidationError& e) {
        assert(e.getMessage() == "Niciun producator primit");
    }
    try {
        test_subject.addElem(gen.genString(), "1000", "123", gen.genString());
    }
    catch (const ValidationError& e) {
        assert(e.getMessage() == "Producatorul nu poate contine valori numerice");
    }

    //test invalid substance
    try {
        test_subject.addElem(gen.genString(), "1000", gen.genString(), "-1");
    }
    catch (const ValidationError& e) {
        assert(e.getMessage() == "invalid");
    }
    try {
        test_subject.addElem(gen.genString(), "1000", gen.genString(), "");
    }
    catch (const ValidationError& e) {
        assert(e.getMessage() == "Nicio substanta primita");
    }

}

void test_deleteElemS() {
    service test_subject;
    generator gen;

    for (int i = 0; i < 100; ++i) {
        test_subject.addElem(gen.genString(), "1000", gen.genString(), gen.genString());

    }
    for (int i = 0; i < 50; ++i) {
        test_subject.deleteElem(i);
    }

    try {
        test_subject.deleteElem(51);
    }
    catch (const RangeError& e) {
        assert(e.getMessage() == "Index out of range");
    }

    assert(test_subject.getNrElems() == 50);
}

void test_changeElemS() {
    service test_subject;
    generator gen;

    for (int i = 0; i < 100; ++i) {
        test_subject.addElem(gen.genString(), "100", gen.genString(), gen.genString());
    }
    for (int i = 0; i < 100; ++i) {
        entity aux(gen.genString(), 1000, gen.genString(), gen.genString());
        test_subject.changeElem(i, aux.getName(), "1000", aux.getManufacturer(), gen.genString());
        assert(test_subject.getElem(i) == aux);
    }
    try {
        test_subject.changeElem(101, gen.genString(), "1000", gen.genString(), gen.genString());
    }
    catch (const RangeError& e) {
        assert(e.getMessage() == "Index out of range");
    }
    try {
        test_subject.changeElem(2, "-1", "-1", "-1", "-1");
    }
    catch (const ValidationError& e) {
        assert(e.getMessage() == "invalid");
    }
    try {
        test_subject.changeElem(2, gen.genString(), "-1", "-1", "-1");
    }
    catch (const ValidationError& e) {
        assert(e.getMessage() == "invalid");
    }
    try {
        test_subject.changeElem(2, gen.genString(), "100", "-1", "-1");
    }
    catch (const ValidationError& e) {
        assert(e.getMessage() == "invalid");
    }
    try {
        test_subject.changeElem(2, gen.genString(), "100", gen.genString(), "-1");
    }
    catch (const ValidationError& e) {
        assert(e.getMessage() == "invalid");
    }

}

void test_searchElemS() {
    service test_subject;

    test_subject.addElem("asdf", "1000", "asdf", "asdf");
    test_subject.addElem("oooo", "1000", "asdf", "asdf");
    test_subject.addElem("bbbb", "1000", "asdf", "asdf");
    test_subject.addElem("cccc", "1000", "asdf", "asdf");

    assert(test_subject.searchElem("oooo", "asdf") == entity("oooo", 1000, "asdf", "asdf"));
    assert(test_subject.searchElem("bbbb", "asdf") == entity("bbbb", 1000, "asdf", "asdf"));
    assert(test_subject.searchElem("cccc", "asdf") == entity("cccc", 1000, "asdf", "asdf"));
    try {
        assert(test_subject.searchElem("bbbc", "asrf") == entity("bbbb", 1000, "asdf", "asdf"));
    }
    catch(const RangeError &e) {
        assert(e.getMessage() == "No element found");
    }
}

void test_filterElems() {
    service test_subject;

    test_subject.addElem("dddd", "1126", "eeee", "yyyy");
    test_subject.addElem("oooo", "2738", "bbbb", "tttt");
    test_subject.addElem("bbbb", "9384", "zzzz", "pppp");
    test_subject.addElem("cccc", "1287", "wwww", "aaaa");

    iter_pair result;

    // test prim criteriu
    result = test_subject.filterElems("oooo", 1);
    assert(result.first->getSubstance() == "tttt");
    try {
        result = test_subject.filterElems("-1", 1);
    }
    catch (const ValidationError& e) {
        assert(e.getMessage() == "invalid");
    }

    // test al doilea criteriu
    result = test_subject.filterElems("9384", 2);
    assert(result.first->getName() == "bbbb");
    try {
        result = test_subject.filterElems("-1", 2);
    }
    catch (const ValidationError& e) {
        assert(e.getMessage() == "invalid");
    }

    // test al treilea criteriu
    result = test_subject.filterElems("aaaa", 3);
    assert(result.first->getName() == "cccc");
    try {
        result = test_subject.filterElems("-1", 3);
    }
    catch (const ValidationError& e) {
        assert(e.getMessage() == "invalid");
    }

    // test criteriu invalid
    try {
        result = test_subject.filterElems("-1", 4);
    }
    catch (const RangeError& e) {
        assert(e.getMessage() == "Invalid crit.");
    }

    // test getAll()
    result = test_subject.getAll();
    assert(result.first->getName() == "dddd");
}


void test_service(){
    test_addElemS();
    test_deleteElemS();
    test_changeElemS();
    test_searchElemS();
    test_filterElems();
}