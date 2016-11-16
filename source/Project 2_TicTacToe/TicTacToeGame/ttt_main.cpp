#include "ttt.h"
#include "GameManager.h"
#include <iostream>
using namespace std;

void main()
{
	std::cout << "Tic Tac Toe Game" << std::endl;

	GameManager gm;
	gm.Run();
}