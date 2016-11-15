#include "GameManager.h"

void GameManager::InitializePlayers()
{
	std::string name;
	std::cout << "Enter Player 1 Name: ";
	std::cin >> name;
	player1 = std::make_unique<Player>(Player(name, X));
	std::cout << "Enter Player 2 Name: ";
	std::cin >> name;
	player2 = std::make_unique<Player>(Player(name, O));
}
void GameManager::InitializeTicTacToe()
{
	tictactoe = std::make_unique<TicTacToe>(TicTacToe(*player1.get(), *player2.get()));
}

void GameManager::PlayingCicle()
{
	tictactoe->DisplayBoard();
	auto player = tictactoe->GetCurrentPlayer();

	do
	{
		try
		{
			int nextposition = player.NextPositionToPlay(*tictactoe.get());
			tictactoe->ChoosePosition(nextposition);
			break;
		}
		catch (std::exception e) { std::cout << "Occupied Position, try again..." << std::endl; }
	} while (true);
}

void GameManager::DisplayMenuAndSelectOption()
{
	int option = 0;
	std::cout << "1) Start a new match(two new players)." << std::endl;
	std::cout << "2) Continue the current match(the same two players." << std::endl;
	std::cout << "3) Exit" << std::endl;
	std::cout << "Enter the number that correspont to the option you want to go: ";
	std::cin >> option;
	
	switch (option)
	{
	case 1:
		ResetMatch();
		break;
	case 2:
		ResetGame();
		break;
	default:
		exit(0);
		break;
	}
}
void GameManager::DisplayBasicPlayerInformation()
{
	std::cout << "Player 1 Name " << player1->name << " is using X symbol" << std::endl;
	std::cout << "Player 2 Name " << player2->name << " is using O symbol" <<std::endl;

	std::cout << "Game Started: " << player1->name << " vs " << player2->name << std::endl;
}

GameManager::GameManager()
{
	InitializePlayers();
	InitializeTicTacToe();
}

void GameManager::Run()
{
	do
	{
		DisplayBasicPlayerInformation();

		while (tictactoe->CheckForWinner() == InProgress)
			PlayingCicle();
		
		tictactoe->DisplayScore();
		
		DisplayMenuAndSelectOption();
	}
	while (true);
}

void GameManager::ResetMatch()
{
	InitializePlayers();
	InitializeTicTacToe();
}

void GameManager::ResetGame()
{
	tictactoe->ResetGame();
}
 