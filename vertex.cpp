#include "vertex.hpp"

#include <string>
#include <iostream>

using namespace std;

vertex::vertex(size_t number) : numberId(number){
    //cout << "Vertex created with number: " << number << endl;
}
    
size_t vertex::getNumberId(){
    return numberId;
}

bool vertex::getIsClear(){
    return isClear;
}

void vertex::setIsClear(bool boolValue){
    if(isClear == true){
        this->isClear = boolValue;
        //cout << "The boolean value in " << getNumberId() << ", had been changed" << endl;
    }else{
        cout << "Vertex is already occupied" << endl;
    }
}

void vertex::printVertex(){
    cout << "Number ID: " << numberId << endl;
    cout << "Is Clear: " << isClear << endl << endl;
}
