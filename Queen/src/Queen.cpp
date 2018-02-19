//============================================================================
// Name        : Queen.cpp
// Author      : Navid Saboori
// Version     :
// Copyright   : Sky2464
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>

#include <cstdio>
#include <cstdlib>
#define N 8 //fixing the value of board
using namespace std;

void printBoard();
bool check(int board[8][8], int row, int col);
bool output(int board[8][8], int col);
bool findSolution(int i);

int main()
{
	for (int i = 0; i < 8; i++) {
		findSolution(i);
		cout << "\n\n";
	}
	return 0;
}

//find the final output of the 8 queens problem
bool output(int board[8][8], int col)
{
	if (col >= 8)
		return true;
	for (int i = 0; i < 8; i++)
	{
		if (check(board, i, col))
		{
			board[i][col] = 1;
			if (output(board, col + 1) == true)
				return true;
			board[i][col] = 0;
		}
	}
	return false;
}


// check if a queen can be placed to avoid conflicts in the row and column
bool check(int board[8][8], int row, int col)
{
	int i, j;
	for (i = 0; i < col; i++)
	{
		if (board[row][i])
			return false;
	}
	for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
	{
		if (board[i][j])
			return false;
	}

	for (i = row, j = col; j >= 0 && i < 8; i++, j--)
	{
		if (board[i][j])
			return false;
	}

	return true;
}

//to print the output on to the screen we use this method
void printBoard(int board[8][8])
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
			cout << board[i][j] << " "; //prints the board values
		cout << endl; //ending the line
	}
}


//using backtracking to solve the 8 Queen problem
bool findSolution(int i)
{
	int board[8][8] = { 0 };
	if (output(board, i) == false)
	{
		cout << "Solution does not exist" << endl;
		return false;
	}
	printBoard(board);
	return true;
}

// Main method calling the funtion to solve the 8 queens problem
