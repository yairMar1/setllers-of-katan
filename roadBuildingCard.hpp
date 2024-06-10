#ifndef ROADBUILDINGCARD_HPP
#define ROADBUILDINGCARD_HPP

#include <string>
#include <vector>
#include <iostream>

using namespace std;

class roadBuildingCard : public developmentCard{
public:
    string getType() const override{
        return "Road Building";
    }
    //~RoadBuildingCard() = default;
    void playCard(){
        cout << "You played a Road Building card" << endl;
    }
};
#endif // ROADBUILDINGCARD_HPP