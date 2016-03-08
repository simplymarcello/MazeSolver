// Created by Marcello Martins on 04/20/2015
// Last modified on 04/21/2015
// Implementation file for the ADT Maze.

/** @file Maze.cpp */

#include <iomanip>
#include <iostream>
#include <string>
#include "Maze.h"

// Defualt Constructor which inits maze_ to null and sets rows and cols to 0.
Maze::Maze() : maze_( nullptr )
{
	rows_ = 0;
	cols_ = 0;
} 

// @param input file consisting of '.' and '-' which create a maze. The name of the file inluded in my package is "input.txt".
void Maze::Fill(ifstream& InputFile) 
{
	char input;
	InputFile >> rows_ >> cols_;
	maze_ = new int[rows_ * cols_];
	for (int i = 0; i < rows_; i++)
	{
		for (int j = 0; j < cols_; j++)
		{
			InputFile >> input;
			if(input == '.')
				maze_[i * cols_ + j] = -1;
			else if(input == '-')
				maze_[i * cols_ + j] = -2;
		}
	}
}

// Recursively iterate the Maze to find a single successful path.
void Maze::SolveSinglePath(int r, int c) 
{
	static int PathsFound = 0, RecursiveCount = 0;
	if( PathsFound > 0 || r >= rows_ || c >= cols_ || r < 0 || c < 0 || maze_[r * cols_ + c ] != -1)
		return;
	maze_[r * cols_ + c] = RecursiveCount++;
	if (r == rows_-1 && c == cols_-1)
		PrintPaths(++PathsFound);
	if(PathsFound == 0)
		SolveSinglePath(r,c+1); // right
	if(PathsFound == 0)
		SolveSinglePath(r-1,c); // up
	if(PathsFound == 0)
		SolveSinglePath(r,c-1);// left
	if(PathsFound == 0)
		SolveSinglePath(r+1,c); // down
	maze_[r * cols_ + c] = -1;
	RecursiveCount--;
	if( RecursiveCount == 0 && PathsFound == 0 )
		cout << "Path could not be found... " << endl;
}

// Recursively iterate the Maze to find all successful paths.
void Maze::SolveEveryPath(int r, int c) 
{
	static int PathsFound = 0, RecursiveCount = 0;
	if( r >= rows_ || c >= cols_ || r < 0 || c < 0 || maze_[r * cols_ + c ] != -1 )
		return;
	maze_[r * cols_ + c] = RecursiveCount++;
	if (r == (rows_-1) && c == (cols_-1))
	{ 
		PrintPaths(++PathsFound);
		maze_[r * cols_ + c] = -1;
		RecursiveCount--;
		return;
	}
	SolveEveryPath(r,c+1); // right
	SolveEveryPath(r-1,c); // up
	SolveEveryPath(r,c-1); // left
	SolveEveryPath(r+1,c); // down
	maze_[r * cols_ + c] = -1;
	RecursiveCount--;
	if( RecursiveCount == 0 && PathsFound == 0 )
		cout << "Path could not be found... " << endl;
}

// Neatly print a found path.
void Maze::PrintPaths(int p)
{
	int input;
	(p == 1 ) ? (cout << "Printing first path found :" << endl) : (cout << "Printing path number " << p << ": " << endl);
	for (int i = 0; i < rows_; i++)
	{
		for (int j = 0; j < cols_; j++)
		{	
			input = maze_[i * cols_ + j];
			if(input == (-1) )
				cout << setw(3) << ".";
			else if (input == (-2) )
				cout << setw(3) << "-";
			else 
				cout << setw(3) << input;
		}
		cout << endl;
	}
	cout << endl;
}

// Destructor deallocates dynamic memory.
Maze::~Maze()
{
	delete [] maze_;
}