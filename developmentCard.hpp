#ifndef DEVELOPMENTCARD_HPP
#define DEVELOPMENTCARD_HPP

#include <string>
#include <vector>
#include <iostream>

using namespace std;

class developmentCard{
public:
    virtual string getType() const = 0;
    virtual ~DevelopmentCard() = default;
};
#endif // DEVELOPMENTCARD_HPP