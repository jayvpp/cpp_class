
#include "TicTacToeBoard.h"
#include "ttt.h"


bool TicTacToeBoard::CheckRow(int row) { return (board[row][0] != Empty && board[row][0] == board[row][1] && board[row][1] == board[row][2]); }
bool TicTacToeBoard::CheckCol(int col) { return (board[0][col] != Empty && board[0][col] == board[1][col] && board[1][col] == board[2][col]); }
bool TicTacToeBoard::CheckDiagonalLeft() { return (board[0][0] != Empty && board[0][0] == board[1][1] && board[1][1] == board[2][2]); }
bool TicTacToeBoard::CheckDiagonalRight() { return (board[0][2] != Empty && board[0][2] == board[1][1] && board[1][1] == board[2][0]); }
void TicTacToeBoard::CleanBoard()
{
	numberOfPlays = 0;
	for (size_t i = 0; i < 3; i++)
		for (size_t j = 0; j < 3; j++)
			board[i][j] = Symbol::Empty;
}

bool TicTacToeBoard::PlayAtPosition(int position, Symbol s)
{
	if (position < 0 || position > 9) return false;
	int f = (position - 1) / 3;
	int c = (position - 1) % 3;
	if (board[f][c] == Symbol::Empty) 
	{
		board[f][c] = s;
		return true;
	}
	return false;
}
