#include "validator.h"
bool validator::validateName(std::string name){
    if(name.find_first_of("0987654321") != std::string::npos)
                return 0;
            
            return 1;
}

bool validator::validatePret(std::string pret){
    if(pret.find_first_of("qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM")!= std::string::npos)
            return 0;
        return 1;
}