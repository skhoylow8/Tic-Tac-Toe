#include<iostream>
#include <string>
#include "Board.h"
#include "Player.h"

/**
This function clears the game board.
*/
void Board::clearBoard()
{
	std::cout << "\n";
	std::cout << "This is a now a new round.\n";
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			matrix[i][j] = {' '};
		}
	}
}

/**
This function displays the game board as it is manipulated throughout the game.
*/
void Board::displayBoard()
{

	std::cout << " " << "1" << " " << "2" << " " << "3\n";
	std::cout << "1" << matrix[0][0] << "|" << matrix[0][1] << "|" << matrix[0][2] << '\n';
	std::cout << " ----- \n";
	std::cout << "2" << matrix[1][0] << "|" << matrix[1][1] << "|" << matrix[1][2] << '\n';
	std::cout << " ----- \n";
	std::cout << "3" << matrix[2][0] << "|" << matrix[2][1] << "|" << matrix[2][2] << '\n';
}

/**
This function allows the users the manipulate the game board.
@param row is the first value
@param column is the second value
@param turn is the third value
*/
void Board::manipulateBoard(int row, int column, char turn)
{
	matrix[3][3];//This allows it to manipulate the matrix(game board)
	// Player 1's turn
	if (turn == 'x')
	{
		// Checks if the position player 1 chose is available
		if (matrix[row - 1][column - 1] == ' ' || matrix[row - 1][column - 1] != 'o')
		{
			// Assigns x to that position if it is available
			matrix[row - 1][column - 1] = 'x';
		}
	}
	// Player 2's turn
	else if (turn == 'o')
	{
		// Checks if the position player 2 chose is available
		if (matrix[row - 1][column - 1] == ' ' || matrix[row - 1][column - 1] != 'x')
		{
			// Assigns o to that position if it is available
			matrix[row - 1][column - 1] = 'o';
		}
	}
}

/**
This function checks each row in the matrix to see if one of the players won
return true if the same mark is round on either of the three rows and returns false if no one won
@param mark is the first value
@return true is someone won and false if no one won
*/
bool Board::checkRow(char mark)
{
	matrix[3][3];

	//checks the first row
	if (matrix[0][0] == mark && matrix[0][1] == mark && matrix[0][2] == mark)
	{
		return true;
	}

	//checks the second row
	if (matrix[1][0] == mark && matrix[1][1] == mark && matrix[1][2] == mark)
	{
		return true;
	}

	//checks the third row
	if (matrix[2][0] == mark && matrix[2][1] == mark && matrix[2][2] == mark)
	{
		return true;
	}
	return false;
}

/**
This function checks each column in the matrix to see if one of the players won
return true if the same mark is round on either of the three columns and returns false if no one won
@param mark is the first value
@return true is someone won and false if no one won
*/
bool Board::checkColumn(char mark)
{
	matrix[3][3];

	//checks the first column
	if (matrix[0][0] == mark && matrix[1][0] == mark && matrix[2][0] == mark)
	{
		return true;
	}

	//checks the second column
	if (matrix[0][1] == mark && matrix[1][1] == mark && matrix[2][1] == mark)
	{
		return true;
	}

	//checks the third column
	if (matrix[0][2] == mark && matrix[1][2] == mark && matrix[2][2] == mark)
	{
		return true;
	}
	return false;
}

/**
This function checks each diagonal in the matrix to see if one of the players won
return true if the same mark is round on either of the two diagonals and returns false if no one won
@param mark is the first value
@return true is someone won and false if no one won
*/
bool Board::checkDiagonal(char mark)
{
	//checks the first diagonal
	if (matrix[0][0] == mark && matrix[1][1] == mark && matrix[2][2] == mark)
	{
		return true;
	}

	//checks the second diagonal
	if (matrix[2][0] == mark && matrix[1][1] == mark && matrix[0][2] == mark)
	{
		return true;
	}
	return false;
}
