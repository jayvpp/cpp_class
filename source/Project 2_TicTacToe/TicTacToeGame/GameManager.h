#pragma once
#include "ttt.h"
 
class GameManager
{
private:
	std::unique_ptr<TicTacToe> tictactoe;
	std::unique_ptr<Player> player1;
	std::unique_ptr<Player> player2;

	void InitializePlayers();
	void InitializeTicTacToe();
	void PlayingCicle();
	void DisplayMenuAndSelectOption();

	void DisplayBasicPlayerInformation();

public:
	GameManager();
	void Run();
	void ResetMatch();
	void ResetGame();
};