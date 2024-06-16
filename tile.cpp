#include "tile.hpp"
#include "vertex.hpp"
#include "edge.hpp"

#include <string>
#include <vector>
#include <iostream>

using namespace std;

tile::tile(string typeOfResource, size_t num, vector<vertex*> vertex, vector<edge*> edge) : typeOfResource(typeOfResource), number(num), vertexes(vertex), edges(edge){
}

string tile::getTypeOfResource(){
    return typeOfResource;
}

size_t tile::getNumber(){
    return number;
}

bool tile::getHasRobbed(){
    return hasRobbed;
}

vector<vertex*> tile::getVertexes(){
    return vertexes;
}

vector<edge*> tile::getEdges(){
    return edges;
}

void tile::setHasRobbed(bool hasRobbed){
    this->hasRobbed = hasRobbed;
}

void tile::printTile(){
    cout << "Type of Resource: " << typeOfResource << endl;
    cout << "Number: " << number << endl;
    cout << "Has Robbed: " << hasRobbed << endl << endl;
    cout << "Vertexes: " << endl << endl;
    for (size_t i = 0; i < 6; i++){
        //cout << "Vertex " << i << ": " << endl;
        vertexes[i]->printVertex();
    }
    cout << endl;
    cout << "Edges: " << endl << endl;
    for (size_t i = 0; i < 6; i++){
        //cout << "Edge " << i << ": " << endl;
        edges[i]->printEdge();
    }
}