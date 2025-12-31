/*******************************************************
 * Scott Schmidt; DataStructures Using Graphs
 * IT 279 – Program 4 - Illinois State University 
 * Maze Implementation
 *******************************************************/

#include "Maze.h"
#include "DisjointSet.h"
#include <fstream>
#include <cstdlib>
#include <ctime>

Maze::Maze(int r, int c)
    : rows(r), cols(c), stopEarly(false)
{
    // Initialize all walls as present
    walls.resize(rows * cols, 15); // 1111 = all walls
}

void Maze::setStopEarly(bool value) {
    stopEarly = value;
}

void Maze::generate(unsigned int seed) {
    if (seed == 0)
        srand(time(nullptr));
    else
        srand(seed);

    DisjointSet ds(rows * cols);

    // Main maze generation loop
    while (true) {
        // TODO:
        // 1. Pick random cell
        // 2. Pick random direction
        // 3. Handle edge cases
        // 4. Compute neighbor cell
        // 5. Union sets if different
        // 6. Remove walls

        // Extra credit early stopping
        if (stopEarly) {
            if (ds.find(0) == ds.find(rows * cols - 1)) {
                break;
            }
        }
    }
}

void Maze::printMaze(const string& filename) const {
    ofstream out(filename);

    if (!out)
        return;

    // NOTE:
    // The instructor-provided printing logic
    // should go here. Do NOT invent your own
    // formatting unless instructed.

    out.close();
}
