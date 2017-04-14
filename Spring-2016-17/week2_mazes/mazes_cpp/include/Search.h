#ifndef __SEARCH_H
#define __SEARCH_H

#include "MazeDefinitions.h"
#include <unordered_map>

/**
 * Deines a node to represented a visited part of the maze and the part of the
 * maze where it came from
 */
class SearchNode
{
public:
    SearchNode(MazeBlock s, SearchNode* p) : state(s), parent(p) {}
    /**
     * Copy constructor
     */
    SearchNode(const SearchNode& node) : state(node.state), parent(node.parent) {}
    ~SearchNode() {}

    static std::vector<SearchNode*> trace(SearchNode* node);

    SearchNode& operator=(const SearchNode& rhs);

    const MazeBlock state;
    SearchNode* parent;
};

/**
 * Abstract class representing a search algorithm. Defines useful methods and
 * variables for searching and checking visited nodes
 */
class Search
{
public:
    Search() {}
    ~Search();

    SearchNode* addState(MazeBlock state, SearchNode* parent);
    bool stateVisited(int state);

    /** 
     * Method that must be implemented of classes inheriting from search. This
     * defines the search algorithm
     */
    virtual SearchNode* search(Maze m) = 0;
protected:
    /**
     * Stores all visited nodes by their index for lookup purposes and so all
     * visited nodes can be deleted on destruction
     */
    std::unordered_map<int, SearchNode*> _states;
};

#endif
