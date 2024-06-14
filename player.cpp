#include "player.hpp"
#include "deck.hpp"
#include "monopolyCard.hpp"
#include "roadBuildingCard.hpp"
#include "victoryPointCard.hpp"
#include "yearOfPlentyCard.hpp"
#include "KnightCard.hpp"

#include <string>
#include <vector>
#include <iostream>

using namespace std;

player::player(string nameOfPlayer, size_t age) : person(nameOfPlayer, age){
    developmentCards["Knight"] = 0;
    developmentCards["VictoryPoint"] = 0;
    developmentCards["YearOfPlenty"] = 0;
    developmentCards["Monopoly"] = 0;
    developmentCards["RoadBuilding"] = 0;
}

void player::getNumberOfPoints(){
    cout << getNameOfPlayer() << " have " << numberOfPoints << " points" << endl;
}

size_t player::getNumberOfPoints(size_t n){
    return numberOfPoints;
}

void player::setNumberOfPoints(size_t n){
    numberOfPoints += n;
}

size_t player::getMyTurn(){
    return myTurn;
}

void player::setMyTurn(bool b){
    myTurn = b;
}

void player::getCitys(){
    cout << "The citys of " << getNameOfPlayer() << ": ";
    for(size_t i = 0; i < citys.size(); i++){
        cout << citys[i]->getNumberId() << " ";
    }
    cout << endl;
}

vector<size_t> player::getCitys(int v){
    vector<size_t> temp;
    for(size_t i = 0; i < citys.size(); i++){
        temp.push_back(citys[i]->getNumberId());
    }
    return temp;
}

size_t player::getKnightCards(){
    return numberOfKnightCards;
}

void player::setKnightCards(size_t n){
    numberOfKnightCards += n;
    if(getKnightCards() == 3){ // check if the player has 3 knight cards
        cout << getNameOfPlayer() << " has 3 knight cards, he get 2 victory points" << endl;
        numberOfPoints += 2;
    }
}

void player::getSettlements(){
    cout << "The settlements of " << getNameOfPlayer() << ": ";
    for(size_t i = 0; i < settlements.size(); i++){
        cout << settlements[i]->getNumberId() << " ";
    }
    cout << endl;
}

vector<size_t> player::getSettlements(size_t i){
    vector<size_t> temp;
    for(size_t j = 0; j < settlements.size(); j++){
        temp.push_back(settlements[j]->getNumberId());
    }
    return temp;
}

void player::printPlayer(){
    cout << "Player: " << getNameOfPlayer() << " has " << numberOfPoints << " points, " << roads.size() << " roads, " << settlements.size() << " settlements, " << citys.size() << " citys" << endl;
}

void player::getResources(){
    cout << getNameOfPlayer() << " has: " << endl;
    cout << "Wood: " << resources[WOOD] << endl;
    cout << "Iron: " << resources[IRON] << endl;
    cout << "Wheat: " << resources[WHEAT] << endl;
    cout << "Sheep: " << resources[SHEEP] << endl;
    cout << "Clay: " << resources[CLAY] << endl;
}

string player::getResources(size_t resource){
    string res;
    if(resource < 0 || resource > 4){
        cout << "Invalid resource" << endl;
        return "Invalid resource";
    }
    if(resource == 0){
        res = "Wood";
    }
    else if(resource == 1){
        res = "Iron";
    }
    else if(resource == 2){
        res = "Wheat";
    }
    else if(resource == 3){
        res = "Sheep";
    }
    else if(resource == 4){
        res = "Clay";
    }
    return res;
}

size_t player::getResources(size_t resource, string s){
    if(resource == 0){
        return resources[WOOD];
    }
    else if(resource == 1){
        return resources[IRON];
    }
    else if(resource == 2){
        return resources[WHEAT];
    }
    else if(resource == 3){
        return resources[SHEEP];
    }
    else if(resource == 4){
        return resources[CLAY];
    }
    else{
        cout << "Invalid resource" << endl;
        return 0;
    }
}

size_t player::getAllResources(){
    size_t res = 0;
    for(size_t i = 0; i < 5; i++){
        res += resources[i];
    }
    return res;
}

void player::setResources(size_t resource, int amount){
    if(resource < 0 || resource > 4){
        cout << "Invalid resource" << endl;
        return;
    }
    resources[resource] += amount;
    cout << getNameOfPlayer() << " get: " << amount <<  " of " << getResources(resource) << endl;
}

void player::rollDice(board& b, gameLogic& g){
    if(hasRollDice == true){
        cout << getNameOfPlayer() << " already rolled the dice, choose another action" << endl;
        return;
    }
    if(g.getNumberTurn() == 1){ // if it's the first turn of the game that the dice will rolled
        g.getPlayer(0).setMyTurn(true);
        g.setNumberTurn(2);
    }
    if(getMyTurn() == false){ // if it's not the turn of the player
        cout << getNameOfPlayer() << " It's not your turn, please wait" << endl;
        return;
    }
    cout << getNameOfPlayer() << " start his turn" << endl;
    size_t dice1 = rand() % 6 + 1;
    size_t dice2 = rand() % 6 + 1;
    size_t sum = dice1 + dice2;
    cout << getNameOfPlayer() << " rolled: " << dice1 << " and " << dice2 << " the sum is: " << sum << endl;
    
    g.addResources(b, sum);
    hasRollDice = true;
}

void player::placeSettelemnt(board& b, vertex* v, size_t n){
    for(size_t i = 0; i < 19; i++){
        for(size_t j = 0; j < 6; j++){
            if(b.get_board()[i].getVertexes()[j]->getNumberId() == v->getNumberId()){
                if(b.get_board()[i].getVertexes()[j]->getIsClear() == false){ // If the vertex is not clear
                    cout << "The vertex " << v->getNumberId() << " is not clear, please choose another vertex" << endl;
                    return;
                }
            }
        }
    }

    for(size_t i = 0; i < 19; i++){
        for(size_t j = 0; j < 6; j++){
            if(b.get_board()[i].getEdges()[j]->getVertexA()->getNumberId() == v->getNumberId()){ // the other vertex on the egde is not clear
                if(b.get_board()[i].getEdges()[j]->getVertexB()->getIsClear() == false){
                    cout << "The next vertex is occupied, choose another vertex" << endl;
                    return;
                }
            }
        }
    }
    for(size_t i = 0; i < 19; i++){
        for(size_t j = 0; j < 6; j++){
            if(b.get_board()[i].getEdges()[j]->getVertexB()->getNumberId() == v->getNumberId()){ // the other vertex on the egde is not clear
                if(b.get_board()[i].getEdges()[j]->getVertexA()->getIsClear() == false){
                    cout << "The next vertex is occupied, choose another vertex" << endl;
                    return;
                }
            }
        }
    }
    v->setIsClear(false); // Set the vertex to occupied
    //b.get_board()[i].getVertexes()[j]->setIsClear(false); // Set the vertex to occupied (from the board)
    cout << getNameOfPlayer() << " placed settlement on vertex " << v->getNumberId() << ", on junction: ";
    for(size_t k = 0; k < 19; k++){
        for(size_t l = 0; l < 6; l++){
            if(b.get_board()[k].getVertexes()[l]->getNumberId() == v->getNumberId()){
                cout << b.get_board()[k].getNumber() << " " << b.get_board()[k].getTypeOfResource() << " ";
            }
        }
    }
    cout << endl;
    settlements.push_back(v);
    numberOfPoints += 1;
    // when the player place the first settlement he get the resources of the tile
    for (size_t i = 0; i < 19; i++){
        for (size_t j = 0; j < 6; j++){ // Go over the tile vertices
                    if (b.get_board()[i].getVertexes()[j]->getNumberId() == v->getNumberId()){ // if the settlement belongs to player
                        if (b.get_board()[i].getTypeOfResource() == "wood"){
                            setResources(WOOD, 1);
                            }
                            else if (b.get_board()[i].getTypeOfResource() == "iron"){
                            setResources(IRON, 1);
                            }
                            else if (b.get_board()[i].getTypeOfResource() == "wheat"){
                            setResources(WHEAT, 1);
                            }
                            else if (b.get_board()[i].getTypeOfResource() == "sheep"){
                            setResources(SHEEP, 1);
                            }
                            else if (b.get_board()[i].getTypeOfResource() == "clay"){
                            setResources(CLAY, 1);
                            }
                        }
                    }
                }
    return;
}

void player::placeSettelemnt(board& b, vertex* v){
    if(getMyTurn() == false){
        cout << "It's not your turn, please wait" << endl;
        return;
    }
    if(getResources(WOOD, "wood") < 1 || getResources(CLAY, "clay") < 1 || getResources(WHEAT, "wheat") < 1 || getResources(SHEEP, "sheep") < 1){ // cheack if the player has enough resources
        cout << "You don't have enough resources to build a settlement, choose another action" << endl;
        return;
    }
    for(size_t i = 0; i < 19; i++){
        for(size_t j = 0; j < 6; j++){
            if(b.get_board()[i].getVertexes()[j]->getNumberId() == v->getNumberId()){
                if(b.get_board()[i].getVertexes()[j]->getIsClear() == false){ // If the vertex is not clear
                    cout << "The vertex " << v->getNumberId() << " is not clear, please choose another vertex" << endl;
                    return;
                }
            }
        }
    }
    for(size_t i = 0; i < 19; i++){
        for(size_t j = 0; j < 6; j++){
            if(b.get_board()[i].getEdges()[j]->getVertexA()->getNumberId() == v->getNumberId()){ // the other vertex on the egde is not clear
                if(b.get_board()[i].getEdges()[j]->getVertexB()->getIsClear() == false){
                    cout << "The next vertex is occupied, choose another vertex" << endl;
                    return;
                }
            }
        }
    }
    for(size_t i = 0; i < 19; i++){
        for(size_t j = 0; j < 6; j++){
            if(b.get_board()[i].getEdges()[j]->getVertexB()->getNumberId() == v->getNumberId()){ // the other vertex on the egde is not clear
                if(b.get_board()[i].getEdges()[j]->getVertexA()->getIsClear() == false){
                    cout << "The next vertex is occupied, choose another vertex" << endl;
                    return;
                }
            }
        }
    }
    bool foundConsecutiveRoads = false;
    // Check if the player has a two consecutive roads before placing a settlement
    for(size_t i = 0; i < roads.size(); i++){
        if(roads[i]->getVertexA()->getNumberId() == v->getNumberId()){
            size_t adjacent = roads[i]->getVertexB()->getNumberId();
            size_t counter = 0;
            for(size_t j = 0; j < roads.size(); j++){
                if(roads[j]->getVertexA()->getNumberId() == adjacent || roads[j]->getVertexB()->getNumberId() == adjacent){
                    counter++;
                }
            }
            if(counter > 1){ // there is two consecutive roads that belong to the player
            foundConsecutiveRoads = true;
                v->setIsClear(false); // Set the vertex to occupied
                //b.get_board()[i].getVertexes()[j]->setIsClear(false); // Set the vertex to occupied (from the board)
                cout << getNameOfPlayer() << " placed settlement on vertex " << v->getNumberId() << ", on junction: ";
                for(size_t k = 0; k < 19; k++){
                    for(size_t l = 0; l < 6; l++){
                        if(b.get_board()[k].getVertexes()[l]->getNumberId() == v->getNumberId()){
                            cout << b.get_board()[k].getNumber() << " " << b.get_board()[k].getTypeOfResource() << " ";
                        }
                    }
                }
                cout << endl;
                settlements.push_back(v);
                numberOfPoints += 1;
                setResources(WOOD, -1);// payment for the settlement
                setResources(CLAY, -1);
                setResources(WHEAT, -1);
                setResources(SHEEP, -1);
                return;
            }
            else{
                cout << "You don't have two consecutive roads. you can't build here, choose another vertex" << endl;
                return;
            }
        }
        else if(roads[i]->getVertexB()->getNumberId() == v->getNumberId()){
            size_t adjacent = roads[i]->getVertexA()->getNumberId();
            size_t counter = 0;
            for(size_t j = 0; j < roads.size(); j++){
                if(roads[j]->getVertexA()->getNumberId() == adjacent || roads[j]->getVertexB()->getNumberId() == adjacent){
                    counter++;
                }
            }
            if(counter > 1){ // there is two consecutive roads that belong to the player
            foundConsecutiveRoads = true;
                v->setIsClear(false); // Set the vertex to occupied
                //b.get_board()[i].getVertexes()[j]->setIsClear(false); // Set the vertex to occupied (from the board)
                cout << getNameOfPlayer() << " placed settlement on vertex " << v->getNumberId() << ", on junction: ";
                for(size_t k = 0; k < 19; k++){
                    for(size_t l = 0; l < 6; l++){
                        if(b.get_board()[k].getVertexes()[l]->getNumberId() == v->getNumberId()){
                            cout << b.get_board()[k].getNumber() << " " << b.get_board()[k].getTypeOfResource() << " ";
                        }
                    }
                }
                cout << endl;
                settlements.push_back(v);
                numberOfPoints += 1;
                setResources(WOOD, -1); // payment for the settlement
                setResources(CLAY, -1);
                setResources(WHEAT, -1);
                setResources(SHEEP, -1);
                return;
            }
            else{
                cout << "You don't have two consecutive roads. you can't build here, choose another vertex" << endl;
                return;
            }
        }
    }
    if(foundConsecutiveRoads == false){ // If the player want to place settlement with no connection to his tool on the board
        cout << getNameOfPlayer() << ", You need to have two consecutive roads before placing a settlement on " << v->getNumberId() << ", choose another action" << endl;
        return;
    }
}

void player::placeCity(board &b, vertex *v){
    if(getMyTurn() == false){
        cout << "It's not your turn, please wait" << endl;
        return;
    }
    if(getResources(IRON, "iron") < 3 || getResources(WHEAT, "wheat") < 2){ // cheack if the player has enough resources
        cout << "You don't have enough resources to build a city, choose another action" << endl;
        return;
    }
    for(size_t i = 0; i < settlements.size(); i++){
        if(settlements[i]->getNumberId() == v->getNumberId()){
            cout << getNameOfPlayer() << " placed city on vertex " << v->getNumberId() << ", on junction: ";
            for(size_t k = 0; k < 19; k++){
                for(size_t l = 0; l < 6; l++){
                    if(b.get_board()[k].getVertexes()[l]->getNumberId() == v->getNumberId()){
                        cout << b.get_board()[k].getNumber() << " " << b.get_board()[k].getTypeOfResource() << " ";
                    }
                }
            }
            cout << endl;
            settlements.erase(settlements.begin() + i);
            numberOfPoints -= 1; // remove the settlement
            citys.push_back(v);
            numberOfPoints += 2; // add the city
            setResources(IRON, -3); // payment for the city
            setResources(WHEAT, -2);
            return;
        }
    }
    cout << getNameOfPlayer() << " You don't have a settlement on vertex " << v->getNumberId() << " choose another vertex" << endl;
    return;
}

void player::placeRoad(board &b, edge *e, size_t n){
    for(size_t i = 0; i < 19; i++){
        for(size_t j = 0; j < 6; j++){
            if(b.get_board()[i].getEdges()[j]->getNameOfEdge() == e->getNameOfEdge()){
                if(b.get_board()[i].getEdges()[j]->getIsClear()){ // If the edge is clear
                    // Check if the player has a settlement on one of the vertices of the edge
                    for(size_t k = 0; k < settlements.size(); k++){
                        if(settlements[k]->getNumberId() == e->getVertexA()->getNumberId() || settlements[k]->getNumberId() == e->getVertexB()->getNumberId()){ // If the player has a settlement on one of the vertices
                            cout << "You can place a road on this edge" << endl;
                            b.get_board()[i].getEdges()[j]->setIsClear(false); // Set the edge to occupied
                            cout << getNameOfPlayer() << " placed road on edge " << e->getNameOfEdge() << " on tile: ";
                            for(size_t k = 0; k < 19; k++){
                                for(size_t l = 0; l < 6; l++){
                                    if(b.get_board()[k].getEdges()[l]->getNameOfEdge() == e->getNameOfEdge()){
                                        cout << b.get_board()[k].getNumber() << " " << b.get_board()[k].getTypeOfResource() << " ";
                                    }
                                }
                            }
                            cout << endl;
                            roads.push_back(e);
                            return;
                        }
                    }
                    // Check if the player has a road on one of the vertices of the edge
                    for(size_t k = 0; k < roads.size(); k++){
                        if(roads[k]->getVertexA()->getNumberId() == e->getVertexA()->getNumberId() || roads[k]->getVertexB()->getNumberId() == e->getVertexA()->getNumberId() || roads[k]->getVertexA()->getNumberId() == e->getVertexB()->getNumberId() || roads[k]->getVertexB()->getNumberId() == e->getVertexB()->getNumberId()){ // If the player has a road on one of the vertices
                            cout << "You can place a road on this edge" << endl;
                            b.get_board()[i].getEdges()[j]->setIsClear(false); // Set the edge to occupied
                            cout << getNameOfPlayer() << " placed road on edge " << e->getNameOfEdge() << " on tile: ";
                            for(size_t k = 0; k < 19; k++){
                                for(size_t l = 0; l < 6; l++){
                                    if(b.get_board()[k].getEdges()[l]->getNameOfEdge() == e->getNameOfEdge()){
                                        cout << b.get_board()[k].getNumber() << " " << b.get_board()[k].getTypeOfResource() << " ";
                                    }
                                }
                            }
                            cout << endl;
                            roads.push_back(e);
                            return;
                        }
                        else{
                            cout << getNameOfPlayer() << ", although the vertex is free, it needs to have some connection to your tools on the board, choose another action" << endl;
                            return;
                        }
                    }
                }
                else{
                    cout << "This edge " << e->getNameOfEdge() << " is already occupied or you choose a wrong action, please choose another edge" << endl;
                    return;  // Exit the function if the edge is occupied
                } 
            }
        }
    }
}

void player::placeRoad(board& b, edge* e){
    if(getMyTurn() == false){
        cout << getNameOfPlayer() << " It's not your turn, please wait" << endl;
        return;
    }
    if(getResources(WOOD, "wood") < 1 || getResources(CLAY, "clay") < 1){ // cheack if the player has enough resources
        cout << "You don't have enough resources to build a road, choose another action" << endl;
        return;
    }
    for(size_t i = 0; i < 19; i++){
        for(size_t j = 0; j < 6; j++){
            if(b.get_board()[i].getEdges()[j]->getNameOfEdge() == e->getNameOfEdge()){
                if(b.get_board()[i].getEdges()[j]->getIsClear()){ // If the edge is clear
                    // Check if the player has a settlement on one of the vertices of the edge
                    for(size_t k = 0; k < settlements.size(); k++){
                        if(settlements[k]->getNumberId() == e->getVertexA()->getNumberId() || settlements[k]->getNumberId() == e->getVertexB()->getNumberId()){ // If the player has a settlement on one of the vertices
                            cout << "You can place a road on this edge" << endl;
                            b.get_board()[i].getEdges()[j]->setIsClear(false); // Set the edge to occupied
                            cout << getNameOfPlayer() << " placed road on edge " << e->getNameOfEdge() << " on tile: ";
                            for(size_t k = 0; k < 19; k++){
                                for(size_t l = 0; l < 6; l++){
                                    if(b.get_board()[k].getEdges()[l]->getNameOfEdge() == e->getNameOfEdge()){
                                        cout << b.get_board()[k].getNumber() << " " << b.get_board()[k].getTypeOfResource() << " ";
                                    }
                                }
                            }
                            cout << endl;
                            roads.push_back(e);
                            setResources(WOOD, -1); // payment for the road
                            setResources(CLAY, -1);
                            return;
                        }
                    }
                    // Check if the player has a road on one of the vertices of the edge
                    for(size_t k = 0; k < roads.size(); k++){
                        if(roads[k]->getVertexA()->getNumberId() == e->getVertexA()->getNumberId() || roads[k]->getVertexB()->getNumberId() == e->getVertexA()->getNumberId() || roads[k]->getVertexA()->getNumberId() == e->getVertexB()->getNumberId() || roads[k]->getVertexB()->getNumberId() == e->getVertexB()->getNumberId()){ // If the player has a road on one of the vertices
                            cout << "You can place a road on this edge" << endl;
                            b.get_board()[i].getEdges()[j]->setIsClear(false); // Set the edge to occupied
                            cout << getNameOfPlayer() << " placed road on edge " << e->getNameOfEdge() << " on tile: ";
                            for(size_t k = 0; k < 19; k++){
                                for(size_t l = 0; l < 6; l++){
                                    if(b.get_board()[k].getEdges()[l]->getNameOfEdge() == e->getNameOfEdge()){
                                        cout << b.get_board()[k].getNumber() << " " << b.get_board()[k].getTypeOfResource() << " ";
                                    }
                                }
                            }
                            cout << endl;
                            roads.push_back(e);
                            setResources(WOOD, -1); // payment for the road
                            setResources(CLAY, -1);
                            return;
                        }
                        else{
                            cout << getNameOfPlayer() << ", although the vertex is free, it needs to have some connection to your tools on the board, choose another action" << endl;
                            return;
                        }
                    }
                }
                else{
                    cout << "This edge " << e->getNameOfEdge() << " is already occupied or you choose a wrong action, please choose another edge" << endl;
                    return;  // Exit the function if the edge is occupied
                } 
            }
        }
    }
}

void player::getRoads(){
    cout << "The roads of " << getNameOfPlayer() << ": ";
    for(size_t i = 0; i < roads.size(); i++){
        cout << roads[i]->getNameOfEdge();
    }
    cout << endl;
}

void player::addDevelopmentCard(string s){
    if(s != "Knight" && s != "RoadBuilding" && s != "YearOfPlenty" && s != "Monopoly" && s != "VictoryPoint"){
        cout << "Invalid development card" << endl;
        return;
    }
    cout << getNameOfPlayer() << " get a development card: " << s << endl;
    developmentCards[s] += 1;
}

void player::buyDevelopmentCard(deck &d, gameLogic &g){
    if(getMyTurn() == false){
        cout << "It's not your turn, please wait" << endl;
        return;
    }
    if(getResources(WHEAT, "wheat") < 1 || getResources(SHEEP, "sheep") < 1 || getResources(IRON, "iron") < 1){ // cheack if the player has enough resources
        cout << getNameOfPlayer() << " don't have enough resources to buy a development card, choose another action" << endl;
        return;
    }
    setResources(WHEAT, -1); // payment for the development card
    setResources(SHEEP, -1);
    setResources(IRON, -1);
    //cout << getNameOfPlayer() << " bought a development card" << endl;
    addDevelopmentCard(d.drawCard()); // draw a card from the deck, and add it to the player's development cards
}

void player::playDevelopmentCard(gameLogic& g, deck& d, const string& cardType) {
    if (developmentCards[cardType] > 0) {
        if (cardType == "Knight") {
            KnightCard().playCard(*this, g);
            developmentCards[cardType]--; // the player can't the card twice
            return; // Knight cards should not return to the deck
        } else if (cardType == "RoadBuilding") {
            roadBuildingCard().playCard(*this, g);
        } else if (cardType == "YearOfPlenty") {
            yearOfPlentyCard().playCard(*this, g);
        } else if (cardType == "Monopoly") {
            monopolyCard().playCard(*this, g);
        } else if (cardType == "VictoryPoint") {
            victoryPointCard().playCard(*this, g);
            developmentCards[cardType]--; // the player can't the card twice
            return; // Victory point cards should not return to the deck
        } else {
            cout << "Unknown card type!" << endl;
            return;
        }
        developmentCards[cardType]--;
        d.addCard(cardType);
    } else {
        cout << "No " << cardType << " card available!" << endl;
    }
}

void player::printDevelopmentCards() {
    cout << getNameOfPlayer() << " development cards: " << endl;
    for (const auto& [cardType, count] : developmentCards) {
        std::cout << cardType << ": " << count << std::endl;
    }
}

void player::trade(player &p, size_t resource, size_t resource2, size_t resource3, size_t resource4, size_t resource5, size_t resource6, size_t resource7, size_t resource8, size_t resource9, size_t resource10)
{
    if(getMyTurn() == false){
        cout << "it's not your turn, please wait" << endl;
        return;
    }
    if(&p == this){
        cout << "You can't trade with yourself" << endl;
        return;
    }
    if(resource < 0 || resource2 < 0 || resource3 < 0 || resource4 < 0 || resource5 < 0 || resource6 < 0 || resource7 < 0 || resource8 < 0){
        cout << "Invalid trade" << endl;
        return;
    }
    if(p.getResources(WOOD,"resource") < resource || p.getResources(IRON,"resource") < resource2 || p.getResources(WHEAT,"resource") < resource3 || p.getResources(SHEEP,"resource") < resource4 || p.getResources(CLAY,"resource") < resource5){
        cout << "He don't have enough resources to trade" << endl;
        return;
    }
    if(getResources(WOOD,"resource") < resource6 || getResources(IRON,"resource") < resource7 || getResources(WHEAT,"resource") < resource8 || getResources(SHEEP,"resource") < resource9 || getResources(CLAY,"resource") < resource10){
        cout << "You don't have enough resources to trade" << endl;
        return;
    }

    cout << p.getNameOfPlayer() << ", " << getNameOfPlayer() << " wants to trade (give): " << resource << " wood, " << resource2 << " iron, " << resource3 << " wheat, " << resource4 << " sheep, " << resource5 << " clay" << ". for (receive): " << resource6 << " wood, " << resource7 << " iron, " << resource8 << " wheat, " << resource9 << " sheep, " << resource10 << " clay" << endl;
    cout << p.getNameOfPlayer() << ", would you like to accept the trade? (yes/no): ";
    string s;
    cin >> s;// get the answer from the player

    if((s != "yes" && s != "Yes") && (s != "no" && s != "No")){
        cout << "Trade canceled, invalid argument (option: yes or Yes, no or No)" << endl;
        return;
    }

    if(s == "no" || s == "No") {
        cout << "Trade canceled" << endl;
        return;
    }

    //**** the resources's change, other player ****
    p.setResources(WOOD, -resource);// remove the resources from the player
    p.setResources(IRON, -resource2);
    p.setResources(WHEAT, -resource3);
    p.setResources(SHEEP, -resource4);
    p.setResources(CLAY, -resource5);
    p.setResources(WOOD, resource6);// add the resources to the player
    p.setResources(IRON, resource7);
    p.setResources(WHEAT, resource8);
    p.setResources(SHEEP, resource9);
    p.setResources(CLAY, resource10);
    // **** the resources's change, this player ****
    setResources(WOOD, -resource6);// remove the resources from the player
    setResources(IRON, -resource7);
    setResources(WHEAT, -resource8);
    setResources(SHEEP, -resource9);
    setResources(CLAY, -resource10);
    setResources(WOOD, resource);// add the resources to the player
    setResources(IRON, resource2);
    setResources(WHEAT, resource3);
    setResources(SHEEP, resource4);
    setResources(CLAY, resource5);
    cout << "Trade completed" << endl;
    cout << "You receive from " << p.getNameOfPlayer() << ": " << resource << " wood, " << resource2 << " iron, " << resource3 << " wheat, " << resource4 << " sheep, " << resource5 << " clay" << endl;
    cout << "You give to " << p.getNameOfPlayer() << ": "  << resource6 << " wood, " << resource7 << " iron, " << resource8 << " wheat, " << resource9 << " sheep, " << resource10 << " clay" << endl;
}

void player::endTurn(gameLogic &g){
    cout << getNameOfPlayer() << " end his turn" << endl;
    hasRollDice = false;
    g.nextTurn();
}
