#pragma once

#ifndef __entity_h_
/* code */
#include "../entities/entity.h"
#endif //__entity_h_

#include <vector>

class repository_tests;

typedef std::vector<entity>::iterator IT; 

template<typename type1, typename type2>
class pair{
    
    private:

    public:
        
        type1 first;
        type2 second;

        pair(type1 first_elem, type2 second_elem);

};

//template<class vector>
class service_tests;
class repository{
    friend class repository_tests;
    friend class service_tests;
    private:
        std::vector<entity> repo_list;

    public:

    unsigned long size()const;

    entity create_entity(std::string denumire, float pret, std::string producator, std::string substanta_activa);

    void adauga_repo(const entity to_add);

    IT cauta_repo(entity to_search);

    void sterge_repo(IT pos);

    void modifica_repo(IT pos,const entity clone);

    pair<IT,IT> get_all_repo();

    entity get_elem_repo(IT pos) const;

    bool is_elem_in_repo(const entity to_search);

};