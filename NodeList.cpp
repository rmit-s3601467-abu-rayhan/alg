#include "NodeList.h"
#include <iostream>

NodeList::NodeList(){ 
    // TODO
    length = 0;
    for(int i = 0; i < NODE_LIST_ARRAY_MAX_SIZE; ++i){
        nodes[i] = nullptr;
    }
    //nodes[0] = new Node(0, 0, 0);
    //Node* nodes = new Node[NODE_LIST_ARRAY_MAX_SIZE];
}

NodeList::~NodeList(){
    // TODO
    //std::cout << "length: " << getLength() << std::endl;
    for(int i = 0; i < length; i++){
        delete nodes[i];
    }
    //delete nodes[sizeof(length)];
}

//deepcopy
NodeList::NodeList(NodeList& other){
    // TODO
    //this->length = int(other.length);
    // Node* nodes[NODE_LIST_ARRAY_MAX_SIZE];
    for(int i = 0; i < length; ++i){
        this->nodes[i] = new Node(*other.nodes[i]);
    }

}

int NodeList::getLength(){
    // TODO
    //std::cout << "in getLength length: " << length << std::endl;
    return length;
}

void NodeList::addElement(Node* newPos){
    // TODO
    // int i = 0;
    // i++;
    //nodes[length] = newPos;
    // NodeList: list of node objects
    // You may assume a fixed size for M1, M2, M3
    //Node* nodes[NODE_LIST_ARRAY_MAX_SIZE];
    Node * newA = new Node(*newPos);
    nodes[length] = newA;
    length++;
}

Node* NodeList::getNode(int i){
    // TODO
    //std::cout << "in getNode(): " << nodes[i] << std::endl;
    return nodes[i];
}