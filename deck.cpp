#include "deck.hpp"

#include <string>
#include <vector>
#include <iostream>

using namespace std;

deck::deck() {
    cards = initializeDeck();
}

vector<string> deck::initializeDeck() {
    vector<string> c;

    KnightCard k1, k2, k3;
    c.push_back(k1.getType());
    c.push_back(k2.getType());
    c.push_back(k3.getType());

    victoryPointCard v1, v2, v3, v4;
    c.push_back(v1.getType());
    c.push_back(v2.getType());
    c.push_back(v3.getType());
    c.push_back(v4.getType());

    yearOfPlentyCard y1, y2;
    c.push_back(y1.getType());
    c.push_back(y2.getType());

    monopolyCard m1, m2;
    c.push_back(m1.getType());
    c.push_back(m2.getType());

    roadBuildingCard r1, r2;
    c.push_back(r1.getType());
    c.push_back(r2.getType());

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
    string card = cards[0];
    cout << "You drew a card! " << card << endl;
    cards.erase(cards.begin());
    shuffleDeck();
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

void deck::addCard(string card){
    if(card == "knight"){
        KnightCard k;
        cards.push_back(k.getType());
    }
    else if(card == "victoryPoint"){
        victoryPointCard v;
        cards.push_back(v.getType());
    }
    else if(card == "yearOfPlenty"){
        yearOfPlentyCard y;
        cards.push_back(y.getType());
    }
    else if(card == "monopoly"){
        monopolyCard m;
        cards.push_back(m.getType());
    }
    else if(card == "roadBuilding"){
        roadBuildingCard r;
        cards.push_back(r.getType());
    }
    else{
        cout << "Invalid card!" << endl;
    }
    shuffleDeck();
}
