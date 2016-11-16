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

void TicTacToe::UpdateMatchInformation()
{
	match.IncrementRoundsPlayed();
	if (gameState == Tie)
		match.IncrementTieGames();
	else
		currentPlayer->current_score++;
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
	gameState = GameStatus::InProgress;
	numberOfPlays = 0;
	CleanBoard();
}

GameStatus TicTacToe::FindWinnerByPosition(int f,int c)
{
	std::shared_ptr<Player> player = FindPlayerBySymbol(board[f][c]);
	if (player == player1) return Player1;
	else return Player2;
}

GameStatus TicTacToe::CheckForWinner()
{
	for (size_t i = 0; i < 3; i++)
	{
		if (CheckRow(i))	      return FindWinnerByPosition(i, 0);
		if (CheckCol(i))	      return FindWinnerByPosition(0, i);
		if (CheckDiagonalLeft())  return FindWinnerByPosition(0, 0);
		if (CheckDiagonalRight()) return FindWinnerByPosition(0, 2);
	}
	if (numberOfPlays == 9)       return GameStatus::Tie;
	return GameStatus::InProgress;
}

void TicTacToe::ChoosePosition(int position)
{
	try 
	{
		TryToPlayAtPosition(position);
	}
	catch (OccupiedPosition e)
	{
		throw e;
	}
	AnalyseGameStateAfterPlay();
}



void TicTacToe::ResetGame()
{
	CleanBoard();
}

void TicTacToe::CleanBoard()
{
	numberOfPlays = 0;
	for (size_t i = 0; i < 3; i++)
		for (size_t j = 0; j < 3; j++)
			board[i][j] = Symbol::Empty;
}

void TicTacToe::AnalyseGameStateAfterPlay()
{
	if (gameState != InProgress)
	{
		GameCompleted();
		return;
	}
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

bool TicTacToe::IsWinner()
{
	return (gameState == GameStatus::Player1 || gameState == GameStatus::Player2);
}

void TicTacToe::DisplayScore()
{
	std::cout << std::endl;

	std::cout << "Player 1 Wins		Player 2 Winds		Tie Games		TotalNumberOfGames" << std::endl;
	std::cout << "-------------------------------------------------------------------------------------------" << std::endl;
	std::cout << player1->current_score << "\t\t\t" << player2->current_score << "\t\t\t" << match.GetAmountOfTieGames() << "\t\t\t" << match.GetAmountOfRoundsPlayed() << std::endl;
	
	std::cout << std::endl;
}

void TicTacToe::DisplayBoard()
{
	std::string board_string[3] = { "X" , "O" ,"?" };
	std::cout << std::endl;
	std::cout << "Current State of the Game" << std::endl;
	for (size_t i = 0; i < 3; i++)
	{
		for (size_t j = 0; j < 3; j++)
		{
			std::cout <<"|" <<board_string[board[i][j]];
		}
		std::cout << "|\n-------" << std::endl;
	}	
	std::cout << std::endl;
}

const Player & TicTacToe::GetCurrentPlayer()const
{
	return *currentPlayer.get();
}

void TicTacToe::GameCompleted()
{
	std::cout <<"-------------------------------------------------------------------------------------------" << std::endl;
	if (gameState == Tie)
		std::cout << "IMPORTANT: TIE" << std::endl;
	else
		std::cout << "IMPORTANT: Player " << currentPlayer->name << " Won the game." << std::endl;
	DisplayBoard();
	UpdateMatchInformation();
}
 
