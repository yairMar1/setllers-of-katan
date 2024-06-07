#include "edge.hpp"
#include "vertex.hpp"
#include <string>
#include <iostream>
#include <vector>

using namespace std;

edge::edge(vertex* a, vertex* b) : a(a), b(b){
    //cout << "Edge created with vertex: " << a.getNumberId() << " and " << b.getNumberId() << endl;
}

vertex *edge::getVertexA(){
    return a;
}

vertex *edge::getVertexB(){
    return b;
}

// vector<size_t> edge::getNameOfEdge(){
//     vector<size_t> nameOfEdge = {a->getNumberId(), b->getNumberId()};
//     return nameOfEdge;
// }

string edge::getNameOfEdge() {
    string res;
    res = "(" + to_string(a->getNumberId()) + "," + to_string(b->getNumberId()) + ")";
    return res;
}

bool edge::getIsClear(){
    return isClear;
}

void edge::setIsClear(bool newValue){
    if(isClear == true){
    this->isClear = newValue;
            //cout << "The boolean value in it, had been changed" << endl;
    }else{
        cout << "Edge is already occupied" << endl;
    }
}

void edge::printEdge(){
    cout << "Vertex A: " << a->getNumberId() << endl;
    cout << "Vertex B: " << b->getNumberId() << endl;
    cout << "Is Clear: " << isClear << endl << endl;
}
