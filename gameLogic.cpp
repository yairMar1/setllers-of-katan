#include "player.hpp"
#include "gameLogic.hpp"

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

gameLogic::gameLogic(vector<player>& player) : players(player){}

void gameLogic::chooseFirstPlayer(){
    vector<player> temp = {players[0], players[1], players[2]};
    sort(temp.begin(), temp.end(), [](player &a, player &b){return a.getAge() > b.getAge();});
    players = temp;

    cout << "The first player is: " << players[0].getNameOfPlayer() << endl; 
    cout << "The second player is: " << players[1].getNameOfPlayer() << endl; 
    cout << "The third player is: " << players[2].getNameOfPlayer() << endl;
}

void gameLogic::addResources(board& b, size_t sum){
    for(size_t i = 0; i < 19; i++){
        if(b.get_board()[i].getNumber() == sum){ // if the number of the tile is equal to the sum of the dice
            if(b.get_board()[i].getHasRobbed() == false){ // if the tile has not been robbed
                for(size_t j = 0; j < 6; j++){ // Go over the tile vertices
                    if(b.get_board()[i].getVertexes()[j]->getIsClear() == false){ // we found a settlement or a city
                    for(size_t l = 0; l < 3; l++){
                        for(size_t k = 0; k < 6; k++){
                        if(b.get_board()[i].getVertexes()[j]->getNumberId() == players[l].getSettlements(1)[k]){ // if the settlement belongs to player
                                if(b.get_board()[i].getTypeOfResource() == "wood"){
                                    players[l].setResources(WOOD, 1);
                                }
                                else if(b.get_board()[i].getTypeOfResource() == "iron"){
                                    players[l].setResources(IRON, 1);
                                }
                                else if(b.get_board()[i].getTypeOfResource() == "wheat"){
                                    players[l].setResources(WHEAT, 1);
                                }
                                else if(b.get_board()[i].getTypeOfResource() == "sheep"){
                                    players[l].setResources(SHEEP, 1);
                                }
                                else if(b.get_board()[i].getTypeOfResource() == "clay"){
                                    players[l].setResources(CLAY, 1);
                                }
                            }
                        }
                            // else if(b.get_board()[i].getVertexes()[j]->getCity() == true){
                            //     if(b.get_board()[i].getTypeOfResource() == "wood"){
                            //         players[0].setResources(WOOD, players[0].getResources()[WOOD] + 2);
                            //     }
                            //     else if(b.get_board()[i].getTypeOfResource() == "iron"){
                            //         players[0].setResources(IRON, players[0].getResources()[IRON] + 2);
                            //     }
                            //     else if(b.get_board()[i].getTypeOfResource() == "wheat"){
                            //         players[0].setResources(WHEAT, players[0].getResources()[WHEAT] + 2);
                            //     }
                            //     else if(b.get_board()[i].getTypeOfResource() == "sheep"){
                            //         players[0].setResources(SHEEP, players[0].getResources()[SHEEP] + 2);
                            //     }
                            //     else if(b.get_board()[i].getTypeOfResource() == "clay"){
                            //         players[0].setResources(CLAY, players[0].getResources()[CLAY] + 2);
                            //     }
                            // }
                        }
                    }
                }
            }
        }
    }
}

