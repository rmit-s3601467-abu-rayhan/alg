#include "PathSolver.h"
#include <iostream>
#include <bits/stdc++.h>
#include <utility>
using namespace std;

// Creating a shortcut for int, int pair type
typedef std::pair<int, int> Pair;

// Creating a shortcut for pair<int, pair<int, int>> type
typedef std::pair<double, std::pair<int, int> > pPair;

struct node{
	int parent_i;
	int parent_j;
	double f,g,h;
    
};
bool isValid(int row, int col)
{
    // Returns true if row number and column number
    // is in range
    return (row >= 0) && (row < ENV_DIM) &&
           (col >= 0) && (col < ENV_DIM);
}
bool maxMinRowCol(int row, int col){
    if(row == ENV_DIM || col == ENV_DIM){
        return true;
    }else if(row == 0 || col == 0){
        return true;
    }else{
        return false;
    }
}
bool isWall(char env[ENV_DIM][ENV_DIM], int row, int col){
    if(env[row][col] == SYMBOL_WALL){
        return true;
    }else{
        return false;
    }
    // return false;
}
bool isBlockEmpty(char env[ENV_DIM][ENV_DIM], int row, int col){
    if(env[row][col] == SYMBOL_EMPTY){
        return true;
    }else{
        return false;
    }
    // return false;
}
bool isUnBlocked(char env[ENV_DIM][ENV_DIM], int row, int col)
{
    // Returns true if the cell is not blocked else false
    if (env[row][col] == SYMBOL_START){
        return true;
    }else if(env[row][col] == SYMBOL_GOAL){
        return true;
    }else if(env[row][col] == SYMBOL_EMPTY){
        return true;
    }else{
        return false;
    }
}
bool isDestination(int row, int col, Pair dest)
{
    if (row == dest.first && col == dest.second)
        return (true);
    else
        return (false);
}
double calculateHValue(int row, int col, Pair dest)
{
    //return wusing manhatten distance
    return (abs(row-dest.first - row-dest.second)+ abs(col-dest.first - col-dest.second));
}

void tracePath(node cellDetails[][ENV_DIM], Pair dest)
{
    std::cout << ("\nThe Path is ");
    int row = dest.first;
    int col = dest.second;

    std::stack<Pair> Path;

    while (!(cellDetails[row][col].parent_i == row
             && cellDetails[row][col].parent_j == col ))
    {
        Path.push (std::make_pair (row, col));
        int temp_row = cellDetails[row][col].parent_i;
        int temp_col = cellDetails[row][col].parent_j;
        row = temp_row;
        col = temp_col;
    }

    Path.push (std::make_pair (row, col));
    while (!Path.empty())
    {
        std::pair<int,int> p = Path.top();
        Path.pop();
        std::cout << "("<<p.first <<"," <<p.second << ")";
    }

    return;
}

PathSolver::PathSolver(){
    // TODO
    //NodeList * nodesExplored = NULL;
}


PathSolver::~PathSolver(){
	
    // TODO
}

void PathSolver::forwardSearch(Env env){
    // TODO 
    Pair src;
    Pair dest;
    int endPos = 0;
    //int i, j;
    NodeList * openList = new NodeList();
    NodeList * closedList = new NodeList();
    for (int i = 0; i < ENV_DIM; i++){
		for (int j = 0; j < ENV_DIM; j++){
			// Finding source
			if (env[i][j] == SYMBOL_START){
                src.first = i; //row
                src.second = j; //col
                // cout << "In symbol start" << endl;
                // cout << src.first << endl;
                // cout << src.second << endl;
                src = std::make_pair(i, j);
			}
            //finding destination
            if (env[i][j] == SYMBOL_GOAL){
                dest.first = i;
                dest.second = j;
                // cout << "In symbol dest" << endl;
                // cout << dest.first << endl;
                // cout << dest.second << endl;
                dest = std::make_pair(i, j);
			}
		}
	}
    // If the source is out of range
    if (isValid(src.first, src.second) == false)
    {
        printf ("Source is invalid\n");
        return;
    }

    // // If the destination is out of range
    if (isValid(dest.first, dest.second) == false)
    {
        printf ("Destination is invalid\n");
        return;
    }
    // // Either the source or the destination is blocked
    if (isUnBlocked(env, src.first, src.second) == false ||
            isUnBlocked(env, dest.first, dest.second) == false)
    {
        printf ("Source or the destination is blocked\n");
        return;
    }
    int i , j = 0;
    i = src.first, j = src.second;
    Node * startPos = new Node(i, j, 0);
    Node * Goal = new Node(dest.first, dest.second, 0);
    i = startPos->getRow();
    j = startPos->getCol();
    startPos->setGRow(dest.first);
    startPos->setGCol(dest.second);

    openList->addElement(startPos);
    //closedList->addElement(startPos);
    int index1 = 0;
    int smallestDist = 0;
    int manhattan = 0;
    int prevDist = 0;
    int newDist = 0;
    int checker = 0;
    // int checkerC = 0;
    Node * p = openList->getNode(0);
    //openist forloop
        //find smallest distance
        //closedList forloop
        //
    //

    int holder = 0;
    // Node * q = new Node(i, j, 0);
    while(true && /* endPos < 16 */ checker != 1){
        for(int z = 0; z < openList->getLength(); z++){
            manhattan = openList->getNode(z)->getEstimatedDist2Goal(Goal);
            newDist = manhattan+index1;
            prevDist = smallestDist;
            smallestDist = newDist;
            if(smallestDist < prevDist){
                holder = z;
            }
            for(int x = 0; x < closedList->getLength(); x++){
                // cout << "openlist row: " << openList->getNode(holder)->getRow()
                // << "openlist col: " << openList->getNode(holder)->getCol() 
                // << " closedlist row: " << closedList->getNode(x)->getRow() <<
                // " closedlist col: " << closedList->getNode(x)->getCol() << endl;
                if((openList->getNode(holder)->getCol() != closedList->getNode(x)->getCol() )||
                    (openList->getNode(holder)->getRow() != closedList->getNode(x)->getRow())){
                        // holder = z; 
                        p = openList->getNode(holder);  
                }
            }
        }
        if((p->getCol() == Goal->getCol()) && (p->getRow() == Goal->getRow())){
            checker = 1;           
        }
        //for each position q in E that the robot can reach from p 
            //set dist_traveled of q to be one more then that of p
            //add q to openlist P ONLY if it is not in it already
        //end for loop
        i = p->getRow();
        j = p->getCol();
        closedList->addElement(p);
        cout << "i: " << i << "," << j << endl;
        if(env[i][j+1] == SYMBOL_EMPTY || env[i][j+1] == SYMBOL_GOAL){
            // cout << "Eastb4index1 " << index1 << endl;
            // index1 = p->getDistanceTraveled()+1;
            // cout << "EastAfindex1 " << index1 << endl;
            if(p->getCol() != j+1){
                index1 = p->getDistanceTraveled()+1;
                p = new Node(i, j+1, index1);
                openList->addElement(p);
            }
            // cout << "EastAfindex1 " << index1 << endl;
        }
        if(env[i][j-1] == SYMBOL_EMPTY || env[i][j-1] == SYMBOL_GOAL){
            // cout << "Westb4index1 " << index1 << endl;
            // index1 = p->getDistanceTraveled()+1;
            // cout << "WestAfindex1 " << index1 << endl;
            if(p->getCol() != j-1){
                index1 = p->getDistanceTraveled()+1;
                p = new Node(i, j-1, index1);
                openList->addElement(p);
            }
            // cout << "WestAfindex1 " << index1 << endl;
        }
        if(env[i+1][j] == SYMBOL_EMPTY || env[i+1][j] == SYMBOL_GOAL){
            // cout << "Sb4index1 " << index1 << endl;
            // index1 = p->getDistanceTraveled()+1;
            // cout << "NAfindex1 " << index1 << endl;
            if(p->getRow() != i+1){
                index1 = p->getDistanceTraveled()+1;
                p = new Node(i+1, j, index1);
                openList->addElement(p);
            }
            // cout << "SAfindex1 " << index1 << endl;
        }
        if(env[i-1][j] == SYMBOL_EMPTY || env[i-1][j] == SYMBOL_GOAL){
            // cout << "Nb4index1 " << index1 << endl;
            // index1 = p->getDistanceTraveled()+1;
            // cout << "SAfindex1 " << index1 << endl;
            if(p->getRow() != i-1){
                index1 = p->getDistanceTraveled()+1;
                p = new Node(i-1, j, index1);
                openList->addElement(p);
            }
            // cout << "NAfindex1 " << index1 << endl;
        }

        cout << "closedList->getLength(): " << closedList->getLength() << endl;
        // closedList->addElement(p);
        endPos++;
       
    }
    cout << checker << endl;
    for(int g = 0; g <  closedList->getLength(); g++){
        cout << "closedList->row: " << closedList->getNode(g)->getRow() 
        << "closedList->col: " << closedList->getNode(g)->getCol() << endl; 
    }
    // NodeList* nodesExplored;
    closedList = nodesExplored;
    delete startPos;
    delete openList;
    delete closedList;
    
    
}

NodeList* PathSolver::getNodesExplored(){
    //TODO
    
    return nullptr;
}

NodeList* PathSolver::getPath(Env env){

    // TODO
    
    // Pair dest;
    // node cellDetails[ENV_DIM][ENV_DIM];

    // std::cout << ("\nThe Path is ");
    // int row = dest.first;
    // int col = dest.second;

    // std::stack<Pair> Path;

    // while (!(cellDetails[row][col].parent_i == row
    //          && cellDetails[row][col].parent_j == col ))
    // {
    //     Path.push (std::make_pair (row, col));
    //     int temp_row = cellDetails[row][col].parent_i;
    //     int temp_col = cellDetails[row][col].parent_j;
    //     row = temp_row;
    //     col = temp_col;
    // }

    // Path.push (std::make_pair (row, col));
    // while (!Path.empty())
    // {
    //     std::pair<int,int> p = Path.top();
    //     Path.pop();
    //     std::cout << "("<<p.first <<"," <<p.second << ")";
    // }

    // return;
    
    return nullptr;
}

//-----------------------------