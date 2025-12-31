/*******************************************************
 * Scott Schmidt
 * IT 279 – Program 4
 * Maze Class
 *******************************************************/

#ifndef MAZE_H
#define MAZE_H

#include <vector>
#include <string>
using namespace std;

class Maze {
private:
    int rows;
    int cols;

    // Each cell stores wall information
    // You may encode walls however you choose
    vector<int> walls;

    // Extra credit: stop early flag
    bool stopEarly;

public:
    Maze(int r, int c);

    // Generate the maze using a DisjointSet
    void generate(unsigned int seed);

    // Print the maze to a file
    void printMaze(const string& filename) const;

    // Extra credit setter (safe even if unused)
    void setStopEarly(bool value);
};

#endif
