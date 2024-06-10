#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "edge.hpp"
#include "vertex.hpp"
#include "tile.hpp"
#include "board.hpp"
#include "person.hpp"
#include "gameLogic.hpp"

#include <string>
#include <vector>
#include <iostream>
# define WOOD 0
# define IRON 1
# define WHEAT 2
# define SHEEP 3
# define CLAY 4

class player : public person
{
private:
    size_t numberOfPoints = 0;
    vector<edge*> roads;
    vector<vertex*> settlements;
    vector<vertex*> citys;
    vector<size_t> resources = {0,0,0,0,0};
    bool myTurn = false;
    bool hasRollDice = false;
public:
    //Access to a player's fields
    player(string nameOfPlayer, size_t age);
    void getNumberOfPoints();
    size_t getMyTurn();
    void setMyTurn(bool b);
    void getCitys(); // print the citys of the player
    vector<size_t> getCitys(int v); // function i use in gameLogic.cpp to get the vector of city's player

    void printPlayer(); // print ditails of the player
    void getResources(); // print the resources of the player
    string getResources(size_t resource); // function to get the resources of the player
    size_t getResources(size_t resource, string s); // function to get the amount of specipic resources
    void setResources(size_t resource, int amount); // function to set the resources of the player (add or remove, there is a refrence in case of city or settlement)

    //Actions that player can do
    void rollDice(board& b, gameLogic& g);
    void placeSettelemnt(board& b, vertex* v, size_t n); // for the two first action of the player (need less checks)
    void placeSettelemnt(board& b, vertex* v); // for the rest action of the player (need more checks)
    void getSettlements(); // print the settlements of the player
    vector<size_t> getSettlements(size_t i); // function i use in gameLogic.cpp to get the vector of settlement's player

    void placeCity(board& b, vertex* v);
    void placeRoad(board& b, edge* e,size_t n);// for the two first action of the player (need less checks)
    void placeRoad(board& b, edge* e);  // for the rest action of the player (need more checks)
    void getRoads();

    void buyDevelopmentCard();
    // the four number is the resources that the player want to trade, the last four is the resources that the player want to get (the place of the resource in the function is the same as the place of the resource in the vector of the player's class)
    void trade(player& p, size_t resource, size_t resource2, size_t resource3, size_t resource4,size_t resource5,size_t resource6, size_t resource7, size_t resource8, size_t resource9, size_t resource10);
    void endTurn(gameLogic &g);
    
};
#endif // PLAYER_HPP