#include "Node.h"
#include <iostream>


Node::Node(int row, int col, int dist_traveled)
{
    // TODO
    this->row = row;
    this->col = col;
    this->dist_traveled = dist_traveled;
    // this->xRowA = xRowA;
    // this->yColA = yColA;
}

Node::~Node(){
    // TODO
    // delete &row;
    // delete &col;
    // delete &dist_traveled;      
}

int Node::getRow(){
    // TODO
    return row;
}

int Node::getCol(){
    // TODO
    return col;
}

int Node::getDistanceTraveled(){
    //std::cout << "dist_traveled: " << dist_traveled << std::endl;
    // TODO
    return dist_traveled;
}

void Node::setDistanceTraveled(int dist_traveled)
{
    // TODO
    this->dist_traveled = dist_traveled;
    // std::cout << "this->dist_traveled: " << this->dist_traveled << std::endl;
}

int Node::getEstimatedDist2Goal(Node* goal){
    // TODO
    //Node * newN = new Node(*goal);
    //int h = abs(goal->getCol() - col) + abs(goal->getRow() - getRow());
    //return (abs(row-dest.first - row-dest.second)+ abs(col-dest.first - col-dest.second));
    //int dist = newN->getCol() - col + newN->getRow()-
    //return (abs(goal->getCol() - col) + abs(goal->getRow() - getRow())) + dist_traveled;
    // std::cout << "getGrow: " << getGrow() << " getGcol: " << getGcol() << std::endl;
    // std::cout << "goal->getRow(): " << goal->getRow() << " goal->getCol(): " << goal->getCol() << std::endl;
    // std::cout << "row: " << row << " col: " << col << std::endl;
    return (abs(goal->getCol() - col) + abs(goal->getRow() - row));
    
}

void Node::setGRow(int xRowA){
    // TODO
    this->xRowA = xRowA;
}

void Node::setGCol(int yColA){
    // TODO
    this->yColA = yColA;
}

int Node::getGrow(){
    return xRowA;
}

int Node::getGcol(){
    return yColA;
}
//--------------------------------                             