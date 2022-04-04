#include "service.h"

void service::adauga(entity to_add){
    try{
        repo.adauga_repo(to_add);
    }
    catch(ErrorClass &e){
        //de adaugat error handling
    }
}

void service::sterge(entity to_delete){
    
    try{
        IT pos = repo.cauta_repo(to_delete);
        repo.sterge_repo(pos);
    
    }catch(ErrorClass &e){

    }
    
}


void service::modifica(entity current, entity modifications){
        IT pos = repo.cauta_repo(current);
        *pos = modifications;
}

entity service::cauta(std::string denumire, std::string producator){

    if(val.validateName(denumire) && val.validateName(producator)){
        pair<IT, IT> res = repo.get_all_repo();

        for(;res.first!=res.second;++res.first){
            if((*res.first).denumire == denumire && (*res.first).producator == producator)
            {
                return *res.first;
            }
        }
    }
    return NULL_ENTITY();
}
pair<IT, IT> service::all(){
    return repo.get_all_repo();
}
entity service::dataConverter(std::string nume, std::string pret, std::string producator, std::string substanta_activa){
    entity nil = NULL_ENTITY();
    try{
        if(!val.validateName(nume)){
            //raise error
            std::cerr<<"Nume gresit!\n";
            return nil;

        }
        if(!val.validatePret(pret)){
            //raise error
            std::cerr<<"Pret gresit!\n";
            return nil;


        }
        if(!val.validateName(producator)){
            //raise error
            std::cerr<<"Producator gresit!\n";
            return nil;

        }
        entity brandNew = repo.create_entity(nume,std::stof(pret),producator,substanta_activa);
        return brandNew;
    }catch(ErrorClass& e){
        //error handling
    }
    return nil;
}

unsigned long service::size(){
    return repo.size();
}
