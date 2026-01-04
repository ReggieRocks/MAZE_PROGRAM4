/*******************************************************
 * Scott Schmidt
 * IT 279 – Program 4
 * Maze Generator Driver

git add .
git commit -m "Describe change"
git push

g++ -std=c++17 DisjointSet.cpp Maze.cpp MazeGenerator.cpp -o maze
 *******************************************************/

#include "Maze.h"
#include <cstdlib>
#include <string>
using namespace std;

int main(int argc, char* argv[]) {
    //Four Arguments are Required; 5th is Optional: 
    if (argc < 5) {
        return 1;
    }

    int rows = atoi(argv[1]);
    int cols = atoi(argv[2]);
    string outputFile= argv[3]; //output
    unsigned int seed = atoi(argv[4]); //conert string to int

    Maze maze(rows, cols);

    // Extra credit: optional early stop argument
    if (argc == 6) {
        maze.setStopEarly(true);
    }

    maze.generate(seed);

    maze.printMaze(outputFile);

    return 0;
}
