#ifndef GAMELOGIC_HPP
#define GAMELOGIC_HPP

#include "player.hpp"
class player;
class gameLogic{
private:
    vector<player>& players;
    size_t numberTurn = 1;
public:
    gameLogic(vector<player>& players);
    size_t getNumberTurn();
    void setNumberTurn(size_t n);
    player& getPlayer(int index);
    void chooseFirstPlayer();
    void nextTurn();
    void addResources(board& b, size_t sum);
    string gameFhinished();
};
#endif // GAMELOGIC_HPP