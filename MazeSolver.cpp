// Created by Marcello Martins on 04/20/2015
// Last modified on 04/21/2015

/** @file MazeSolver.h */

#include <iostream>
#include <fstream> 
#include "Maze.h"

using namespace std;

int main(int argc, char const *argv[])
{
	// Open input stream with the second value from the command line as the parameter.
	ifstream FileInput(argv[2]);

	// Check to make sure the file is open else show error.
	if( FileInput.is_open() )
	{
		// Create instance of maze class.
		Maze myMaze;

		// Use method Fill to input the values into the maze instance.
		myMaze.Fill(FileInput);

		// Check which action to take based on first value from the command line.
		if(atoi(argv[1]) == 1)
			myMaze.SolveSinglePath(); // Find only one path, and print.
		else 
			myMaze.SolveEveryPath(); // Find all paths, and print each one.
	}

	else 
		cerr << "ERROR: Your second parameter failed to open, Program exiting..." << endl; // Send error if input file coult not open.

	return 0;
} // end MAIN 