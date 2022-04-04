#include "repository.h"
#include <string>

template<typename type1, typename type2>
pair<type1,type2>::pair(type1 first_elem, type2 second_elem):first{first_elem}, second{second_elem}{};

entity repository::create_entity(std::string denumire, float pret, std::string producator, std::string substanta_activa){
    
    //place for validators

    entity a;

    a.denumire = denumire;
    a.pret = pret;
    a.producator = producator;
    a.substanta_activa = substanta_activa;


    return a;
}

void repository::adauga_repo(const entity to_add){
    if(is_elem_in_repo(to_add) == 0)
        repo_list.push_back(to_add);
    else{
        //error raise
    }
}

IT repository::cauta_repo(entity to_search)// entity must be in repository 
{
    for(std::vector<entity>::iterator i = repo_list.begin();i!=repo_list.end();++i){
        if(*i == to_search)
            return i;
    }
    return repo_list.end();
}

void repository::sterge_repo(IT pos){
    repo_list.erase(pos);
}

void repository::modifica_repo(IT pos, entity clone){
    *pos = clone;
}

pair<IT, IT> repository::get_all_repo(){
    
    return pair<IT,IT>(repo_list.begin(), repo_list.end());
}

entity repository::get_elem_repo(IT pos) const{
    return *pos;
}

bool repository::is_elem_in_repo(const entity to_search){
    for(std::vector<entity>::iterator i = repo_list.begin();i!=repo_list.end();++i){
        if(*i == to_search)
            return 1;
    }

    return 0;
}

unsigned long repository::size() const{
    return repo_list.size();
}