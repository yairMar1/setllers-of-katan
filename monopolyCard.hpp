#ifndef MONOPOLYCARD_HPP
#define MONOPOLYCARD_HPP

#include <string>
#include <vector>
#include <iostream>

using namespace std;

class monopolyCard : public developmentCard{
public:
    string getType() const override{
        return "Monopoly";
    }
    //~MonopolyCard() = default;
    void playCard(){
        cout << "You played a Monopoly card" << endl;
    }
};
#endif // MONOPOLYCARD_HPP