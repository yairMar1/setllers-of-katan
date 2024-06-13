#ifndef ROADBUILDINGCARD_HPP
#define ROADBUILDINGCARD_HPP

#include <string>
#include <vector>
#include <iostream>
#include "developmentCard.hpp"
#include "player.hpp"

using namespace std;

class roadBuildingCard : public developmentCard{
public:
    string getType() const override;
    //~roadBuildingCard() = default;
    void playCard(player& p, gameLogic& g) override;
};
#endif // ROADBUILDINGCARD_HPP