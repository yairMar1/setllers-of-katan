#ifndef DEVELOPMENTCARD_HPP
#define DEVELOPMENTCARD_HPP

#include <string>
#include <vector>
#include <iostream> 
// #include "player.hpp"

class player;
class gameLogic;
using namespace std;

class developmentCard{
public:
    virtual string getType() const = 0;
    virtual void playCard(player& p, gameLogic& g) = 0;
    //virtual ~developmentCard() = default;
};
#endif // DEVELOPMENTCARD_HPP