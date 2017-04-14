#include "MazeDefinitions.h"

/**
 * Searches all child nodes of the start node by expanding the children of a 
 * node first
 */
SearchNode* DepthFirstSearch::search(Maze m)
{
    MazeBlock start = m.get(0);
    SearchNode* startNode = addState(start, NULL);
    this->moveStack.push(startNode);

    while (this->moveStack.size() != 0)
    {
        // Get the next node to consider
        SearchNode* currentNode = this->moveStack.top();
        this->moveStack.pop();
        MazeBlock currentState = currentNode->state;

        // If this state is the solution, return this state
        if (currentState.atExit())
        {
            return currentNode;
        }
        
        // Add each child of this node if it is new
        // South
        if (currentState.south == EMPTY)
        {
            // Create new state and node by applying move
            int nextR = currentState.row + 1;
            int nextC = currentState.col;
            MazeBlock childState = m.get(nextR, nextC);
            // Check if this state has been visited, skip if it has
            if (!this->stateVisited(childState.ind))
            {
                // This is a new state, add it to the tree
                SearchNode* childNode = this->addState(childState, currentNode);
                this->moveStack.push(childNode);
            }
            
        }
        // East
        if (currentState.east == EMPTY)
        {
            // Create new state and node by applying move
            int nextR = currentState.row;
            int nextC = currentState.col + 1;
            MazeBlock childState = m.get(nextR, nextC);
            // Check if this state has been visited, skip if it has
            if (!this->stateVisited(childState.ind))
            {
                // This is a new state, add it to the tree
                SearchNode* childNode = this->addState(childState, currentNode);
                this->moveStack.push(childNode);
            }
            
        }
        // West
        if (currentState.west == EMPTY)
        {
            // Create new state and node by applying move
            int nextR = currentState.row;
            int nextC = currentState.col - 1;
            MazeBlock childState = m.get(nextR, nextC);
            // Check if this state has been visited, skip if it has
            if (!this->stateVisited(childState.ind))
            {
                // This is a new state, add it to the tree
                SearchNode* childNode = this->addState(childState, currentNode);
                this->moveStack.push(childNode);
            }
        }
        // North
        if (currentState.north == EMPTY)
        {
            // Create new state and node by applying move
            int nextR = currentState.row - 1;
            int nextC = currentState.col;
            MazeBlock childState = m.get(nextR, nextC);
            // Check if this state has been visited, skip if it has
            if (!this->stateVisited(childState.ind))
            {
                // This is a new state, add it to the tree
                SearchNode* childNode = this->addState(childState, currentNode);
                this->moveStack.push(childNode);
            }
        }
    }

    return NULL;
}
