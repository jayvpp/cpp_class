#pragma once
#include <string>

enum Symbol
{
	X,
	O,
	Empty
};



struct Player
{
	std::string name;
	Symbol symbol;
	int current_score;
};

struct Position
{
	int x;
	int y;
};

class TicTacToe
{
private:
	const size_t size = 3;
	Player player1;
	Player player2;
	int currentWinner;
	Symbol board[3][3];
	bool CheckRow(int row);
	bool CheckCol(int col);
	bool CheckDiagonalLeft();
	bool CheckDiagonalRight();
public:

	TicTacToe(Player player1, Player player2);
	Player CheckForWinner();
	void ChoosePosition(Position position);
	void ResetMatch();
	void ResetGame();
	void DisplayScore();
	void DisplayBoard();
};