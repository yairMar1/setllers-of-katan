#ifndef VICTORYPOINTCARD_HPP
#define VICTORYPOINTCARD_HPP

#include "developmentCard.hpp"
#include "player.hpp"

using namespace std;

class victoryPointCard : public developmentCard {
public:
    string getType() const override;
    void playCard(player& p, gameLogic& g) override;
    //~victoryPointCard() = default;
};

#endif // VICTORYPOINTCARD_HPP