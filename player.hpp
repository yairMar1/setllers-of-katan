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
    bool myTurn;
public:
    //Access to a player's fields
    player(string nameOfPlayer, size_t age);
    void getNumberOfPoints();

    void getCitys();
    void setCitys(int vertexNumber);

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

    void placeCity();
    void placeRoad(board& b, edge* e,size_t n);// for the two first action of the player (need less checks)
    void placeRoad(board& b, edge* e);  // for the rest action of the player (need more checks)
    void getRoads();

    void buyDevelopmentCard();
    void trade();
    void endTurn();


    
};
#endif // PLAYER_HPP