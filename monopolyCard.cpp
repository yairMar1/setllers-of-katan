#include "monopolyCard.hpp"

string monopolyCard::getType() const {
    return "Monopoly";
}

void monopolyCard::playCard(player &p, gameLogic& g){
    cout << "You played a Monopoly card" << endl;
    cout << "Choose a resource to take from all the other players" << endl;
    size_t resource;
    cin >> resource;
    if(resource < 0 || resource > 4){
        cout << "Invalid resource" << endl;
        return;
    }
    cout << "You chose to take " << resource << " from all the other players" << endl;
    for(size_t i = 0; i < 3; i++){
        if(g.getPlayer(i).getNameOfPlayer() != p.getNameOfPlayer()){
            p.setResources(resource, p.getResources(resource, "resource") + g.getPlayer(i).getResources(resource, "resource")); // add the resource to the player
            g.getPlayer(i).setResources(resource, 0); // remove the resource from the other players
        }
    }
}