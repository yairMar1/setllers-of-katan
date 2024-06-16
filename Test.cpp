#include <sstream>
#include <string>
#include <vector>
#include <iostream>
#include <ctime>

#include "doctest.h"
#include "vertex.hpp"
#include "edge.hpp"
#include "tile.hpp"
#include "board.hpp"
#include "player.hpp"
#include "person.hpp"
#include "gameLogic.hpp"
#include "developmentCard.hpp"
#include "deck.hpp"

#define KNIGHT "Knight"
#define ROAD_BUILDING "RoadBuilding"
#define YEAR_OF_PLENTY "YearOfPlenty"
#define MONOPOLY "Monopoly"
#define VICTORY_POINT "VictoryPoint"

using namespace std;

TEST_CASE("Settlement location in an empty place, at the beginning of the game")
{
    player p1("yair", 25);
    player p2("david", 19);
    player p3("shlomo", 20);
    
    vector<player> p = {p1, p2, p3};
    gameLogic g1(p);
    g1.chooseFirstPlayer();
    board b;
    p[0].placeSettelemnt(b, b.get_board()[0].getVertexes()[3], 1);// set v31 as a settlement
    p[0].getResources();
    p[0].getSettlements();
    p[0].placeRoad(b, b.get_board()[0].getEdges()[2], 1);// set e2 as a road
    p[0].getRoads();
    p[0].getNumberOfPoints();

    //********* player try to place a settlement and a road on the same vertex and edge, there are no change on his ditails **********
    p[0].placeSettelemnt(b,b.get_board()[0].getVertexes()[3], 1);
    p[0].placeRoad(b,b.get_board()[0].getEdges()[2], 1);
    
    ostringstream os;
    os << "Wood: 0 Iron: 1 Wheat: 0 Sheep: 1 Clay: 1";
    CHECK(p[0].getResources(1,1) == os.str());

    ostringstream oss;
    oss << "The settlements of yair: 31";
    CHECK_MESSAGE(p[0].getSettlements("t"), oss.str());

    ostringstream osss;
    osss << "The roads of yair: (2,31)";
    CHECK(p[0].getRoads(1) == osss.str());
    
    ostringstream oosss;
    oosss << "yair have 1 points";
    CHECK(p[0].getNumberOfPoints("s") == oosss.str());
}

TEST_CASE("player try roll the dice after he end his turn")
{
    player p1("yair", 25);
    player p2("david", 19);
    player p3("shlomo", 20);
    
    vector<player> p = {p1, p2, p3};
    gameLogic g1(p);
    g1.chooseFirstPlayer();
    board b;

    p[0].rollDice(b,g1);
    // ********* player try to roll the dice after he roll the dice before he finish his turn **********
    streambuf* old = cout.rdbuf();
    ostringstream capture;
    cout.rdbuf(capture.rdbuf());

    p[0].rollDice(b,g1);

    cout.rdbuf(old); // reset to standard output again
    CHECK(capture.str() == "yair already rolled the dice, choose another action\n");

    p[0].endTurn(g1);

    // ********* player try to roll the dice after he finish his turn **********
    streambuf* oldCoutStreamBuf = cout.rdbuf();
    ostringstream capturedCout;
    cout.rdbuf(capturedCout.rdbuf());

    p[0].rollDice(b,g1);

    cout.rdbuf(oldCoutStreamBuf); // reset to standard output again

    CHECK(p[0].getMyTurn() == 0);
    CHECK(capturedCout.str() == "yair It's not your turn, please wait\n");
    }


TEST_CASE("Settlement location in an occupied place")
{
    player p1("yair", 25);
    player p2("david", 19);
    player p3("shlomo", 20);
    
    vector<player> p = {p1, p2, p3};
    gameLogic g1(p);
    g1.chooseFirstPlayer();
    board b;
    p[0].placeSettelemnt(b, b.get_board()[0].getVertexes()[3], 1);// set v31 as a settlement
    p[0].getResources();
    p[0].getSettlements();
    p[0].placeRoad(b, b.get_board()[0].getEdges()[2], 1);// set e2 as a road
    p[0].getRoads();
    p[0].getNumberOfPoints();
    
    //********* second player try to place a settlement and a road on the same vertex and edge **********
    p[1].placeSettelemnt(b,b.get_board()[0].getVertexes()[3], 1);// set v31 as a settlement, but it is already occupied
    p[1].getResources();
    p[1].getSettlements();
    p[1].placeRoad(b,b.get_board()[0].getEdges()[2], 1);// set e2 as a settlement, but it is already occupied
    p[1].getRoads();
    p[1].getNumberOfPoints();

    ostringstream os;
    os << "The next vertex is occupied, choose another vertex";
    CHECK_MESSAGE(p[1].getSettlements("s"), os.str());

    ostringstream oss;
    oss << "Wood: 0 Iron: 0 Wheat: 0 Sheep: 0 Clay: 0";
    CHECK(p[1].getResources(1,1) == oss.str());

    ostringstream ooss;
    ooss << "The roads of shlomo: ";
    CHECK(p[1].getRoads(1) == ooss.str());

    ostringstream oosss;
    oosss << "shlomo have 0 points";
    CHECK(p[1].getNumberOfPoints("t") == oosss.str());
    cout << endl;
}

TEST_CASE("Choosing a location to settle in a free place during the game (not in the first two turns)")
{
    player p1("yair", 25);
    player p2("david", 19);
    player p3("shlomo", 20);
    
    vector<player> p = {p1, p2, p3};
    gameLogic g1(p);
    g1.chooseFirstPlayer();
    board b;
    p[0].placeSettelemnt(b, b.get_board()[0].getVertexes()[3], 1);// set v31 as a settlement
    p[0].getResources();
    p[0].getSettlements();
    p[0].placeRoad(b, b.get_board()[0].getEdges()[2], 1);// set e2 as a road
    p[0].getRoads();
    p[0].getNumberOfPoints();
    cout << endl;
    p[1].placeSettelemnt(b,b.get_board()[12].getVertexes()[1], 1);// set v43 as a settlement
    p[1].getResources();
    p[1].getSettlements();
    p[1].placeRoad(b,b.get_board()[12].getEdges()[3], 1);// set e49 as a settlement
    p[1].getRoads();
    p[1].getNumberOfPoints();
    cout << endl;
    p[2].placeSettelemnt(b,b.get_board()[10].getVertexes()[0], 1);// set v36 as a settlement
    p[2].getResources();
    p[2].getSettlements();
    p[2].placeRoad(b,b.get_board()[10].getEdges()[4], 1);// set e30 as a settlement
    p[2].getRoads();
    p[2].getNumberOfPoints();
    cout << endl;
    //second turn of the game - each player places a settlement and a road on the board
    p[0].placeSettelemnt(b,b.get_board()[7].getVertexes()[2], 1);// set v46 as a settlement
    p[0].getResources();
    p[0].getSettlements();
    p[0].placeRoad(b,b.get_board()[7].getEdges()[2], 1);// set e32 as a road
    p[0].getRoads();
    p[0].getNumberOfPoints();
    cout << endl;
    p[1].placeSettelemnt(b,b.get_board()[15].getVertexes()[0], 1);// set v12 as a settlement
    p[1].getResources();
    p[1].getSettlements();
    p[1].placeRoad(b,b.get_board()[15].getEdges()[4], 1);// set e48 as a road
    p[1].getRoads();
    p[1].getNumberOfPoints();
    cout << endl;
    p[2].placeSettelemnt(b,b.get_board()[17].getVertexes()[5], 1);// set v41 as a settlement
    p[2].getResources();
    p[2].getSettlements();
    p[2].placeRoad(b,b.get_board()[17].getEdges()[4], 1);// set e54 as a road
    p[2].getRoads();
    p[2].getNumberOfPoints();
    cout << endl;
    p[0].placeSettelemnt(b,b.get_board()[5].getVertexes()[1]);// set v33 as a settlement
    p[0].getResources();
    p[0].getSettlements();
    p[0].placeRoad(b,b.get_board()[5].getEdges()[1]);// set e15 as a road
    p[0].getRoads();
    p[0].getNumberOfPoints();
    cout << endl;

    ostringstream oos;
    oos << "Wood: 1 Iron: 1 Wheat: 2 Sheep: 1 Clay: 1";
    CHECK(p[0].getResources(1,1) == oos.str()); // it not change because he can't build there a settlement
    
    ostringstream ooss;
    ooss << "The settlements of yair: 31 46";
    CHECK_MESSAGE(p[0].getSettlements("t"), ooss.str());
    
    ostringstream oss;
    oss << "The roads of yair: (2,31) (46,45)";
    CHECK(p[0].getRoads(1) == oss.str()); // it not change because he can't build there a road

    ostringstream os;
    os << "yair have 2 points";
    CHECK(p[0].getNumberOfPoints("s") == os.str()); // it not change because he can't build there a settlement
}

TEST_CASE("if the dices are 7 the player has more than 7 cards and the player has to throw half of his cards")
{
    player p1("yair", 25);
    player p2("david", 19);
    player p3("shlomo", 20);
    
    vector<player> p = {p1, p2, p3};
    gameLogic g1(p);
    g1.chooseFirstPlayer();
    board b;
    p[0].setResources(WOOD,5);
    p[0].setResources(IRON,3);
    ostringstream os;
    os << "Wood: 5 Iron: 3 Wheat: 0 Sheep: 0 Clay: 0";
    CHECK(p[0].getResources(1,1) == os.str());
    cout << endl;
    
    cout << "The resources that lost:" << endl;
    g1.addResources(b, 7);
    cout << endl;
    
    ostringstream oss;
    oss << "Wood: 3 Iron: 1 Wheat: 0 Sheep: 0 Clay: 0";
    CHECK(p[0].getResources(1,1) == oss.str());
    cout << endl;
}

TEST_CASE("VICTORY CARD")
{
    player p1("yair", 25);
    player p2("david", 19);
    player p3("shlomo", 20);
    
    vector<player> p = {p1, p2, p3};
    gameLogic g1(p);
    g1.chooseFirstPlayer();
    board b;
    deck d;
    p[0].placeSettelemnt(b, b.get_board()[0].getVertexes()[3], 1);// set v31 as a settlement
    p[0].getResources();
    p[0].getSettlements();
    p[0].placeRoad(b, b.get_board()[0].getEdges()[2], 1);// set e2 as a road
    p[0].getRoads();
    p[0].getNumberOfPoints();

    p[0].setResources(SHEEP,1);
    p[0].setResources(IRON,1);
    p[0].setResources(WHEAT,1);

    p[0].addDevelopmentCard(VICTORY_POINT);
    p[0].playDevelopmentCard(g1,d,VICTORY_POINT);
    ostringstream os;
    os << "yair have 2 points";
    CHECK(p[0].getNumberOfPoints("s")== os.str());
    cout << endl;
}

TEST_CASE("YEAROFPLENTY CARD")
{
    player p1("yair", 25);
    player p2("david", 19);
    player p3("shlomo", 20);
    
    vector<player> p = {p1, p2, p3};
    gameLogic g1(p);
    g1.chooseFirstPlayer();
    board b;
    deck d;

    p[0].addDevelopmentCard(YEAR_OF_PLENTY);
    cout << "************************  you need to choose 0 and 1 to get 1 wood and 1 iron ***********************" << endl;
    p[0].playDevelopmentCard(g1,d,YEAR_OF_PLENTY); // you need to choose 0 and 1 to get 1 wood and 1 iron
    ostringstream os;
    os << "Wood: 1 Iron: 1 Wheat: 0 Sheep: 0 Clay: 0";
    CHECK(p[0].getResources(1,1) == os.str());
    cout << endl;
}

TEST_CASE("MONOPLY CARD")
{
    player p1("yair", 25);
    player p2("david", 19);
    player p3("shlomo", 20);
    
    vector<player> p = {p1, p2, p3};
    gameLogic g1(p);
    g1.chooseFirstPlayer();
    board b;
    deck d;

    p[0].setResources(WOOD,2);
    p[1].setResources(WOOD,2);
    p[2].setResources(WOOD,2);

    p[0].addDevelopmentCard(MONOPOLY);
    cout << "************************  you need to choose 0 to get all the wood ***********************" << endl;
    p[0].playDevelopmentCard(g1,d,MONOPOLY); // you need to choose 0 to get all the wood

    ostringstream os;
    os << "Wood: 6 Iron: 0 Wheat: 0 Sheep: 0 Clay: 0";
    CHECK(p[0].getResources(1,1) == os.str()); // the player get all the wood
    cout << endl;

    ostringstream oss;
    oss << "Wood: 0 Iron: 0 Wheat: 0 Sheep: 0 Clay: 0";
    CHECK(p[1].getResources(1,1) == oss.str()); // the player lost all the wood
    CHECK(p[2].getResources(1,1) == oss.str()); // the player lost all the wood
    cout << endl;
}

TEST_CASE("ROADSBILDING CARD")
{
    player p1("yair", 25);
    player p2("david", 19);
    player p3("shlomo", 20);
    
    vector<player> p = {p1, p2, p3};
    gameLogic g1(p);
    g1.chooseFirstPlayer();
    board b;
    deck d;

    p[0].addDevelopmentCard(ROAD_BUILDING);
    p[0].playDevelopmentCard(g1,d,ROAD_BUILDING);

    ostringstream oss;
    oss << "Wood: 2 Iron: 0 Wheat: 0 Sheep: 0 Clay: 2";
    CHECK(p[0].getResources(1,1) == oss.str()); // the player recieve 4 resources for 2 roads
    cout << endl;
}

TEST_CASE("KNIGHT CARD")
{
    player p1("yair", 25);
    player p2("david", 19);
    player p3("shlomo", 20);
    
    vector<player> p = {p1, p2, p3};
    gameLogic g1(p);
    g1.chooseFirstPlayer();
    board b;
    deck d;

    p[0].addDevelopmentCard(KNIGHT);
    p[0].playDevelopmentCard(g1,d,KNIGHT);
    cout << "Number of knight card: " << p[0].getKnightCards() << endl;

    ostringstream os;
    CHECK(p[0].getKnightCards() == 1); // the player recieve 1 knight card
    cout << endl;

    p[0].addDevelopmentCard(KNIGHT);
    p[0].playDevelopmentCard(g1,d,KNIGHT);
    p[0].addDevelopmentCard(KNIGHT);
    p[0].playDevelopmentCard(g1,d,KNIGHT);

    ostringstream oss;
    CHECK(p[0].getKnightCards() == 3); // the player recieve 3 knight card
    CHECK(p[0].getNumberOfPoints("s") == "yair have 2 points"); // the player recieve 2 points
    cout << endl;
}