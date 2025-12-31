/*******************************************************
 * Scott Schmidt
 * IT 279 – Program 4
 * Maze Class // Maze.cpp (template)
 *******************************************************/ 

#include "Maze.h"
#include "DisjointSet.h"
 
#include <cstdlib>   // rand, srand
#include <ctime>     // time
#include <fstream>   // ofstream
 
Maze::Maze(int r, int c)
    : rows(r), cols(c), walls(r * c, 15), stopEarly(false) // 15 = 1111 (all walls)
{

}
 
void Maze::setStopEarly(bool value) {
    stopEarly = value;
}

/*******************************************************
Generate your random locations as follows:
• generate a random number (using rand()) in the range 0 to number of cells -1 
• generate a random number in the range 0-3 representing directions: 0: left 1: down 2: right 3: up 
The goal here is that you are selecting a neighbor of the first cell 
• if the 2nd cell (the neighbor) is invalid because the first cell is at the edge of maze in that direction,
 go the opposite direction (0 becomes 2, 1 becomes 3, 2 becomes 0, 3 becomes 1) 
• compute the number for the second cell given the valid direction 
From this point, you will figure out whether to knock down the wall and what wall you are knocking down.
 *******************************************************/ 
void Maze::generate(unsigned int seed) {
    if (seed == 0) {
        srand(static_cast<unsigned>(time(nullptr)));
    } else {
        srand(seed);
    }
 
    const int total = rows * cols;
    DisjointSet ds(total);
 
    int successfulUnions = 0;
 
    // Stop normally when the maze is fully connected (N-1 successful unions).
    while (successfulUnions < total - 1) {
        // 1) Pick random cell [0..total-1]
        int cell = rand() % total;
 
        // 2) Pick random direction [0..3] (0=L,1=D,2=R,3=U)
        int dir = rand() % 4;
 
        // 3) If neighbor invalid (edge), flip direction to opposite
        // TODO: implement edge check + dir flip exactly per assignment
 
        // 4) Compute neighbor cell index from (cell, dir)
        // TODO: implement neighbor computation
        int neighbor = -1;
 
        // If you haven't implemented neighbor yet, skip safely:
        if (neighbor < 0 || neighbor >= total || neighbor == cell) {
            continue;
        }
 
        // 5) If in different sets, union + remove walls
        if (ds.find(cell) != ds.find(neighbor)) {
            ds.doUnion(cell, neighbor);
 
            // 6) Remove the correct walls in BOTH cells
            // TODO: implement wall bit removal based on dir + your encoding
            ++successfulUnions;
 
            // Extra credit: stop as soon as start connects to finish
            if (stopEarly && ds.find(0) == ds.find(total - 1)) {
                break;
            }
        }
    }
}
 
void Maze::printMaze(const string& filename) const {
    ofstream out(filename);
    if (!out) return;
 
    // TODO (AUTOGRADER): Replace this with the instructor-provided printing logic.
    // Leaving it empty is fine for now, but it will not match required output.
    out << "hello world\n";  // TEMP DEBUG
 
    out.close();
}