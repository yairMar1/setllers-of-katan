#include "yearOfPlentyCard.hpp"

#include <string>
#include <vector>
#include <iostream>

string yearOfPlentyCard::getType() const {
    return "Year of Plenty";
}

void yearOfPlentyCard::playCard(player &p, gameLogic& g){
    cout << p.getNameOfPlayer() << " played a Year of Plenty card" << endl;
    
    cout << "choose the number of the sesource you want" << endl;
    int resource1;
    cin >> resource1;
    cout << "the resource you chose is: " << resource1 << endl;
    if(resource1 < 0 || resource1 > 4){
        cout << "invalid resource" << endl;
        return;
    }
    // add the resource to the player
    if(resource1 == 0){
        p.setResources(WOOD, 1);
    }
    else if(resource1 == 1){
        p.setResources(IRON, 1);
    }
    else if(resource1 == 2){
        p.setResources(WHEAT, 1);
    }
    else if(resource1 == 3){
        p.setResources(SHEEP, 1);
    }
    else if(resource1 == 4){
        p.setResources(CLAY, 1);
    }
    cout << "choose the number of the sesource you want" << endl;
    int resource2;
    cin >> resource2;
    cout << "the resource you chose is: " << resource2 << endl;
    if(resource2 < 0 || resource2 > 4){
        cout << "invalid resource" << endl;
        return;
    }
    // add the resource to the player
    if(resource2 == 0){
        p.setResources(WOOD, 1);
    }
    else if(resource2 == 1){
        p.setResources(IRON, 1);
    }
    else if(resource2 == 2){
        p.setResources(WHEAT, 1);
    }
    else if(resource2 == 3){
        p.setResources(SHEEP, 1);
    }
    else if(resource2 == 4){
        p.setResources(CLAY, 1);
    }
}
