#include "player.hpp"
#include "person.hpp"

#include <string>
#include <vector>
#include <iostream>

using namespace std;

player::player(string nameOfPlayer, size_t age) : person(nameOfPlayer, age){
}

void player::getNumberOfPoints(){
    cout << getNameOfPlayer() << " have " << numberOfPoints << " points" << endl;
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

void player::setResources(size_t resource, int amount){
    if(resource < 0 || resource > 4){
        cout << "Invalid resource" << endl;
        return;
    }
    resources[resource] += amount;
    cout << getNameOfPlayer() << " get: " << amount <<  " of " << getResources(resource) << endl;
}

void player::rollDice(board& b, gameLogic& g){
    myTurn = true;
    size_t dice1 = rand() % 6 + 1;
    size_t dice2 = rand() % 6 + 1;
    size_t sum = dice1 + dice2;
    cout << getNameOfPlayer() << " rolled: " << dice1 << " and " << dice2 << " the sum is: " << sum << endl;
    
    g.addResources(b, sum);
    
    //return sum;
}

// void player::placeSettelemnt(board& b, vertex* v, size_t n){
//     for(size_t i = 0; i < 19; i++){
//         for(size_t j = 0; j < 6; j++){
//             if(b.get_board()[i].getVertexes()[j]->getNumberId() == v->getNumberId()){
//                 if(b.get_board()[i].getVertexes()[j]->getIsClear()){ // If the vertex is clear
//                     b.get_board()[i].getVertexes()[j]->setIsClear(false); // Set the vertex to occupied
//                     cout << getNameOfPlayer() << " placed settlement on vertex " << v->getNumberId() << ", on junction: ";
//                     for(size_t k = 0; k < 19; k++){
//                         for(size_t l = 0; l < 6; l++){
//                             if(b.get_board()[k].getVertexes()[l]->getNumberId() == v->getNumberId()){
//                                 cout << b.get_board()[k].getNumber() << " " << b.get_board()[k].getTypeOfResource() << " ";
//                             }
//                         }
//                     }
//                     cout << endl;
//                     settlements.push_back(v);
//                     numberOfPoints += 1;
//                     return;
//                 }
//                 else{
//                     cout << "This vertex " << v->getNumberId() << " is already occupied, please choose another vertex" << endl;
//                     return;  // Exit the function if the vertex is occupied
//                 }
//             }
//         }
//     }
// }


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
    return;
}

void player::placeSettelemnt(board& b, vertex* v){
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
        else{
            cout << getNameOfPlayer() << ", You need to have two consecutive roads before placing a settlement on " << v->getNumberId() << ", choose another action" << endl;
            return;
        }
    }
}

// void player::placeRoad(board& b, edge* e){
//     for(size_t i = 0; i < 19; i++){
//         for(size_t j = 0; j < 6; j++){
//             if(b.get_board()[i].getEdges()[j]->getNameOfEdge() == e->getNameOfEdge()){
//                 if(b.get_board()[i].getEdges()[j]->getIsClear()){ // If the edge is clear
//                     b.get_board()[i].getEdges()[j]->setIsClear(false); // Set the edge to occupied
//                     cout << getNameOfPlayer() << " placed road on edge " << e->getNameOfEdge() << " on tile: ";
//                     for(size_t k = 0; k < 19; k++){
//                         for(size_t l = 0; l < 6; l++){
//                             if(b.get_board()[k].getEdges()[l]->getNameOfEdge() == e->getNameOfEdge()){
//                                 cout << b.get_board()[k].getNumber() << " " << b.get_board()[k].getTypeOfResource() << " ";
//                             }
//                         }
//                     }
//                     cout << endl;
//                     roads.push_back(e);
//                     return;
//                 }
//                 else{
//                     cout << "This edge " << e->getNameOfEdge() << " is already occupied, please choose another edge" << endl;
//                     return;  // Exit the function if the edge is occupied
//                 }
//             }
//         }
//     }
// }


void player::placeRoad(board& b, edge* e ,size_t n){
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