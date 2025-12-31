/*******************************************************
 * Scott Schmidt; Data Structures using Graphs
 * IT 279 – Program 4
 * Disjoint Set (Union-Find) Class
 
 * Implements union by size and path compression.
 *******************************************************/

#ifndef DISJOINTSET_H
#define DISJOINTSET_H
#include <vector>
using namespace std;

class DisjointSet {
private:
    vector<int> parent;   // parent[i] < 0 means i is root, |parent[i]| = size

public:
    // Constructor: creates n disjoint sets
    DisjointSet(int n);

    // Find the root (set label) of element x
    // Uses path compression
    int find(int x);

    // Unions the sets containing a and b
    // Returns true if the resulting set contains all elements
    bool doUnion(int a, int b);
};

#endif
