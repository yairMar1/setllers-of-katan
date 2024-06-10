#include <string>
#include <vector>
#include <iostream>
#include <ctime>

#include "vertex.hpp"
#include "edge.hpp"
#include "tile.hpp"
#include "board.hpp"
#include "player.hpp"
#include "person.hpp"
#include "gameLogic.hpp"

using namespace std;

int main(){
    player p1("yair", 25);
    player p2("david", 19);
    player p3("shlomo", 20);
    
    vector<player> p = {p1, p2, p3};
    gameLogic g1(p);
    g1.chooseFirstPlayer();
    board b;
    
    cout << endl;
    // cout << p[0].getNameOfPlayer() << endl;
    // cout << p[1].getNameOfPlayer() << endl;
    // cout << p[2].getNameOfPlayer() << endl;
    // cout << endl;
 
    // for(size_t i = 0; i < 19; i++){//Information about edges and vertices of a specific tile
    //     if(b.get_board()[i].getTypeOfResource() == "iron" && b.get_board()[i].getNumber() == 10){
    //         for(size_t j = 0; j < 6; j++){
    //             b.get_board()[i].getEdges()[j]->printEdge();
    //         }
    //         for(size_t j = 0; j < 6; j++){
    //             b.get_board()[i].getVertexes()[j]->printVertex();
    //         }
    //     }
    // }
    // cout << endl;
    
    //First turn of the game - each player places a settlement and a road on the board
    p[0].placeSettelemnt(b, b.get_board()[0].getVertexes()[3], 1);// set v31 as a settlement
    p[0].getSettlements();
    p[0].placeRoad(b, b.get_board()[0].getEdges()[2], 1);// set e2 as a road
    p[0].getRoads();
    p[0].getNumberOfPoints();
    cout << endl;
    //********* second player try to place a settlement and a road on the same vertex and edge **********
    p[1].placeSettelemnt(b,b.get_board()[1].getVertexes()[4], 1);// set v31 as a settlement, but it is already occupied
    p[1].getSettlements();
    p[1].placeRoad(b,b.get_board()[0].getEdges()[2], 1);// set e2 as a settlement, but it is already occupied
    p[1].getRoads();
    p[1].getNumberOfPoints();
    //********* second player place a settlement and a road on another vertex and edge **********
    cout << endl;
    p[1].placeSettelemnt(b,b.get_board()[12].getVertexes()[1], 1);// set v43 as a settlement
    p[1].getSettlements();
    p[1].placeRoad(b,b.get_board()[12].getEdges()[3], 1);// set e49 as a settlement
    p[1].getRoads();
    p[1].getNumberOfPoints();
    cout << endl;

    p[2].placeSettelemnt(b,b.get_board()[10].getVertexes()[0], 1);// set v36 as a settlement
    p[2].getSettlements();
    p[2].placeRoad(b,b.get_board()[10].getEdges()[4], 1);// set e30 as a settlement
    p[2].getRoads();
    p[2].getNumberOfPoints();
    cout << endl;
    //second turn of the game - each player places a settlement and a road on the board
    p[0].placeSettelemnt(b,b.get_board()[7].getVertexes()[2], 1);// set v46 as a settlement
    p[0].getSettlements();
    p[0].placeRoad(b,b.get_board()[7].getEdges()[2], 1);// set e32 as a road
    p[0].getRoads();
    p[0].getNumberOfPoints();
    cout << endl;

    p[1].placeSettelemnt(b,b.get_board()[15].getVertexes()[0], 1);// set v12 as a settlement
    p[1].getSettlements();
    p[1].placeRoad(b,b.get_board()[15].getEdges()[4], 1);// set e48 as a road
    p[1].getRoads();
    p[1].getNumberOfPoints();
    cout << endl;

    p[2].placeSettelemnt(b,b.get_board()[17].getVertexes()[5], 1);// set v41 as a settlement
    p[2].getSettlements();
    p[2].placeRoad(b,b.get_board()[17].getEdges()[4], 1);// set e54 as a road
    p[2].getRoads();
    p[2].getNumberOfPoints();
    cout << endl;
    //b.get_board().at(4).getVertexes().at(1)->printVertex();

    // The game continues with the rest of the turns, each player roll the dice and do the actions that he can do (place a settlement, place a road, buy a development card, trade, end turn)
    
    srand(time(0)); // ensure that the random number will be different each time
    
    // for(size_t i = 0; i < 5; i++){
    // p[0].rollDice(b, g1);
    // }
    // cout << endl;
    // p[0].getResources();
    // cout << endl;
    // p[1].getResources();
    // cout << endl;
    // p[2].getResources();
    // //********** player 1 try to place a settlement and road, detached from his tools on the board **********
    // // p[0].placeSettelemnt(b,b.get_board()[0].getVertexes()[1]);// set v1 as a settlement
    // // p[0].getSettlements();
    // // p[0].placeRoad(b,b.get_board()[0].getEdges()[0]);// set e0 as a road
    // // p[0].getRoads();
    // // p[0].getNumberOfPoints();
    // // cout << endl;


    // //********** player 1 try to place a settlement and road, but he doesn't have enough resources**********
    // p[0].rollDice(b, g1);
    // cout << endl;
    // p[0].getResources();
    // cout << endl;
    // p[0].placeSettelemnt(b,b.get_board()[0].getVertexes()[1]);// set v1 as a settlement
    // p[0].getSettlements();
    // p[0].placeRoad(b,b.get_board()[0].getEdges()[0]);// set e0 as a road
    // p[0].getRoads();
    // p[0].getNumberOfPoints();
    // cout << endl;


    // //********** player 1 place a road, settlement and city. he have enough resources. we can see the amount of his resources get down**********
    // for(size_t i = 0; i < 100; i++){
    //     p1.rollDice(b, g1);
    // }
    // cout << endl;
    // p[0].getResources();
    // cout << endl;
    // p[0].placeRoad(b, b.get_board()[0].getEdges()[1]);// set e1 as a road
    // p[0].getResources();
    // cout << endl;
    // p[0].placeSettelemnt(b, b.get_board()[0].getVertexes()[1]);// set v1 as a settlement
    // p[0].getResources();
    // p[0].getSettlements();
    // p[0].getNumberOfPoints();
    // cout << endl;
    // p[0].placeCity(b, b.get_board()[0].getVertexes()[1]);// set v1 as a city
    // p[0].getResources();
    // p[0].getSettlements();
    // p[0].getCitys();
    // p[0].getNumberOfPoints();
    // cout << endl;

    for(size_t i = 0; i < 10; i++){ // we can see that if dice show 10, player 1 ,get 2 iron from tile 10
        p[0].rollDice(b, g1);
    }
    cout << endl;

    // //********** player 1 try to trade with player 2 **********
    // p[0].getResources();
    // cout << endl;
    // p[1].getResources();
    // cout << endl;
    // p[0].trade(p[1], 1, 0, 0, 0, 0, 0, 0, 0, 1, 0);// player 1 ask, 1 wood for 1 sheep
    // cout << endl;
    // p[0].getResources();
    // cout << endl;
    // p[1].getResources();
    // cout << endl;

    //********** another player try to ineterupt to another player turn **********
    p[0].rollDice(b, g1);
    cout << endl;
    p[1].placeRoad(b, b.get_board()[0].getEdges()[1]);
    cout << "is the turn of yair ? " << p[0].getMyTurn() << endl;
    p[0].endTurn(g1);
    cout << "is the turn of yair ? " << p[0].getMyTurn() << endl;

    p[0].rollDice(b, g1);// player 1 try to roll the dice again after he end his turn
    cout << endl;
    p[2].rollDice(b, g1); // player 3 try to bypass the turn
    cout << endl;
    p[1].rollDice(b, g1); // player 2 roll the dice, the turn is now of player 2
    cout << endl;



   

    //b.printBoard();
    // for(size_t i = 0; i < 19; i++){ // all vertices that are clear
    // cout << "tile " << b.get_board()[i].getNumber() << ": "<< b.get_board()[i].getTypeOfResource() << endl << endl;
    //     for (size_t j = 0; j < 6; j++){
    //         if(b.get_board()[i].getVertexes()[j].getIsClear() == 0){
    //             //cout << "vertex: " << j << "not clear" << endl;
    //             cout << "vertex: " << b.get_board()[i].getVertexes()[j].getNumberId() << " clear" << endl;
    //         }
    //     }
    // }
    // for(size_t i = 0; i < 19; i++){ // all edges that are clear
    // cout << "tile " << b.get_board()[i].getNumber() << ": "<< b.get_board()[i].getTypeOfResource() << endl << endl;
    //     for (size_t j = 0; j < 6; j++){
    //         if(b.get_board()[i].getEdges()[j].getIsClear() == 0){
    //             vector<size_t> nameOfEdge = b.get_board()[i].getEdges()[j].getNameOfEdge();
    //             for(size_t k = 0; k < 2; k++){
    //                 cout << nameOfEdge[k] << " ";
    //             }
    //             cout << endl;
    //             //cout << "edge: " << b.get_board()[i].getEdges()[j].getNameOfEdge()[k] << " clear" << endl;
    //         }
    //     }
    // }
// cout << "*************************************************" << endl;
//     for(size_t i = 0; i < 19; i++){//Information about edges and vertices of a specific tile
//         if(b.get_board()[i].getTypeOfResource() == "iron" && b.get_board()[i].getNumber() == 10){
//             for(size_t j = 0; j < 6; j++){
//                 b.get_board()[i].getEdges()[j]->printEdge();
//             }
//             for(size_t j = 0; j < 6; j++){
//                 b.get_board()[i].getVertexes()[j]->printVertex();
//             }
//         }
//     }

// cout << "*************************************************" << endl;
//      for(size_t i = 0; i < 19; i++){//Information about edges and vertices of a specific tile
//         if(b.get_board()[i].getTypeOfResource() == "sheep" && b.get_board()[i].getNumber() == 2){
//             for(size_t j = 0; j < 6; j++){
//                 b.get_board()[i].getEdges()[j]->printEdge();
//             }
//             for(size_t j = 0; j < 6; j++){
//                 b.get_board()[i].getVertexes()[j]->printVertex();
//             }
//         }
//     }
    return 0;
}