#pragma once
#include <unistd.h>
#include <string>
class randomGenerator{
    private:
        int maxSize = 50;
    public:
        std::string genString(const int maxSize);

        float genFloat();
};
