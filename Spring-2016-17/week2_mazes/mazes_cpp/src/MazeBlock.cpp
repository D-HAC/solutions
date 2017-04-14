#include "MazeDefinitions.h"

/**
 * Returns true if an exit block exists in any direction (I could just check 
 * west/right but that isn't be general enough for me)
 */
bool MazeBlock::atExit() const
{
    return this->north == EXIT || this->east == EXIT || this->south == EXIT ||
           this->west == EXIT;
}

/*
 * Copy another MazeBlock to this one. It is never used and that's good because
 * I'm pretty sure it would lead to memory leaks. But for whatever reason I
 * couldn't get rid of compile errors without it
 */
MazeBlock& MazeBlock::operator=(const MazeBlock& rhs)
{ 
    std::cout << "no pls" << std::endl;
    return *(new MazeBlock(rhs));
}

/**
 * Print block to ostream
 */
std::ostream& operator<< (std::ostream& stream, const MazeBlock& block)
{
    // Top
    stream << STR_CORNER;
    if (block.north == WALL)
    {
        stream << STR_WALL_NS;
    }
    else
    {
        stream << STR_EMPTY_NS;
    }
    stream << STR_CORNER << std::endl;
    // Left
    if (block.west == WALL)
    {
        stream << STR_WALL_EW;
    }
    else
    {
        stream << STR_EMPTY_EW;
    }
    // Middle
    stream << "  ";
    // Right
    if (block.east == WALL)
    {
        stream << STR_WALL_EW;
    }
    else
    {
        stream << STR_EMPTY_EW;
    }
    stream << std::endl;
    // Bottom
    stream << STR_CORNER;
    if (block.south == WALL)
    {
        stream << STR_WALL_NS;
    }
    else
    {
        stream << STR_EMPTY_NS;
    }
    stream << STR_CORNER << std::endl;
    return stream;    
}
