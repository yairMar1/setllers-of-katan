#ifndef EDGE_HPP
#define EDGE_HPP

#include "vertex.hpp"
#include <string>
#include <iostream>
#include <vector>

using namespace std;
       
class edge{

private:
    vertex* a;
    vertex* b;
    bool isClear = true;
public:
    edge(vertex* a, vertex* b);
    
    vertex* getVertexA();
    vertex* getVertexB();
    string getNameOfEdge();
    bool getIsClear();
    void setIsClear(bool isClear);
    void printEdge();
};

#endif // EDGE_HPP