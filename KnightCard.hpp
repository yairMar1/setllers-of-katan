#ifndef KNIGHTCARD_HPP
#define KNIGHTCARD_HPP

#include <string>
#include <vector>
#include <iostream>
#include "developmentCard.hpp"
#include "player.hpp"

using namespace std;

class KnightCard : public developmentCard{
public:
    string getType() const override;
    //~KnightCard() = default;
    void playCard(player& p, gameLogic& g) override;
};
#endif // KNIGHTCARD_HPP