/*******************************************************
 * Scott Schmidt
 * IT 279 – Program 4
 * Maze Generator Driver
 *******************************************************/

#include "Maze.h"
#include <cstdlib>
#include <string>
using namespace std;

int main(int argc, char* argv[]) {
    if (argc < 5) {
        return 1;
    }

    int rows = atoi(argv[1]);
    int cols = atoi(argv[2]);
    string filename = argv[3];
    unsigned int seed = atoi(argv[4]);

    Maze maze(rows, cols);

    // Extra credit: optional early stop argument
    if (argc == 6) {
        maze.setStopEarly(true);
    }

    maze.generate(seed);
    maze.printMaze(filename);

    return 0;
}
