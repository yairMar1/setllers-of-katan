#include "roadBuildingCard.hpp"

string roadBuildingCard::getType() const {
    return "Road Building";
}

void roadBuildingCard::playCard(player &p, gameLogic& g){
    cout << p.getNameOfPlayer() <<" played a Road Building card" << endl;
    // the player can build two roads for free
    p.setResources(WOOD,2);
    p.setResources(CLAY,2);
}
