#pragma once
#include <string>
#include <memory>
#include <iostream>
#include <vector>

enum Symbol { X, O, Empty };
enum GameStatus { Player1, Player2, InProgress, Tie };

class Match
{
private:
	int AmountOfTieGames;
	int AmountOfRoundsPlayed;
public:
	Match() :  AmountOfTieGames(0), AmountOfRoundsPlayed(0) {};

	void IncrementTieGames() { AmountOfTieGames++; }
	void IncrementRoundsPlayed() { AmountOfRoundsPlayed++; }

	void Reset()
	{
		AmountOfTieGames = 0;
		AmountOfRoundsPlayed = 0;
	}
	int GetAmountOfTieGames() const { return AmountOfTieGames; }
    int GetAmountOfRoundsPlayed() const { return AmountOfRoundsPlayed; }

};

class TicTacToe;
struct Player
{
	std::string name;
	Symbol symbol;
	int current_score;

	Player(std::string name, Symbol symbol)
	{
		this->name = name;
		this->symbol = symbol;
		current_score = 0;
	}

	Player(const Player& player)
	{
		name = player.name;
		current_score = player.current_score;
		symbol = player.symbol;
	}

	int NextPositionToPlay(const TicTacToe& tictactoe)
	{
		int position = 0;
		std::cout << name << " Turn: Enter position: ";
		std::cin >> position;
		return position;
	}

	bool operator ==(Player player)
	{
		return (name == player.name);
	}
};

class TicTacToe
{
private:
	std::shared_ptr<Player> player1;
	std::shared_ptr<Player> player2;
	std::shared_ptr<Player> currentPlayer;
	Symbol board[3][3];
	Match match;
	GameStatus gameState;
	int numberOfPlays;

	bool CheckRow(int row);
	bool CheckCol(int col);
	bool CheckDiagonalLeft();
	bool CheckDiagonalRight();

	bool IsWinner();
	void GameCompleted();

	void AnalyseGameStateAfterPlay();

	void TryToPlayAtPosition(int position);
	void SwitchCurrentPlayer();
	void UpdateMatchInformation();
	void CleanBoard();

	std::shared_ptr<Player> FindPlayerBySymbol(Symbol s);
	GameStatus FindWinnerByPosition(int f, int c);

 
	class OccupiedPosition : public std::exception {};
	class OutsideOfBoardPosition : public std::exception {};

public:
	TicTacToe(const Player& player1, const Player& player2);
	GameStatus CheckForWinner();

	void ChoosePosition(int position);
	void ResetGame();
	void DisplayScore();
	void DisplayBoard();
	const Player& GetCurrentPlayer() const;
};


