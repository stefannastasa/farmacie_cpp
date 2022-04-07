#include "repository.h"

void bubble_sort(Lista<entity>& lst, bool(*comparator)(entity a, entity b)){
    
    bool changed = true;

    while(changed){
        changed = false;
        int size = lst.getNrElems();
        for(int i = 0;i<size-1;++i){
            for(int j = i+1;j<size;++j){
                if(!comparator(*(lst.begin()+i), *(lst.begin()+j))){
                    swap(*(lst.begin()+i), *(lst.begin()+j));
                    changed = true;
                }
            }
        }

    }   
}

physical repository::find(int pos){
    return list.begin()+pos;
}

repository::repository():nrElems{0}{}

void repository::addElem(entity to_add){
    list.push_back(to_add);
    ++nrElems;
}

void repository::removeElem(int pos){

    physical location = find(pos);
    list.erase(location);
    --nrElems;
}

void repository::changeElement(int pos, entity updated){
    physical location = find(pos);
    
    if(updated.getName() != "")
        location->setName(updated.getName());
        
    if(updated.getPrice() != -1)
        location->setPrice(updated.getPrice());
    
    if(updated.getManufacturer() != "")
        location->setManufacturer(updated.getManufacturer());
    
    if(updated.getSubstance() != "")
        location->setSubstance(updated.getSubstance());

}

iter_pair repository::getAll(){
    return iter_pair(list.begin(),list.end());
}

int repository::getNrElems(){
    return nrElems;
}

entity repository::getElem(int pos){
    return *(find(pos));
}
void repository::DESTROY(){
    list.clear();
}

bool comparator_nume(entity a, entity b){
    if(a.getName() == b.getName())
        return a.getPrice() < b.getPrice();
    
    return a.getName() < b.getName();
}

bool comparator_manufacturer(entity a, entity b){
    if(a.getManufacturer() == b.getManufacturer())
        return a.getPrice() < b.getPrice();
    
    return a.getManufacturer() < b.getManufacturer();
}

bool comparator_substance(entity a, entity b){
    if(a.getSubstance() == b.getSubstance())
        return a.getPrice() < b.getPrice();
    
    return a.getSubstance() < b.getSubstance();
}


void repository::sortElems(int clause){
    switch(clause){
        case 0:
            bubble_sort(list, &comparator_nume);
            break;
        case 1:
            bubble_sort(list, &comparator_manufacturer);
            break;
        case 2:
            bubble_sort(list, &comparator_substance);
            break;            
    }
}
