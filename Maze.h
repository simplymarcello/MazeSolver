// Created by Marcello Martins on 04/20/2015
// Last modified on 04/21/2015
// Header file for the ADT Maze.

/** @file Maze.h */

#ifndef _MAZE
#define _MAZE

using namespace std;

// This MAZE class is to be used as a container which can hold, and solve mazes.

class Maze
{

public:


	// Default Constructor which calls fill to create the maze.
	Maze();

	// Fills the maze with numerical values via loop and ifsteam.
	// @param ifstream, an ifstream to the input file.
	void Fill(ifstream &);

	// Recursively iterates the Maze to find a single successful path, then prints that path.
	// @param r, this is the starting row of the maze, here it should be left empty or set to 0.
	// @param c, this is the starting column of the maze, here it should be left empty or set to 0.
	void SolveSinglePath(int r = 0, int c = 0);

	// Recursively iterates the Maze to find all successful paths, This method will print each path as it finds it.
	// @param r, this is the starting row of the maze, here it should be left empty or set to 0.
	// @param c, this is the starting column of the maze, here it should be left empty or set to 0.
	void SolveEveryPath(int r = 0, int c = 0);

	// Neatly prints the array in it's current state.
	// @param p, p is used here to refer to which path it is printing.
	void PrintPaths(int p);

	// Destructor deallocates dynamic memory.
	~Maze();

private:

	// ints rows and cols store the size of the maze, aka the rows * columns.
	int rows_ = 0, cols_ = 0;

	// Pointer to the dynamically created maze array.
	int * maze_;

}; // end MAZE

#include "Maze.cpp"
#endif  // _MAZE
