#pragma once
#include <string>
#include <memory>
#include <iostream>
#include <vector>
#include <iostream>
#include "TicTacToeBoard.h"


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

class TicTacToeBoard
{
public:
	Symbol board[3][3];
	bool CheckRow(int row);
	bool CheckCol(int col);
	bool CheckDiagonalLeft();
	bool CheckDiagonalRight();
	void CleanBoard();
	bool PlayAtPosition(int position, Symbol s);
	int numberOfPlays;
	TicTacToeBoard()
	{
		numberOfPlays = 0;
		for (size_t i = 0; i < 3; i++)
			for (size_t j = 0; j < 3; j++)
				board[i][j] = Empty;
	}
	TicTacToeBoard(const TicTacToeBoard& tttb)
	{
		for (size_t i = 0; i < 3; i++)
			for (size_t j = 0; j < 3; j++)
				board[i][j] = tttb.board[i][j];
	}
};

struct IAPlayer : public Player
{
 
	class TreeOfTTT
	{
	public:
	    TicTacToeBoard root;
		std::vector<TreeOfTTT*> nodes;
		GameStatus gamestatus;

		TreeOfTTT(TicTacToeBoard root, GameStatus ge)
		{
			this->root = root;
			this->gamestatus = ge;
		}
		TreeOfTTT() {};
	};

	TreeOfTTT ttt_tree;

	int NextPositionToPlay(const TicTacToe& tictactoe)
	{
		int position = 0;
		std::cout << name << " Turn: Enter position: ";
		std::cin >> position;
		return position;
	}

	void GenerateTicTacToeTree(TreeOfTTT current_ttt, Symbol current_symbol)
	{
		TicTacToeBoard root = current_ttt.root;
		for (size_t i = 1; i < 9; i++)
		{
			if (root.PlayAtPosition(i, current_symbol))
			{
				TicTacToeBoard* nttt = new TicTacToeBoard(current_ttt.root);
		
				TreeOfTTT* tree_ttt = new TreeOfTTT(*nttt, InProgress);
				current_ttt.nodes.push_back(tree_ttt);
				//GenerateTicTacToeTree(current_ttt, static_cast<Symbol>((current_symbol + 1) % 2));
			}
		}
	}
	IAPlayer(std::string name, Symbol symbol):Player(name,symbol)
	{
		TicTacToeBoard empty;
		TreeOfTTT ttt_tree(empty, InProgress);
		GenerateTicTacToeTree(ttt_tree, symbol);
	}
};


class TicTacToe : private TicTacToeBoard
{
private:
	std::shared_ptr<Player> player1;
	std::shared_ptr<Player> player2;
	std::shared_ptr<Player> currentPlayer;

	Match match;
	GameStatus gameState;
	bool IsWinner();
	void GameCompleted();

	void AnalyseGameStateAfterPlay();

	void TryToPlayAtPosition(int position);
	void SwitchCurrentPlayer();
	void UpdateMatchInformation();

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


