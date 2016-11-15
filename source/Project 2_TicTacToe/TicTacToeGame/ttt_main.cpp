#include "ttt.h"
#include <iostream>
using namespace std;

void main()
{
	Player p1("jason");
	Player p2("yilena");

	p1.symbol = Symbol::X;
	p2.symbol = Symbol::O;


	TicTacToe ttt(p1, p2);
	/*ttt.ChoosePosition(1);
	ttt.ChoosePosition(2);
	ttt.ChoosePosition(3);
	ttt.ChoosePosition(5);
	ttt.ChoosePosition(4);
	ttt.ChoosePosition(8);*/

	ttt.ChoosePosition(1);
	ttt.ChoosePosition(2);
	ttt.ChoosePosition(3);
	ttt.ChoosePosition(4);
	ttt.ChoosePosition(5);
	ttt.ChoosePosition(7);
	ttt.ChoosePosition(9);

	//tie
	//ttt.ChoosePosition(1);
	//ttt.ChoosePosition(2);
	//ttt.ChoosePosition(5);
	//ttt.ChoosePosition(9);
	//ttt.ChoosePosition(6);
	//ttt.ChoosePosition(4);
	//ttt.ChoosePosition(7);
	//ttt.ChoosePosition(3);
	//ttt.ChoosePosition(8);

	ttt.DisplayBoard();
	std::cout << ttt.CheckForWinner() << std::endl;
}