// MyCharStack.cpp : Defines the entry point for the console application.
//
// Created by
// Yep, Eben 	      : yepea4@bconline.broward.edu
// Vega, Jason	      : vegaj32@mail.broward.edu
// Dominguez, Michael : domim35@bconline.broward.edu
// 
// COP 2335C - Carlos Lollett-Hernandez
// Lab 4 -Character Stack
// File names : charStack.h, charStackMain.cpp
// a) (20 points)
// Modify the integer stack that we designed in class so that it works for a
// stack of characters.Rename the class CharStack.
// b) (5 points)
// Once your class is defined, write a small test program(in a separate file)
// to thoroughly test all of the member functions of your stack.

#include "stdafx.h"
#include "CharStack.h"

int main()
{
	CharStack aStack(8);

	// Testing member functions of Stack
	aStack.display();
	aStack.push(12);
	aStack.push(24);
	aStack.display();

	system("pause");
}