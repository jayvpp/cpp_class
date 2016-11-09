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
	CharStack aStack(5);

	// Testing that stack isEmpty
	cout << "Stack is "; 
	aStack.display();

	// Testing push to stack
	aStack.push('a');
	aStack.push('b');
	aStack.push('c');
	aStack.push('d');
	aStack.push('e');
	aStack.display();

	// Test if stack is full
	cout << endl;
	aStack.push('f');
	
	// Testing pop of stack
	printf("\nPop = %c\n", aStack.pop());

	// Testing peek of stack
	printf("Peek = %c\n", aStack.peek());

	system("pause");
}