#ifndef MONOPOLYCARD_HPP
#define MONOPOLYCARD_HPP

#include <string>
#include <vector>
#include <iostream>
#include "developmentCard.hpp"
#include "gameLogic.hpp"
#include "player.hpp"

using namespace std;

class monopolyCard : public developmentCard{
public:
    string getType() const override;
    //~monopolyCard() = default;
    void playCard(player& p, gameLogic& g) override;
};
#endif // MONOPOLYCARD_HPP