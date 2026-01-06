/*******************************************************
 * Scott Schmidt
 * IT 279 – Program 4
 * Maze Class // Maze.cpp 
 *******************************************************/ 
#include "Maze.h"
#include "DisjointSet.h"
 
#include <cstdlib>   // rand, srand
#include <ctime>     // time
#include <fstream>   // ofstream
 
namespace {
    // Wall bit encoding per cell (4-bit mask):
    // 1 = left, 2 = down, 4 = right, 8 = up
    constexpr int WALL_LEFT  = 1;
    constexpr int WALL_DOWN  = 2;
    constexpr int WALL_RIGHT = 4;
    constexpr int WALL_UP    = 8;

    constexpr int DIR_LEFT  = 0;
    constexpr int DIR_DOWN  = 1;
    constexpr int DIR_RIGHT = 2;
    constexpr int DIR_UP    = 3;

    int oppositeDir(int dir) {
        switch (dir) {
            case DIR_LEFT:  return DIR_RIGHT;
            case DIR_DOWN:  return DIR_UP;
            case DIR_RIGHT: return DIR_LEFT;
            case DIR_UP:    return DIR_DOWN;
            default:        return dir;
        }
    }
}

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
• generate a random number in the range 0-3 representing directions: 
0: left
1: down 
2: right 
3: up 
The goal here is that you are selecting a neighbor of the first cell 
• if the 2nd cell (the neighbor) is invalid because the first cell is at the edge of maze in that direction,
 go the opposite direction (0 becomes 2, 1 becomes 3, 2 becomes 0, 3 becomes 1) 
• compute the number for the second cell given the valid direction 
From this point, you will figure out whether to knock down the wall and what wall you are knocking down.
 *******************************************************/ 
void Maze::generate(unsigned int seed) {
    // Random Number Generated for Different Mazes:
    if (seed == 0) {
        srand(static_cast<unsigned>(time(nullptr)));
    } else {
        srand(seed);
    }
 
    const int total = rows * cols; //total number of cells in matrix 
    DisjointSet ds(total); //tracks which cells are connected (unioned)

    int successfulUnions = 0; //count for how many cells were connected
 
    // Stop normally when the maze is fully connected (N-1 successful unions).
    while (successfulUnions < total - 1) {
        // 1) Pick random cell [0..total-1]
        int cell = rand() % total;
 
        // 2) Pick random direction [0..3] (0=L,1=D,2=R,3=U)
        int dir = rand() % 4; // gets a number between 0 and 3 
 
        // 3) If neighbor invalid (edge), flip direction 
        const int cellRow = cell / cols;
        const int cellCol = cell % cols;
        const bool top_edge = (cellRow == 0);
        const bool bottom_edge = (cellRow == rows - 1);
        const bool left_edge = (cellCol == 0);
        const bool right_edge = (cellCol == cols - 1);

        // FLIP DIRECTION:  0 (L) <-> 2 (R).  1 (D) <-> 3 (U)
        if ((top_edge && dir == DIR_UP) ||
            (bottom_edge && dir == DIR_DOWN) ||
            (left_edge && dir == DIR_LEFT) ||
            (right_edge && dir == DIR_RIGHT)) {
            dir = oppositeDir(dir);
        }


         /*
        4) Compute neighbor cell index from (cell, dir)
        Maze indexing example (rows = 2, cols = 4):

            [ 0 ][ 1 ][ 2 ][ 3 ]
            [ 4 ][ 5 ][ 6 ][ 7 ]

        RIGHT → cell + 1
        DOWN  → cell + cols
        */

        int neighbor = -1; //temporary placeholder 
        if (dir == DIR_LEFT) { neighbor = cell - 1; }          // left one
        else if (dir == DIR_DOWN) { neighbor = cell + cols; }  // down one row
        else if (dir == DIR_RIGHT) { neighbor = cell + 1; }    // right one
        else if (dir == DIR_UP) { neighbor = cell - cols; }    // up one row

        // If you haven't implemented neighbor yet, skip safely:
        if (neighbor < 0 || neighbor >= total || neighbor == cell) {
            continue;
        }
 
        // 5) If in different sets, union + remove walls
        if (ds.find(cell) != ds.find(neighbor)) {
            ds.doUnion(cell, neighbor);
 
            // 6) Remove the correct walls in BOTH cells
            if (dir == DIR_LEFT) {
                walls[cell] &= ~WALL_LEFT;
                walls[neighbor] &= ~WALL_RIGHT;
            } else if (dir == DIR_DOWN) {
                walls[cell] &= ~WALL_DOWN;
                walls[neighbor] &= ~WALL_UP;
            } else if (dir == DIR_RIGHT) {
                walls[cell] &= ~WALL_RIGHT;
                walls[neighbor] &= ~WALL_LEFT;
            } else if (dir == DIR_UP) {
                walls[cell] &= ~WALL_UP;
                walls[neighbor] &= ~WALL_DOWN;
            }
            ++successfulUnions;
 
            // Extra credit: stop as soon as start connects to finish
            if (stopEarly && ds.find(0) == ds.find(total - 1)) {
                break;
            }
        }
    }
}

/*
    printMaze prints the maze to a file.

    The exact formatting of the maze is provided
    by the instructor. This function should only
    output the maze based on the current maze
    data structure.
*/
void Maze::printMaze(const string& outputFile) const {
    ofstream out(outputFile);
    if (!out) {
        return;
    }

    // Print the top border
    out << "+";
    for (int c = 0; c < cols; c++) {
        out << "---+";
    }
    out << endl;

    // Print each row of the maze
    for (int r = 0; r < rows; r++) {

        // Print left wall of row
        out << "|";

        // Print cells and right walls
        for (int c = 0; c < cols; c++) {
            const int cell = r * cols + c;
            out << "   ";

            // print right wall if it exists, otherwise print a space
            out << ((walls[cell] & WALL_RIGHT) ? "|" : " ");
        }
        out << endl;

        // Print bottom walls
        out << "+";
        for (int c = 0; c < cols; c++) {
            const int cell = r * cols + c;

            // print bottom wall if it exists, otherwise print spaces
            // must end each cell with '+'
            out << ((walls[cell] & WALL_DOWN) ? "---" : "   ") << "+";
        }
        out << endl;
    }
    out.close();
}

