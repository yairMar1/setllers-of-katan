#ifndef YEAROFPLENTYCARD_HPP
#define YEAROFPLENTYCARD_HPP

#include "developmentCard.hpp"
#include "player.hpp"

using namespace std;

class yearOfPlentyCard : public developmentCard{
public:
    string getType() const override;
    //~yearOfPlentyCard() = default;
    void playCard(player& p, gameLogic& g) override;
};
#endif // YEAROFPLENTYCARD_HPP