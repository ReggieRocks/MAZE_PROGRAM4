
/*******************************************************
 * Scott Schmidt; Data Structures, Graphs
 * IT 279 – Illinois State University
 * Disjoint Set Implementation

 Implements a disjoint set using union by size and path compression. 
It will have a constructor that specifies the number of objects, 
a find method that returns the set label (an int) for an object given its index, 
and a doUnion method that takes two object indices, performs the appropriate union,
and returns true if the resulting set is the same size as the number of objects.
********************************************************/

#include "DisjointSet.h"
#include "DisjointSet.h"
#include <iostream>
#include <vector>
using namespace std;

DisjointSet::DisjointSet(int n) {
    parent.resize(n, -1);
}

int DisjointSet::find(int x) {
    if (parent[x] < 0)
        return x;
    return parent[x] = find(parent[x]);  // path compression
}

bool DisjointSet::doUnion(int a, int b) {
    int rootA = find(a);
    int rootB = find(b);

    if (rootA == rootB)
        return false;

    // Union by size (negative values store size)
    if (parent[rootA] < parent[rootB]) {
        parent[rootA] += parent[rootB];
        parent[rootB] = rootA;
        return (-parent[rootA] == parent.size());
    } else {
        parent[rootB] += parent[rootA];
        parent[rootA] = rootB;
        return (-parent[rootB] == parent.size());
    }
}

/*
g++ -std=c++17 DisjointSet.cpp Maze.cpp MazeGenerator.cpp -o maze
*/