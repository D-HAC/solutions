#ifndef __DEPTH_FIRST_SEARCH
#define __DEPTH_FIRST_SEARCH

#include "MazeDefinitions.h"
#include "Search.h"
#include <stack>

class DepthFirstSearch : public Search
{
public:
    DepthFirstSearch() : Search() {}
    ~DepthFirstSearch() {}

    SearchNode* search(Maze m);
protected:
    std::stack<SearchNode*> moveStack;
};

#endif
