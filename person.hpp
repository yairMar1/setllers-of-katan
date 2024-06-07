#ifndef PERSON_HPP
#define PERSON_HPP

#include <string>
#include <vector>
#include <iostream>

using namespace std;

class person
{
private:
    string nameOfPlayer;
    size_t age;
public:
    person(string nameOfPlayer, size_t age);
    string getNameOfPlayer();
    size_t getAge();
};
#endif // PERSON_HPP