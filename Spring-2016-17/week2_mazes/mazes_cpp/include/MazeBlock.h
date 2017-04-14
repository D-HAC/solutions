#ifndef __MAZE_BLOCK_H
#define __MAZE_BLOCK_H

#include "MazeDefinitions.h"
#include <ostream>
#include <iostream>

class MazeBlock
{
public:
    /**
     * Default constructor - This is never used but it got rid of compile errors
     */
    MazeBlock() :
        ind(-1),
        row(0),
        col(-1),
        north(WALL),
        east(WALL),
        south(WALL),
        west(WALL)
    {
        std::cout << "what" << std::endl;
    }

    MazeBlock(int i, int r, int c, MazeState n, MazeState e, MazeState s, MazeState w):
        ind(i),
        row(r),
        col(c),
        north(n),
        east(e),
        south(s),
        west(w) 
    {

    }
    
    /**
     * Copy constructor
     */
    MazeBlock(const MazeBlock& m) :
        ind(m.ind),
        row(m.row),
        col(m.col),
        north(m.north),
        east(m.east),
        south(m.south),
        west(m.west) 
    {

    }
    
    ~MazeBlock() { }

    bool atExit() const;

    MazeBlock& operator=(const MazeBlock&);

    friend std::ostream& operator<< (std::ostream& stream, const MazeBlock& block);

    // I made everything const so it could be public but never changed
    const int ind;
    const int row;
    const int col;
    const MazeState north;
    const MazeState east;
    const MazeState south;
    const MazeState west;
};

#endif
