#ifndef BOARD_HPP
#define BOARD_HPP

#include "tile.hpp"
#include "vertex.hpp"
#include "edge.hpp"

#include <string>
#include <vector>
#include <iostream>

using namespace std;

class board{
    private:
    vector<tile> tiles;

    public:
    board();
    vector<tile>& get_board();
    void printBoard();
    vector<tile> initialBoard();
};
#endif // BOARD_HPP