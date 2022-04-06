#include "service.h"


void service::addElem(string name, string price, string manufacturer, string substance){
    try{
        valid.validateAll(name, price, manufacturer, substance);
    }catch(ValidationError& e){
        throw e;
    }
    entity to_add(name, stof(price), manufacturer, substance);

    repo.addElem(to_add);
}

void service::deleteElem(int pos){
    if(pos < repo.getNrElems())
        repo.removeElem(pos);
    else{
        throw RangeError("Index out of range");
    }

}

void service::changeElem(int pos, string name, string price, string manufacturer, string substance){
    entity modif("", 0, "", "");
    entity actual = repo.getElem(pos);

    try{
        valid.validateName(name);
        modif.setName(name);
    }catch(ValidationError& e){
        if(e.getMessage() == "invalid"){
            modif.setName(actual.getName());
        }
    }

    try{
        valid.validateName(price);
        modif.setPrice(stof(price));
    }catch(ValidationError& e){
        if(e.getMessage() == "invalid"){
            modif.setPrice(actual.getPrice());
        }
    }

    try{
        valid.validateName(manufacturer);
        modif.setManufacturer(manufacturer);
    }catch(ValidationError& e){
        if(e.getMessage() == "invalid"){
            modif.setManufacturer(actual.getManufacturer());
        }
    }

    try{
        valid.validateName(substance);
        modif.setSubstance(substance);
    }catch(ValidationError& e){
        if(e.getMessage() == "invalid"){
            modif.setSubstance(actual.getSubstance());
        }
    }

    if(pos > repo.getNrElems())
        throw RangeError("Index out of range");
    else{
        repo.changeElement(pos, modif);
    }

}


iter_pair service::getAll(){
    return repo.getAll();
}

int service::getNrElems(){
    return repo.getNrElems();
}


entity service::searchElem(string name, string manufacturer){
    iter_pair meds = repo.getAll();
    for(;meds.first!=meds.second;++meds.first){
        if(name == meds.first->getName() && manufacturer == meds.first->getManufacturer()){
            return *(meds.first);
        }
    }
    throw RangeError("No element found");
}

iter_pair service::filterElems_afterPrice(string price){
    
    try{
        valid.validatePrice(price);
        filter.DESTROY();
    }catch(ValidationError& e){
        throw e;
    }

    float p = stof(price);


    iter_pair res = repo.getAll();
    physical start = res.first;
    physical end = res.second;


    for(;start!=end;++start){
        if(start->getPrice() == p){
            filter.addElem(*(start));
        }
    }

    return filter.getAll();
}


iter_pair service::filterElems_afterSubstance(string substance){
    
    try{
        valid.validatePrice(substance);
        filter.DESTROY();
    }catch(ValidationError& e){
        throw e;
    }

    iter_pair res = repo.getAll();
    physical start = res.first;
    physical end = res.second;

    
    for(;start!=end;++start){
        if(start->getSubstance() == substance){
            filter.addElem(*(start));
        }
    }

    return filter.getAll();
}

iter_pair service::filterElems_afterName(string name){
    
    try{
        valid.validatePrice(name);
        filter.DESTROY();
    }catch(ValidationError& e){
        throw e;
    }

    iter_pair res = repo.getAll();
    physical start = res.first;
    physical end = res.second;

    
    for(;start!=end;++start){
        if(start->getSubstance() == name){
            filter.addElem(*(start));
        }
    }
    return filter.getAll();
}

iter_pair service::filterElems(string attr, int clause){
    switch (clause)
    {
    case 1:
        try{
            return filterElems_afterName(attr);
        }catch(ValidationError& e){
            throw e;
        }
        break;
    
    case 2:
        try{
            return filterElems_afterPrice(attr);
        }catch(ValidationError& e){
            throw e;
        }
        break;
    case 3:
        try{
            return filterElems_afterSubstance(attr);
        }catch(ValidationError& e){
            throw e;
        }
        break;
    }

    throw RangeError("Invalid crit.");
}

void service::sortElems(int clause){
    repo.sortElems(clause);
}

entity service::getElem(int pos){
    return repo.getElem(pos);
}