#ifndef __MAZE_H
#define __MAZE_H

#include "MazeDefinitions.h"
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>

class Maze
{
public:
    Maze(std::vector<MazeBlock>& grid, int w, int h);
    ~Maze();

    MazeBlock get(int ind) const;
    MazeBlock get(int r, int c) const;

    int ind(int r, int c) const;
    void printBlocks() const;
    void printSolution(std::vector<SearchNode*> path) const;

    friend std::ostream& operator<< (std::ostream& stream, const Maze& maze);

    static Maze fromTextFile(std::string path);

protected:
    int _width;
    int _height;
    std::vector<MazeBlock> _grid;
};

#endif