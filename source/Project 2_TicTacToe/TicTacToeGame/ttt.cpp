#include "ttt.h"
#include <iostream>
bool TicTacToe::CheckRow(int row)    { return (board[row][0] != Empty && board[row][0] == board[row][1] && board[row][1] == board[row][2]); }
bool TicTacToe::CheckCol(int col)    { return (board[0][col] != Empty && board[0][col] == board[1][col] && board[1][col] == board[2][col]); }
bool TicTacToe::CheckDiagonalLeft()  { return (board[0][0]   != Empty && board[0][0]   == board[1][1]   && board[1][1]   == board[2][2]); }
bool TicTacToe::CheckDiagonalRight() { return (board[0][2]   != Empty && board[0][2]   == board[1][1]   && board[1][1]   == board[2][0]); }

void TicTacToe::SwitchCurrentPlayer()
{
	if (currentPlayer == player1)currentPlayer = player2;
	else currentPlayer = player1;
}

std::shared_ptr<Player> TicTacToe::FindPlayerBySymbol(Symbol s)
{
	if (s == Symbol::Empty) throw;
	if (player1->symbol == s) return player1;
	else return player2;
}

TicTacToe::TicTacToe(const Player& p1, const Player& p2)
{
	player1 = std::make_shared<Player>(p1);
	player2 = std::make_shared<Player>(p2);
	currentPlayer = player1;
	gameState = WinnerStatus::InProgress;
	numberOfPlays = 0;

	for (size_t i = 0; i < 3; i++)
		for (size_t j = 0; j < 3; j++)
			board[i][j] = Symbol::Empty;
}

WinnerStatus TicTacToe::FindWinnerByPosition(int f,int c)
{
	std::shared_ptr<Player> player = FindPlayerBySymbol(board[f][c]);
	if (player == player1) return Player1;
	else return Player2;
}

WinnerStatus TicTacToe::CheckForWinner()
{
	for (size_t i = 0; i < 3; i++)
	{
		if (CheckRow(i))	      return FindWinnerByPosition(i, 0);
		if (CheckCol(i))	      return FindWinnerByPosition(0, i);
		if (CheckDiagonalLeft())  return FindWinnerByPosition(0, 0);
		if (CheckDiagonalRight()) return FindWinnerByPosition(0, 2);
	}
	if (numberOfPlays == 9)       return WinnerStatus::Tie;
	return WinnerStatus::InProgress;
}

void TicTacToe::ChoosePosition(int position)
{
	//check exeption
	TryToPlayAtPosition(position);
	AnalyseGameStateAfterPlay();
}

void TicTacToe::AnalyseGameStateAfterPlay()
{
	if (IsGameTie()) return;
	if (IsGameCompletedAndThereIsAWinner()) return;
	SwitchCurrentPlayer();
}
void TicTacToe::TryToPlayAtPosition(int position)
{
	if (position < 0 || position > 9) throw OutsideOfBoardPosition();
	int f = (position - 1) / 3;
	int c = (position - 1) % 3;
	if (board[f][c] != Symbol::Empty) throw OccupiedPosition();
	board[f][c] = currentPlayer->symbol;
	numberOfPlays++;
	gameState = CheckForWinner();
}

bool TicTacToe::IsGameTie()
{
	if (gameState == WinnerStatus::Tie) 
	{
		GameTie();
		return true;
	}
	return false;
}

bool TicTacToe::IsGameCompletedAndThereIsAWinner()
{
	if (gameState == WinnerStatus::Player1 || gameState == Player2)
	{
		currentPlayer->WonTheGame();
		return true;
	}
	return false;
}

bool TicTacToe::IsWinner()
{
	return (gameState == WinnerStatus::Player1 || gameState == WinnerStatus::Player2);
}

void TicTacToe::DisplayBoard()
{
	std::string board_string[3] = { "X" , "O" ,"E" };
	for (size_t i = 0; i < 3; i++)
	{
		for (size_t j = 0; j < 3; j++)
			std::cout << board_string[board[i][j]] << " ";
		std::cout << std::endl;
	}
}

void TicTacToe::GameEnd()
{
	currentPlayer->WonTheGame();

}
void TicTacToe::GameTie()
{
	std::cout << "TIE :)" << std::endl;
}
