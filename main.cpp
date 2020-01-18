/*
Setareh Khoylow
Section 1A
ID: 30511410

I, Setareh Khoylow, declare that this work is my own. I did this work honetly 
and can fully stand behind everything I have written. I did not copy code from
anyone, student or otherwise.
I colaborated with Francisco Borja and I affirm that we all contributed equally
in the code.
*/

#include <iostream>
#include <string>
#include "Player.h"
#include "Board.h"

int main()
{
	std::cout << "This is a Tic Tac Toe game!\n";

	std::cout << "How many rounds would you like to play?";
	int rounds;
	std::cin >> rounds;
	std::cin.ignore();

	std::cout << "Please enter the name of player 1: ";
	std::string name1;
	getline(std::cin, name1);
	Player player1 (name1, 0);

	std::cout << "Thanks. Please enter the name of player 2: ";
	std::string name2;
	getline(std::cin, name2);
	Player player2 (name2, 0);

	std::cout << "Let the game begin!\n";

	Board game;

	int roundNum = 1;//the round number starts at 1 in the beginning of ever game
	
	int player1_turns = 0;//this keeps track of how many pieces player 1 puts down to decide who goes first in the next round
	int player2_turns = 0;//this keeps track of how many pieces player 2 puts down to decide who goes first in the next round

	//this for loop is to keep track of how many pieces are on the board for every round
	for (int i = 1; i <= 9; i++)
	{
		game.displayBoard();//this displays the board before the players make a move
		if (i % 2 == 0)//if i is even then its player 2's turn
		{
			do//this do-while loop is to check if player 1 placed the last piece or not and based on that it will either execute the code inside or not
			{
				player2_turns++;//this increases the amount of times player 2 has put a piece down
				char mark = 'o';//this is player 2's mark
				std:: cout << "It is " << player2.get_name() << "'s turn.\n";
				std::cout << "Where would you like to play? Enter your row position and column position: ";
				int row, column;
				std::cin >> row >> column;
				game.manipulateBoard(row, column, mark);//this will manipulate the board according to which row and column the player places their piece

				//this if statement checks if player 2 won or not and if they did then it will execute the code inside
				if (game.checkRow(mark) == true || game.checkColumn(mark) == true || game.checkDiagonal(mark) == true)
				{
					game.displayBoard();//this displays the current condition of the game board
					std::cout << player2.get_name() << " won the round!\n";
					player2.set_score();//this increases the players score by 1
					std::cout << "Presently " << player1.get_name() << " has " << player1.get_score() << " points and " << player2.get_name() << " has " << player2.get_score() << " points.\n";
					roundNum++;//increases the rounds played because someone won so it goes to the next round

					//this checks to make sure that the rounds played aren't more than the rounds entered by the user at the beginning. If it isn't than it clears the board
					if (roundNum <= rounds)
					{
						game.clearBoard();
					}
					i = 1;//this is to reset the amount of pieces placed
					break;//this is to exit the loop
				}
			} while (player2_turns < player1_turns);
		}
		else//if i is not even than its player 1's turn
		{
			do//this do-while loop is to check if player 2 placed the last piece or not and based on that it will either execute the code inside or not
			{
				player1_turns++;//this increases the amount of times player 1 has put a piece down
				char mark = 'x';//this is player 1's mark
				std::cout << "It is " << player1.get_name() << "'s turn.\n";
				std::cout << "Where would you like to play? Enter your row position and column position: ";
				int row, column;
				std::cin >> row >> column;
				game.manipulateBoard(row, column, mark);//this will manipulate the board according to which row and column the player places their piece

				//this if statement checks if player 2 won or not and if they did then it will execute the code inside
				if (game.checkRow(mark) == true || game.checkColumn(mark) == true || game.checkDiagonal(mark) == true)
				{
					game.displayBoard();//this displays the current condition of the game board
					std::cout << player1.get_name() << " won the round!\n";
					player1.set_score();//this increases the players score by 1
					std::cout << "Presently " << player1.get_name() << " has " << player1.get_score() << " points and " << player2.get_name() << " has " << player2.get_score() << " points.\n";
					roundNum++;//increases the rounds played because someone won so it goes to the next round

					//this checks to make sure that the rounds played aren't more than the rounds entered by the user at the beginning. If it isn't than it clears the board
					if (roundNum <= rounds)
					{
						game.clearBoard();
					}
					i = 1;//this is to reset the amount of pieces placed
					break;//this is to exit the loop
				}
			} while (player1_turns < player2_turns);
		}
		if (i == 9)//this executes if the board is full and none of the players won
		{
			game.displayBoard();
			std::cout << "It's a draw!\n";
			roundNum++;//increases the rounds played because the board filled up

			//if the rounds played excedes the amount of rounds inputted in the beginning and if there are 9 pieces then it exits the loop
			if (roundNum > rounds && i >= 9)
			{
				break;
			}
			game.clearBoard();//this clears the board becuase they can still play another round since the if statement above wasn't true
			i = 1;//resets the number of pieces
		}
		else if(roundNum > rounds)//if the rounds played excedes the amount of rounds inputted in the beginning then it exits the loop
		{
			break;
		}
	}
	if (player1.get_score() == player2.get_score())//if both of the players final scores are equal then it outputs the code below
	{
		std::cout << player1.get_name() << "'s score was " << player1.get_score() << " and " << player2.get_name() << "'s score was " << player2.get_score() << ".\n";
		std::cout << "It is a draw!\n";
		std:: cout << "Game over!\n";
	}
	else if (player1.get_score() > player2.get_score())//if player 1 had more points than player 2 at the end of all the orunds then the code below is executed
	{
		std::cout << player1.get_name() << " won!\n";
		std::cout << "Game over!\n";
	}
	else//and if none of the others were true then if player 2 had more points than player 1 at the end of all the orunds then the code below is executed
	{
		std::cout << player2.get_name() << " won!\n";
		std::cout << "Game over!\n";
	}

	std::cin.get();

	return 0;
}