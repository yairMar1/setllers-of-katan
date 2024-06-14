#include "deck.hpp"

#include <string>
#include <vector>
#include <iostream>

#define KNIGHT "Knight"
#define ROAD_BUILDING "RoadBuilding"
#define YEAR_OF_PLENTY "YearOfPlenty"
#define MONOPOLY "Monopoly"
#define VICTORY_POINT "VictoryPoint"

using namespace std;

deck::deck() {
    cards = initializeDeck();
}

size_t deck::getDeckSize(){
    return cards.size();
}

vector<string> deck::initializeDeck() {
    vector<string> c;

    KnightCard k1, k2, k3;
    c.push_back(KNIGHT);
    c.push_back(KNIGHT);
    c.push_back(KNIGHT);

    victoryPointCard v1, v2, v3, v4;
    c.push_back(VICTORY_POINT);
    c.push_back(VICTORY_POINT);
    c.push_back(VICTORY_POINT);
    c.push_back(VICTORY_POINT);

    yearOfPlentyCard y1, y2;
    c.push_back(YEAR_OF_PLENTY);
    c.push_back(YEAR_OF_PLENTY);

    monopolyCard m1, m2;
    c.push_back(MONOPOLY);
    c.push_back(MONOPOLY);

    roadBuildingCard r1, r2;
    c.push_back(ROAD_BUILDING);
    c.push_back(ROAD_BUILDING);

    return c;
}
void deck::shuffleDeck() {
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(cards.begin(), cards.end(), g);
}

string deck::drawCard(){
    if (cards.empty()) {
        return "The deck is empty!";
    }
    shuffleDeck(); // Shuffle the deck before drawing a card
    string card = cards[0];
    //cout << "You drew a card! " << card << endl;
    cards.erase(cards.begin());
    return card;
}

void deck::printDeck(){
    for (size_t i = 0; i < cards.size(); i++) {
        cout << cards[i] << " ";
        if(i != cards.size()-1){
            cout << ", ";
        }
    }
    cout << endl;
}

// void deck::addCard(string card){
//     if(card == "knight"){
//         KnightCard k;
//         cards.push_back(k.getType());
//     }
//     else if(card == "victoryPoint"){
//         victoryPointCard v;
//         cards.push_back(v.getType());
//     }
//     else if(card == "yearOfPlenty"){
//         yearOfPlentyCard y;
//         cards.push_back(y.getType());
//     }
//     else if(card == "monopoly"){
//         monopolyCard m;
//         cards.push_back(m.getType());
//     }
//     else if(card == "roadBuilding"){
//         roadBuildingCard r;
//         cards.push_back(r.getType());
//     }
//     else{
//         cout << "Invalid card!" << endl;
//     }
//     shuffleDeck(); // Shuffle the deck after adding a card (after a player uses a card)
// }

void deck::addCard(const string& card){
    cout << "Card has been returned to the deck!" << endl;
    cards.push_back(card);
    shuffleDeck(); // Shuffle the deck after adding a card
}
