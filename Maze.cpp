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
        //EDGE CHECK:
        int cols;
        int rows;
        bool top_edge = (rows==0);
        bool bottom_edge = (rows == rows-1);
        bool left_edge = (cols == 0);
        bool right_edge = (cols == cols-1);

        // FLIP DIRECTION:  0 (L) <-> 2 (R).  1 (D) <-> 3 (U)
        if (top_edge && dir==3) {dir = 1;}
        else if (bottom_edge && dir ==1) { dir=3;}
        else if(left_edge && dir==0) {dir=2;}
        else if(right_edge && dir==2) {dir=0;}


         /*
        4) Compute neighbor cell index from (cell, dir)
        Maze indexing example (rows = 2, cols = 4):

            [ 0 ][ 1 ][ 2 ][ 3 ]
            [ 4 ][ 5 ][ 6 ][ 7 ]

        RIGHT → cell + 1
        DOWN  → cell + cols
        */

        int neighbor = -1; //temporary placeholder 
        if (dir==0) {neighbor=cell-1;} //go left one
        else if (dir==1) {neighbor=cell+rows;} //go down one
        else if (dir==2) {neighbor=cell+1;} // go right one
        else if (dir==3) {neighbor=cell-rows;} //to up one

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
            out << "   ";

            // TODO: print right wall if it exists,
            // otherwise print a space
        }
        out << endl;

        // Print bottom walls
        out << "+";
        for (int c = 0; c < cols; c++) {
            // TODO: print bottom wall if it exists,
            // otherwise print spaces
            // must end each cell with '+'
        }
        out << endl;
    }
    out.close();
}