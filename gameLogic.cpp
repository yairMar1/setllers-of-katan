#include "gameLogic.hpp"

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

gameLogic::gameLogic(vector<player> &player) : players(player) {}

size_t gameLogic::getNumberTurn(){
    return numberTurn;
}

void gameLogic::setNumberTurn(size_t n){
    numberTurn = n;
}

player& gameLogic::getPlayer(int index) {
    return players[index];
}

void gameLogic::chooseFirstPlayer(){

    vector<player> temp = {players[0], players[1], players[2]};
    sort(temp.begin(), temp.end(), [](player &a, player &b){ return a.getAge() > b.getAge(); });// sort the players by age
    players = temp;

    cout << "The first player is: " << players[0].getNameOfPlayer() << endl;
    cout << "The second player is: " << players[1].getNameOfPlayer() << endl;
    cout << "The third player is: " << players[2].getNameOfPlayer() << endl;
}

void gameLogic::nextTurn(){
    for(size_t i = 0; i < 3; i++){
        if(players[i].getMyTurn() == true){// find the player that his turn is now
            players[i].setMyTurn(false);  // end the turn of the player
            players[(i+1)%3].setMyTurn(true); // set the turn of the next player
            cout << "The next player is: " << players[(i+1)%3].getNameOfPlayer() << endl;
            return;
        }
    }
}

void gameLogic::addResources(board &b, size_t sum){
//**** if the dices show 7 */
    if(sum == 7){
        for(size_t i = 0; i < 3; i++){ // go over the players
            if(players[i].getAllResources() > 7){ // if player have more than 7 resources

                size_t count = players[i].getAllResources()/2; // the player will return half of the resources
                for(size_t j = 0; j < count; j++){
                    if(players[i].getResources(j%5, "resource") > 0){
                        players[i].setResources(j%5, -1); // go over the resources, and remove from wood to clay each time one resource if it more than 0
                    }
                }
            }
        }
    }
//**** if the dices don't show 7 */
    for (size_t i = 0; i < 19; i++){
        if (b.get_board()[i].getNumber() == sum){ // if the number of the tile is equal to the sum of the dice
            if (b.get_board()[i].getHasRobbed() == false){ // if the tile has not been robbed
                for (size_t j = 0; j < 6; j++){ // Go over the tile vertices
                    if (b.get_board()[i].getVertexes()[j]->getIsClear() == false){ // we found a settlement or a city
                        for (size_t l = 0; l < 3; l++){
                            for (size_t k = 0; k < players[l].getSettlements(1).size(); k++){
                                if (b.get_board()[i].getVertexes()[j]->getNumberId() == players[l].getSettlements(1)[k]){ // if the settlement belongs to player
                                    if (b.get_board()[i].getTypeOfResource() == "wood"){
                                        players[l].setResources(WOOD, 1);
                                    }
                                    else if (b.get_board()[i].getTypeOfResource() == "iron"){
                                        players[l].setResources(IRON, 1);
                                    }
                                    else if (b.get_board()[i].getTypeOfResource() == "wheat"){
                                        players[l].setResources(WHEAT, 1);
                                    }
                                    else if (b.get_board()[i].getTypeOfResource() == "sheep"){
                                        players[l].setResources(SHEEP, 1);
                                    }
                                    else if (b.get_board()[i].getTypeOfResource() == "clay"){
                                        players[l].setResources(CLAY, 1);
                                    }
                                }
                            }
                            for(size_t k = 0; k < players[l].getCitys(1).size(); k++){
                                if (b.get_board()[i].getVertexes()[j]->getNumberId() == players[l].getCitys(1)[k]){ // if the city belongs to player
                                    if (b.get_board()[i].getTypeOfResource() == "wood"){
                                        players[l].setResources(WOOD, 2);
                                    }
                                    else if (b.get_board()[i].getTypeOfResource() == "iron"){
                                        players[l].setResources(IRON, 2);
                                    }
                                    else if (b.get_board()[i].getTypeOfResource() == "wheat"){
                                        players[l].setResources(WHEAT, 2);
                                    }
                                    else if (b.get_board()[i].getTypeOfResource() == "sheep"){
                                        players[l].setResources(SHEEP, 2);
                                    }
                                    else if (b.get_board()[i].getTypeOfResource() == "clay"){
                                        players[l].setResources(CLAY, 2);
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

string gameLogic::gameFhinished(){
    string res;
    for(size_t i = 0; i < 3; i++){
        if(players[i].getNumberOfPoints(1) > 9){
            res =  players[i].getNameOfPlayer() + " is the winner, he got 10 points";
            return res;
        }
    }
    res = "There is no winner";
    return res;
}
