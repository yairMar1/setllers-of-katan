#ifndef TILE_HPP
#define TILE_HPP

#include <string>
#include <vector>

#include "vertex.hpp"
#include "edge.hpp"

using namespace std;

class tile{

private:
    string typeOfResource;
    size_t number;
    bool hasRobbed = false;
    
    vector<vertex*> vertexes;

    vector<edge*> edges;
public:
    tile(string typeOfResource, size_t num, vector<vertex*> vertex, vector<edge*> edge);

    string getTypeOfResource();
    size_t getNumber();
    bool getHasRobbed();
    vector<vertex*> getVertexes();
    vector<edge*> getEdges();

    void setHasRobbed(bool hasRobbed);
    void printTile();
};
    
#endif // TILE_HPP
