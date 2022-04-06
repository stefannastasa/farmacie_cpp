#include "../entity/entity.h"
#include <assert.h>

void test_entity(){
    entity auxiliary("denumire", 100, "alfa", "beta");

    assert(auxiliary.getName() == "denumire");
    assert(auxiliary.getPrice() == 100);
    assert(auxiliary.getManufacturer() == "alfa" );
    assert(auxiliary.getSubstance() == "beta" );

    auxiliary.setName("aaaa");
    auxiliary.setPrice(200);
    auxiliary.setManufacturer("aaaa");
    auxiliary.setSubstance("aaaa");

    assert(auxiliary.getName() == "aaaa");
    assert(auxiliary.getPrice() == 200);
    assert(auxiliary.getManufacturer() == "aaaa" );
    assert(auxiliary.getSubstance() == "aaaa" );
    
}