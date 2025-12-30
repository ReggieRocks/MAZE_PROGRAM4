# MAZE_PROGRAM4
Description:
You will develop a C++ class that implements a disjoint set using union by size and path compression. 
It will have a constructor that specifies the number of objects, a find method that returns the set label (an int) for an object given its index, and a doUnion method that takes two object indices, performs the appropriate union, and returns true if the resulting set is the same size as the number of objects. You have been provided with a DisjointSet.h file and a partial DisjointSet.cpp file.

You will use your disjoint set class to help you create and print a random maze to a file. 
This program will take in several command line arguments – you have been provided the code that handles that.  
In order, the arguments are: the number of rows in the maze, the number of columns in the maze, the file name to print the maze to, and a random seed (0 to have the seed based on the current clock). There is an optional final parameter for stopping the maze generation early (as discussed in the video). This is a small extra credit opportunity. You may assume you have at least two rows and two columns for each maze. This is the only assumption you should make about the dimensions of the maze.

Because this will be automatically graded in terms of correctness, 
make sure that you generate your random locations as follows: 
	•	generate a random number (using rand()) in the range 0 to number of cells -1
	•	generate a random number in the range 0-3 representing directions:
0: left
1: down
2: right
3: up
The goal here is that you are selecting a neighbor of the first cell
	•	if the 2nd cell (the neighbor) is invalid because the first cell is at the edge of maze in that direction, go the opposite direction (0 becomes 2, 1 becomes 3, 2 becomes 0, 3 becomes 1)
	•	compute the number for the second cell given the valid direction
From this point, you will figure out whether to knock down the wall and what wall you are knocking down.

You have been provided with a starting point for your program, including code to print the maze.Review it carefully.
Be sure to add your name to all files that you modify.
Make sure you don’t change any file names.
For the extra credit option, you will add to Maze.h, Maze.cpp, and MazeGenerator.cpp the necessary code to tell the generation process to stop early and to execute it. It might be useful to add an instance variable to the Maze class. Remember that extra credit only applies to A or B programs (which must work correctly on all provided example data as well as being well designed, appropriately commented, and following assignment instructions). Make sure that you focus first on meeting the assignment expectations before attempting the extra credit. Your additional command line parameter must be optional.

Provided files
The code and sample output can be found in /home/ad.ilstu.edu/mbhatt1/Public/it279/Program4. 
The file testerOutput is the output from running the DisjointSetTester program. 
You also have the output files from running the program with the following two sets of command line arguments:

a.out 5 5 maze1 101
a.out 20 20 maze2 5803

Submission requirements:
If you are not doing the extra credit, you will submit DisjointSet.cpp, Maze.h, and Maze.cpp only. 
Note that a well-designed answer will have changes to Maze.h (private only) as well as to the .cpp files.

If you do the extra credit (adding the early stopping as soon as there is a path from start to finish in the maze),
you will also need to submit MazeGenerator.cpp, because you will need to modify it.

If you are doing the extra credit indicate that a comment on the assignment in Canvas 
or it will NOT be checked and you will not receive credit for it.

Zip your files (no folders). Attach the zip file and submit. 

Do not submit the DisjointSet.h file. Do not submit the MazeGenerator.cpp file unless you are doing the extra credit.
Failure to submit your program in accordance with instructions will result in a grade reduction.

As always, grading will be based on the 279 Program Grading Criteria posted. A and B programs submitted early will receive a 0.10 early submission grade bonus.
