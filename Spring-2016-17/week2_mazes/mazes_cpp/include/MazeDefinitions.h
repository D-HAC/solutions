#ifndef __MAZE_DEFINITIONS_H
#define __MAZE_DEFINITIONS_H

#include <string>

// This file is included by all source and header files in the project

// Representation of possible states that a maze can take on
enum MazeState { EMPTY, WALL, ENTRANCE, EXIT };

// Character representations of maze
const char CHAR_EMPTY = ' ';
const char CHAR_WALL_NS = '-';
const char CHAR_WALL_EW = '|';
const char CHAR_SOLUTION = '#';

// String representations of maze
const std::string STR_EMPTY_NS = "  ";
const std::string STR_EMPTY_EW = " ";
const std::string STR_WALL_NS = "--";
const std::string STR_WALL_EW = "|";
const std::string STR_CORNER = "+";

// I added forward declarations of all my classes because includes are a pain
class MazeBlock;
class Maze;
class SearchNode;
class Search;
class DepthFirstSearch;

#include "MazeBlock.h"
#include "Maze.h"
#include "Search.h"
#include "DepthFirstSearch.h"

#endif
