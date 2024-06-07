#ifndef GAMELOGIC_HPP
#define GAMELOGIC_HPP

#include "player.hpp"
class player;
class gameLogic{
private:
    vector<player>& players;
public:
    gameLogic(vector<player>& players);
    void chooseFirstPlayer();

    void addResources(board& b, size_t sum);
};
#endif // GAMELOGIC_HPP