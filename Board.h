#ifndef _Board_
#define _Board_
class Board
{
public:
	void displayBoard();//displays empty board
	void manipulateBoard(int row, int column, char mark);//modifies matrix
	bool checkRow(char mark);//checks if there is three in a row,
	bool checkColumn(char mark);//checks if there is three in a column
	bool checkDiagonal(char mark);//checks if there is three diagonal 
	void clearBoard();//clears the board

private:
	char matrix[3][3] = { ' ', ' ', ' ',' ',' ',' ',' ',' ',' ' };//creates an empty matrix
	char mark;
};

#endif