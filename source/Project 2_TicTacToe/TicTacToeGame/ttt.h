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
	bool operator ==(Player player)
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
public:
	Match() : TotalGamesPlayed(0), TotalGamesPlayer1Won(0), TotalGamesPlayer2Won(0) {}
};

class TicTacToe
{
private:
	std::shared_ptr<Player> player1;
	std::shared_ptr<Player> player2;
	std::shared_ptr<Player> currentPlayer;
	Symbol board[3][3];
	Match match;
	WinnerStatus gameState;
	int numberOfPlays;

	bool CheckRow(int row);
	bool CheckCol(int col);
	bool CheckDiagonalLeft();
	bool CheckDiagonalRight();

	bool IsGameTie();
	bool IsGameCompletedAndThereIsAWinner();
	bool IsWinner();
	void GameEnd();
	void GameTie();

	void AnalyseGameStateAfterPlay();

	void TryToPlayAtPosition(int position);
	void SwitchCurrentPlayer();

	
	std::shared_ptr<Player> FindPlayerBySymbol(Symbol s);
	WinnerStatus FindWinnerByPosition(int f, int c);

	//Classes that represent exceptions
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

};