#pragma once
#include <string>
#include <memory>
#include <iostream>
enum Symbol
{
	X,
	O,
	Empty
};

enum WinnerStatus
{
	Player1,
	Player2,
	InProgress,
	Tie
};

struct Player
{
	std::string name;
	Symbol symbol;
	int current_score;

	Player(std::string name)
	{
		this->name = name;
		current_score = 0;
	}

	Player(const Player& player)
	{
		name = player.name;
		current_score = player.current_score;
		symbol = player.symbol;
	}

	//make this private , add this struct as friend
	void WonTheGame()
	{
		current_score++;
		std::cout << "Player " << name << " Won The Game." << std::endl;
		std::cout << "Player Score " << current_score << "pts." <<std::endl;
	}
	bool operator==(Player player)
	{
		return (name == player.name);
	}
};

class Match
{
private:
	int TotalGamesPlayed;
	int TotalGamesPlayer1Won;
	int TotalGamesPlayer2Won;
	Match() : TotalGamesPlayed(0), TotalGamesPlayer1Won(0), TotalGamesPlayer2Won(0) {}

};

class TicTacToe
{
private:
	std::shared_ptr<Player> player1;
	std::shared_ptr<Player> player2;
	std::shared_ptr<Player> currentPlayer;
	int numberOfPlays;
	
	Match Match;

	WinnerStatus gameState;
	Symbol board[3][3];
	bool CheckRow(int row);
	bool CheckCol(int col);
	bool CheckDiagonalLeft();
	bool CheckDiagonalRight();
	void SwitchCurrentPlayer();
	bool IsGameTie();
	bool IsGameStillInProgress();
	void TryToPlayAtPosition(int position);
	bool TicTacToe::Winner();
	std::shared_ptr<Player> FindPlayerBySymbol(Symbol s);
	WinnerStatus FindWinnerByPosition(int f, int c);
	class OccupiedPosition {};
	class OutsideOfBoardPosition{};

public:

	TicTacToe(const Player& player1, const Player& player2);

	WinnerStatus CheckForWinner();
	void ChoosePosition(int position);
	void ResetMatch();
	void ResetGame();
	void DisplayScore();
	void DisplayBoard();
	void GameEnd();
	void GameTie();
};