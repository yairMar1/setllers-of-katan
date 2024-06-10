#ifndef VICTORYPOINTCARD_HPP
#define VICTORYPOINTCARD_HPP

#include <string>
#include <vector>
#include <iostream>

using namespace std;

class victoryPointCard : public developmentCard{
public:
    string getType() const override{
        return "Victory Point";
    }
    //~VictoryPointCard() = default;
    void playCard(){
        cout << "You played a Victory Point card" << endl;
    }
};
#endif // VICTORYPOINTCARD_HPP