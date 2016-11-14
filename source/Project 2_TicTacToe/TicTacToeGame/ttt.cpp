#include "ttt.h"

bool TicTacToe::CheckRow(int row)
{
	return (board[row][0] == board[row][1] == board[row][2]);
}

bool TicTacToe::CheckCol(int col)
{
	return (board[0][col] == board[1][col] == board[2][col]);
}

bool TicTacToe::CheckDiagonalLeft()
{
	return (board[0][0] = board[1][1] = board[2][2]);
}

bool TicTacToe::CheckDiagonalRight()
{
	return (board[0][2] = board[1][1] = board[2][0]);
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

Player TicTacToe::CheckForWinner()
{
	
}
