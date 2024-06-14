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
    if(resource1 < 0 || resource1 > 4){
        cout << "invalid resource" << endl;
        return;
    }
    // add the resource to the player
    if (resource1 == 0){
        cout << "the resource you chose is: wood " << endl;
        p.setResources(WOOD, 1);
    }else if (resource1 == 1){
        cout << "the resource you chose is: iron " << endl;
        p.setResources(IRON, 1);
    }else if (resource1 == 2){
        cout << "the resource you chose is: wheat " << endl;
        p.setResources(WHEAT, 1);
    }else if (resource1 == 3){
        cout << "the resource you chose is: sheep " << endl;
        p.setResources(SHEEP, 1);
    }else if (resource1 == 4){
        cout << "the resource you chose is: clay " << endl;
        p.setResources(CLAY, 1);
    }
    cout << "choose the number of the sesource you want" << endl;
    int resource2;
    cin >> resource2;
    if(resource2 < 0 || resource2 > 4){
        cout << "invalid resource" << endl;
        return;
    }
    // add the resource to the player
    if (resource2 == 0){
        cout << "the resource you chose is: wood " << endl;
        p.setResources(WOOD, 1);
    }else if (resource2 == 1){
        cout << "the resource you chose is: iron " << endl;
         p.setResources(IRON, 1);
    }else if (resource2 == 2){
        cout << "the resource you chose is: wheat " << endl;
        p.setResources(WHEAT, 1);
    }else if (resource2 == 3){
        cout << "the resource you chose is: sheep " << endl;
        p.setResources(SHEEP, 1);
    }else if (resource2 == 4){
        cout << "the resource you chose is: clay " << endl;
        p.setResources(CLAY, 1);
    }
}
