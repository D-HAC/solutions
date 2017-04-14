#include "MazeDefinitions.h"
#include <vector>

int main(int argc, char* argv[])
{
    // Get puzzle filename from command line args
    if (argc != 2)
    {
        std::cout << "Usage: ./maze.exe [puzzle filename]" << std::endl;
    }
    std::string puzzleFile = argv[1];

    // Create maze
    Maze maze = Maze::fromTextFile(puzzleFile);

    // Create searcher and solve maze
    Search* searcher = new DepthFirstSearch();
    SearchNode* finalNode = searcher->search(maze);

    // Get path through maze and print it
    std::vector<SearchNode*> route = SearchNode::trace(finalNode);
    maze.printSolution(route);
    return 0;
}