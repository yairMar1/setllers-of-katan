#include "person.hpp"

#include <string>
#include <vector>
#include <iostream>

using namespace std;

person::person(string name, size_t age) : nameOfPlayer(name), age(age){
}

string person::getNameOfPlayer(){
    return nameOfPlayer;
}

size_t person::getAge(){
    return age;
}
