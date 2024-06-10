#ifndef KNIGHTCARD_HPP
#define KNIGHTCARD_HPP

#include <string>
#include <vector>
#include <iostream>

using namespace std;

class KnightCard : public developmentCard{
    KnightCard(){
        if(count >3){
            throw std::invalid_argument("Cannot create more than 3 Knight Cards");
        }
        count++;
    }
    ~KnightCard(){
        count--;
    }
public:
    string getType() const override{
        return "Knight";
    }
    void playCard(){
        cout << "You played a Knight card" << endl;

    }
};
#endif // KNIGHTCARD_HPP