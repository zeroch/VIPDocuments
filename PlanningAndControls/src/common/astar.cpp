#include "astar.h"
#include <stdio.h>
#include <stdlib.h>
#include <stack>

Astar::Astar(Space * problem):Algorithm(problem)
{
   target = problem->get_end();
   head = (Astar::node *)malloc(sizeof(Astar::node));
   head->currentPoint = problem->get_start();
   head->previousNode = nullptr;
   head->nextNodes = *((std::vector<Astar::node *> *)
                       malloc(sizeof(std::vector<Astar::node *>)));
}

Astar::~Astar(){
  std::stack<Astar::node *> nodeStack;
  bool treeHasNodes = true;
  nodeStack.push(head);
  while(!nodeStack.empty()){
    node * currentNode = nodeStack.top();
    nodeStack.pop();
    for(std::vector<Astar::node*>::iterator it = currentNode->nextNodes.begin();
        it != currentNode->nextNodes.end() ; it++){
        nodeStack.push(*it);
     }
    free((void*)currentNode);
   }
}

void Astar::run(){

}

void Astar::pause(){
//to be implemented with threading
}

void Astar::stop(){
//to be implemented with threading
}

void Astar::runUntil(){
//not relevant to this particular algorithm
}

Path * Astar::pathGenerated(){

}

Path * Astar::areaExplored(){

}

int Astar::heuristic(Point *currentLoc){
    return all_points->distance(currentLoc, target);
}
