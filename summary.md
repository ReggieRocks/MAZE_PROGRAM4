# Spell Checker — Cover Page & Summary

## Cover Page
Assignment number: 
Student name(s): Scott Schmidt 
Student ULID: sschmi2@ilstu.edu 
Secret directory: ______________________________
Course: IT279 Data Structures, Illinois State Univeristy

---

## Brief Summary
This program generates a random maze using a disjoint set (union–find) data structure implemented in C++. The maze is represented as a grid (matrix) of cells, and the union–find structure is used to track which cells are connected as walls are removed.

[ 0 ][ 1 ][ 2 ]
[ 3 ][ 4 ][ 5 ]
[ 6 ][ 7 ][ 8 ]

A DisjointSet class is implemented using union by size and path compression. This class supports finding which set a cell belongs to and uniting two cells when a wall is removed.

The maze generation program uses the disjoint set to determine whether two neighboring cells should be connected by knocking down a wall. Random cells and directions are generated following the required rules to ensure correct and repeatable maze construction.

The program takes command-line arguments specifying the maze dimensions, output file name, random seed, and an optional parameter to stop maze generation early. The final maze is printed to a file using the provided printing code. This program was compiled and tested using C++ (g++) and follows all provided assignment constraints.

Maze Generation Process:
Each step:
Pick a random cell
Pick a random direction (left, down, right, up)
Find the neighboring cell

Check the disjoint set:
Are these two cells already connected?
If NO: Remove the wall → 1 → 0

Union the two cells
If YES: Do nothing and Try another random cell/direction

At the end, this is what the maze will look like: 
[  0 ]──[  1 ]   [  2 ]
   │        │
[  4 ]   [  5 ]──[  6 ]
   │
[  8 ]──[  9 ]   [ 10 ]

A maze with N cells is complete after N − 1 successful unions. 
At this point all cells are connected. 

## A hard-copy of the direct output of your program
The output of the program was redirected to a text file using Unix redirection commands. 
This output matches the program’s actual execution and was used for verification.


## A hard-copy of the source codes
(optional, only when you want me to check and remark your program.)
