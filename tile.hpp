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




// #ifndef TILE_HPP
// #define TILE_HPP

// #include <string>
// #include <vector>
// #include <memory>
// #include "vertex.hpp"
// #include "edge.hpp"

// class tile {
// private:
//     std::string typeOfResource;
//     size_t number;
//     bool hasRobbed = false;

//     std::vector<std::shared_ptr<vertex>> vertexes;
//     std::vector<std::shared_ptr<edge>> edges;

// public:
//     tile(std::string typeOfResource, size_t num, std::vector<std::shared_ptr<vertex>> vertexes, std::vector<std::shared_ptr<edge>> edges);

//     std::string getTypeOfResource() const;
//     size_t getNumber() const;
//     bool getHasRobbed() const;
//     std::vector<std::shared_ptr<vertex>> getVertexes() const;
//     std::vector<std::shared_ptr<edge>> getEdges() const;

//     void setHasRobbed(bool hasRobbed);
//     void printTile() const;
// };

// #endif // TILE_HPP
