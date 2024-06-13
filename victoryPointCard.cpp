#include "victoryPointCard.hpp"

string victoryPointCard::getType() const{
    return "Victory Point";
}

void victoryPointCard::playCard(player &p, gameLogic& g){
    cout << p.getNameOfPlayer() << " played a Victory Point card" << endl;
    p.setNumberOfPoints(1);
}

