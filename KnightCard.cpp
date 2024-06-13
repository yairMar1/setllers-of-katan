#include "KnightCard.hpp"

string KnightCard::getType() const{
    return "Knight";
}

void KnightCard::playCard(player &p, gameLogic& g){
    cout << p.getNameOfPlayer() << " played a Knight card" << endl;
    p.setKnightCards(1);
}
