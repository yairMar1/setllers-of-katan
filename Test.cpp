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

// TEST_CASE("Settlement location in an empty place, at the beginning of the game")
// {
//     board b;
//     p[0].placeSettelemnt(b, b.get_board()[0].getVertexes()[3], 1);// set v31 as a settlement
//     p[0].getResources();
//     p[0].getSettlements();
//     p[0].placeRoad(b, b.get_board()[0].getEdges()[2], 1);// set e2 as a road
//     p[0].getRoads();
//     p[0].getNumberOfPoints();

//     CHECK(p[0].placeSettelemnt(b,b.get_board()[0].getVertexes()[3], 1) == "yair placed settlement on vertex 31, on junction: 10 iron 2 sheep 6 clay");
//     CHECK(p[0].getResources() == "yair has: "
//                             "Wood: 0 "
//                             "Iron: 1 "
//                             "Wheat: 0 "
//                             "Sheep: 1 "
//                             "Clay: 1");
//     CHECK(p[0].getSettlements() == "The settlements of yair: 31");
//     CHECK(p[0].placeRoad(b,b.get_board()[0].getEdges()[2], 1) == "yair placed road on edge (2,31) on tile: 10 iron 2 sheep ");
//     CHECK(p[0].getRoads() == "The roads of yair: (2,31)");
//     CHECK(p[0].getNumberOfPoints() == "yair have 1 points");
// }


// TEST_CASE("Settlement location in an occupied place")
// {
//     board b;
//     p[0].placeSettelemnt(b, b.get_board()[0].getVertexes()[3], 1);// set v31 as a settlement
//     p[0].getResources();
//     p[0].getSettlements();
//     p[0].placeRoad(b, b.get_board()[0].getEdges()[2], 1);// set e2 as a road
//     p[0].getRoads();
//     p[0].getNumberOfPoints();
    
//     //********* second player try to place a settlement and a road on the same vertex and edge **********
//     p[1].placeSettelemnt(b,b.get_board()[1].getVertexes()[5], 1);// set v31 as a settlement, but it is already occupied
//     p[1].getResources();
//     p[1].getSettlements();
//     p[1].placeRoad(b,b.get_board()[0].getEdges()[2], 1);// set e2 as a settlement, but it is already occupied
//     p[1].getRoads();
//     p[1].getNumberOfPoints();

//     CHECK(p[1].placeSettelemnt(b,b.get_board()[1].getVertexes()[4], 1) == "The next vertex is occupied, choose another vertex");
// CHECK(p[1].getResources() == "shlomo has: "
//                             "Wood: 0 "
//                             "Iron: 0 "
//                             "Wheat: 0 "
//                             "Sheep: 0 "
//                             "Clay: 0");
//     CHECK(p[1].placeRoad(b,b.get_board()[0].getEdges()[2], 1) == "This edge (2,31) is already occupied or you choose a wrong action, please choose another edge");
//     CHECK(p[1].getNumberOfPoints() == "shlomo have 0 points");
// }

// TEST_CASE("Choosing a location to settle in a free place, during the game (not in the first two turns)")
// {
//     board b;
//     p[0].placeSettelemnt(b, b.get_board()[0].getVertexes()[3], 1);// set v31 as a settlement
//     p[0].getResources();
//     p[0].getSettlements();
//     p[0].placeRoad(b, b.get_board()[0].getEdges()[2], 1);// set e2 as a road
//     p[0].getRoads();
//     p[0].getNumberOfPoints();
//     cout << endl;
//     //********* second player try to place a settlement and a road on the same vertex and edge **********
//     p[1].placeSettelemnt(b,b.get_board()[1].getVertexes()[4], 1);// set v31 as a settlement, but it is already occupied
//     p[1].getResources();
//     p[1].getSettlements();
//     p[1].placeRoad(b,b.get_board()[0].getEdges()[2], 1);// set e2 as a settlement, but it is already occupied
//     p[1].getRoads();
//     p[1].getNumberOfPoints();
//     //********* second player place a settlement and a road on another vertex and edge **********
//     cout << endl;
//     p[1].placeSettelemnt(b,b.get_board()[12].getVertexes()[1], 1);// set v43 as a settlement
//     p[1].getResources();
//     p[1].getSettlements();
//     p[1].placeRoad(b,b.get_board()[12].getEdges()[3], 1);// set e49 as a settlement
//     p[1].getRoads();
//     p[1].getNumberOfPoints();
//     cout << endl;

//     p[2].placeSettelemnt(b,b.get_board()[10].getVertexes()[0], 1);// set v36 as a settlement
//     p[2].getResources();
//     p[2].getSettlements();
//     p[2].placeRoad(b,b.get_board()[10].getEdges()[4], 1);// set e30 as a settlement
//     p[2].getRoads();
//     p[2].getNumberOfPoints();
//     cout << endl;
//     //second turn of the game - each player places a settlement and a road on the board
//     p[0].placeSettelemnt(b,b.get_board()[7].getVertexes()[2], 1);// set v46 as a settlement
//     p[0].getResources();
//     p[0].getSettlements();
//     p[0].placeRoad(b,b.get_board()[7].getEdges()[2], 1);// set e32 as a road
//     p[0].getRoads();
//     p[0].getNumberOfPoints();
//     cout << endl;

//     p[1].placeSettelemnt(b,b.get_board()[15].getVertexes()[0], 1);// set v12 as a settlement
//     p[1].getResources();
//     p[1].getSettlements();
//     p[1].placeRoad(b,b.get_board()[15].getEdges()[4], 1);// set e48 as a road
//     p[1].getRoads();
//     p[1].getNumberOfPoints();
//     cout << endl;

//     p[2].placeSettelemnt(b,b.get_board()[17].getVertexes()[5], 1);// set v41 as a settlement
//     p[2].getResources();
//     p[2].getSettlements();
//     p[2].placeRoad(b,b.get_board()[17].getEdges()[4], 1);// set e54 as a road
//     p[2].getRoads();
//     p[2].getNumberOfPoints();
//     cout << endl;

//     p[0].placeSettelemnt(b,b.get_board()[5].getVertexes()[1]);// set v33 as a settlement
//     p[0].getResources();
//     p[0].getSettlements();
//     p[0].placeRoad(b,b.get_board()[5].getEdges()[1]);// set e15 as a road
//     p[0].getRoads();
//     p[0].getNumberOfPoints();
//     cout << endl;
//     CHECK(p[0].placeSettelemnt(b,b.get_board()[5].getVertexes()[1]) == "");
//     CHECK(p[0].getResources() == "yair has: "
//                             "Wood: 1 "
//                             "Iron: 1 "
//                             "Wheat: 2 "
//                             "Sheep: 1 "
//                             "Clay: 1"); // it not change because he can't build there a settlement    CHECK(p[0].getSettlements() == "The settlements of yair: 31 46");
//     CHECK(p[0].placeRoad(b,b.get_board()[5].getEdges()[1]) == "This edge (33,34) is already occupied or you choose a wrong action, please choose another edge");
//     CHECK(p[0].getRoads() == "The roads of yair: (2,31) (46,45)"); // it not change because he can't build there a road
//     CHECK(p[0].getNumberOfPoints() == "yair have 2 points"); // it not change because he can't build there a settlement
// }

TEST_CASE("if the dices are 7, the player has more than 7 cards, and the player has to throw half of his cards")
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
    os << "yair has: Wood: 5 Iron: 3 Wheat: 0 Sheep: 0 Clay: 0";
    CHECK_EQ(p[0].getResources(1,1), os.str());

    g1.addResources(b, 7);
    
    ostringstream oss;
    oss << "yair has: Wood: 3 Iron: 2 Wheat: 0 Sheep: 0 Clay: 0";
    CHECK(p[0].getResources(1,1) == oss.str());
}