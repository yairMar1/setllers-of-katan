#ifndef YEAROFPLENTYCARD_HPP
#define YEAROFPLENTYCARD_HPP

#include <string>
#include <vector>
#include <iostream>

using namespace std;

class yearOfPlentyCard : public developmentCard{
public:
    string getType() const override{
        return "Year of Plenty";
    }
    //~YearOfPlentyCard() = default;
    void playCard(){
        cout << "You played a Year of Plenty card" << endl;
    }
};
#endif // YEAROFPLENTYCARD_HPP