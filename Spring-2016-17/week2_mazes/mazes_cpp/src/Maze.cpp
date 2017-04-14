#include "MazeDefinitions.h"

/**
 * Create a maze from a 1D vector of maze blocks with given dimensions
 */
Maze::Maze(std::vector<MazeBlock>& grid, int h, int w)
{
    this->_grid = grid;
    this->_height = h;
    this->_width = w;
}

Maze::~Maze(){}

/**
 * Get the maze block at the specified array index
 */
MazeBlock Maze::get(int ind) const
{
    return this->_grid[ind];
}

/**
 * Get the maze block at the specified row and column
 */
MazeBlock Maze::get(int r, int c) const
{
    return this->_grid[this->ind(r, c)];
}

/**
 * Convert row and column to array index
 */
int Maze::ind(int r, int c) const
{
    return this->_width*r + c;
}

/**
 * Print maze to ostream
 */
std::ostream& operator<< (std::ostream& stream, const Maze& maze)
{
    // Top
    stream << STR_CORNER;
    for(int c = 0; c < maze._width; c++)
    {
        std::string strNorth = maze._grid[maze.ind(0, c)].north == WALL ?
                               STR_WALL_NS : STR_EMPTY_NS;
        stream << strNorth << STR_CORNER;
    }
    stream << std::endl;
    // Rest of the rows
    for (int r = 0; r < maze._height; r++)
    {
        // West for column 0
        std::string strWest = maze._grid[maze.ind(r, 0)].west == WALL ?
                                  STR_WALL_EW : STR_EMPTY_EW;
        stream << strWest;
        // East for the rest of the columns
        for(int c = 0; c < maze._width; c++)
        {
            std::string strEast = maze._grid[maze.ind(r, c)].east == WALL ?
                                  STR_WALL_EW : STR_EMPTY_EW;
            stream << "  " << strEast;
        }
        stream << std::endl;
        // Bottom
        stream << STR_CORNER;
        for(int c = 0; c < maze._width; c++)
        {
            std::string strSouth = maze._grid[maze.ind(r, c)].south == WALL ?
                                   STR_WALL_NS : STR_EMPTY_NS;
            stream << strSouth << STR_CORNER;
        }
        stream << std::endl;
    }
    return stream;
}

/**
 * Print each block of maze on its own line. This can be used to make sure all 
 * blocks are properly created
 */
void Maze::printBlocks() const
{
    for(int r = 0; r < this->_height; r++)
    {
        for(int c = 0; c < this->_width; c++)
        {
            std::cout << this->_grid[this->ind(r, c)] << std::endl << std::endl;
        }
    }
}

/**
 * Print the maze to stdout highlighting the nodes in the given vector
 */
void Maze::printSolution(std::vector<SearchNode*> path) const
{
    std::stringstream solution;
    solution << *this;
    // Read into vector of strings
    std::string line;
    std::vector<std::string> lines;
    while(std::getline(solution, line, '\n'))
    {
        lines.push_back(line);
    }

    // Draw solution
    for (SearchNode* node : path)
    {
        lines[2*node->state.row + 1][3*node->state.col + 1] = CHAR_SOLUTION;
        lines[2*node->state.row + 1][3*node->state.col + 2] = CHAR_SOLUTION;
    }

    // Print maze with solution
    for (std::string line : lines)
    {
        std::cout << line << std::endl;
    }
}

/**
 * Create a maze from given file
 */
Maze Maze::fromTextFile(std::string path)
{
    // Read whole file
    std::ifstream file(path);
    std::stringstream buffer;
    buffer << file.rdbuf();

    // Read into vector of strings
    std::string line;
    std::vector<std::string> lines;
    while(std::getline(buffer, line, '\n'))
    {
        lines.push_back(line);
        std::cout << line << std::endl;
    }

    // Calculate dimensions of maze
    int height = (lines.size() - 1) / 2;
    int width = (lines[0].length() - 1) / 3;

    // Create puzzle blocks
    std::vector<MazeBlock> grid;
    for (int r = 0; r < height; r++)
    {
        for (int c = 0; c < width; c++)
        {
            MazeState n, s, e, w;

            // North
            if (lines[2*r][3*c + 1] == CHAR_WALL_NS)
            {
                n = WALL;
            }
            else
            {
                n = EMPTY;
            }
            // East
            // Edge case...
            if (r == (height - 1) && c == (width - 1))
            {
                e = EXIT;
            }
            else if (lines[2*r + 1][3*c + 3] == CHAR_WALL_EW)
            {
                e = WALL;
            }
            else
            {
                e = EMPTY;
            }
            // South
            if (lines[2*r + 2][3*c + 1] == CHAR_WALL_NS)
            {
                s = WALL;
            }
            else
            {
                s = EMPTY;
            }
            // West
            // Edge case...
            if (r == 0 && c == 0)
            {
                w = ENTRANCE;
            }
            else if (lines[2*r + 1][3*c] == CHAR_WALL_EW)
            {
                w = WALL;
            }
            else
            {
                w = EMPTY;
            }

            grid.push_back(MazeBlock(r*width + c, r, c, n, e, s, w));
        }
    }

    return Maze(grid, height, width);
}
