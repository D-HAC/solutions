#include "MazeDefinitions.h"

/**
 * Delete all search nodes allocated while searching
 */
Search::~Search()
{
    for (auto pair : this->_states)
    {
        delete pair.second;
    }
}

/**
 * Add maze block to map of vistited states
 */
SearchNode* Search::addState(MazeBlock state, SearchNode* parent)
{
    SearchNode* node = new SearchNode(state, parent);
    this->_states.emplace(state.ind, node);
    return node;
}

/**
 * Check if maze block has been visited by search by checking if the array index
 * of the block is in the list of visited states.
 */
bool Search::stateVisited(int state)
{
    return this->_states.find(state) != this->_states.end();
}

/**
 * Create a vector of visited maze blocks by iterating through the parents of
 * the given node until a NULL node is reached.
 */
std::vector<SearchNode*> SearchNode::trace(SearchNode* node)
{
    std::vector<SearchNode*> visited;
    while(node != NULL)
    {
        visited.push_back(node);
        node = node->parent;
    }
    return visited;
}

/**
 * Copy another Search to this one. It is never used and that's good because I'm
 * pretty sure it would lead to memory leaks. But for whatever reason I couldn't
 * get rid of compile errors without it
 */
SearchNode& SearchNode::operator=(const SearchNode& rhs)
{
    return *(new SearchNode(rhs));
}
