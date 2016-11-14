#include "ttt.h"

bool TicTacToe::CheckRow(int row)
{
	return (board[row][0] == board[row][1] == board[row][2])
}

TicTacToe::TicTacToe(Player player1, Player player2)
{
	this->player1 = player1;
	this->player2 = player2;
	currentWinner = -1;
	for (size_t i = 0; i < size; i++)
		for (size_t j = 0; j < size; j++)
			board[i][j] = Symbol::Empty;
}

//Check for winner, if no winner return null
Player TicTacToe::CheckForWinner()
{
	for (size_t i = 0; i < size; i++)
	{
		for (size_t j = 0; j < size; j++)
		{
		
		}
	}
}
