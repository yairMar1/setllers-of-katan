#pragma once

#include <string>
#include <iostream>
using namespace std;

class vertex{

private:
    size_t numberId;
    bool isClear = true;
public:
    vertex(size_t number);
    
    size_t getNumberId();
    bool getIsClear();
    void setIsClear(bool isClear);
    void printVertex();
};