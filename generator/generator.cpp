#include "generator.h"
#include <iostream>

std::string randomGenerator::genString(int maxSize){

    char alpha[]="qwertyuiopasdfghjklzxcvbnm";// NOLINT
    std::string gen;
    for(int i=0;i<maxSize;++i){
        gen += alpha[rand() % (sizeof(alpha) - 1)];// NOLINT
    }
    
    return gen;
}

float randomGenerator::genFloat(){
    return (float)(rand() % 1001);
}
