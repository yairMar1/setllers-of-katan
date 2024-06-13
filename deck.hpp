#ifndef DECK_HPP
#define DECK_HPP

#include "developmentCard.hpp"
#include "KnightCard.hpp"
#include "monopolyCard.hpp"
#include "roadBuildingCard.hpp"
#include "victoryPointCard.hpp"
#include "yearOfPlentyCard.hpp"

#include <array>
#include <string>
#include <iostream>
#include <random>
#include <algorithm>

using namespace std;

class deck {
private:
    vector<string> cards;
public:
    deck();
    vector<string> initializeDeck(); // Initialize the deck with specific number of cards
    void shuffleDeck(); // Shuffle the deck
    string drawCard(); // Draw a card from the deck
    void printDeck(); // Print the deck
    void addCard(string card); // Add a card to the deck, after a player uses a card
};

#endif // DECK_HPP