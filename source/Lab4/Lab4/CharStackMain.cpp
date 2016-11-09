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
#include <cassert>

using namespace std;

bool test_push();
bool test_pop();
bool test_peek();

int main()
{
	CharStack aStack(5);

	// Testing that stack isEmpty
	cout << "Push test passed: " << test_push() << endl;
	cout << "Pop test passed: " << test_pop() << endl;
	cout << "Peek test passed: " << test_peek() << endl;
	system("pause");
}

bool test_push() {
	CharStack aStack(400);

	aStack.push('a');
	aStack.push('b');
	aStack.push('c');
	aStack.push('d');

	try
	{
		aStack.push('e');
	}
	catch (std::exception& e)
	{
		cout << "Push Test passed, we cannot push anymore, exception called!" << endl;
		return true;
	}

	return false;
};

bool test_pop() {
	CharStack aStack(2);

	aStack.push('a');
	aStack.push('b');

	assert(aStack.pop() == 'b');
	assert(aStack.pop() == 'a');

	try
	{
		aStack.pop();
	}
	catch (std::exception& e)
	{
		cout << "Pop Test passed, we cannot pop anymore, exception called!" << endl;
		return true;
	}

	return false;
};

bool test_peek() {
	CharStack aStack(2);

	aStack.push('a');
	aStack.push('b');

	assert(aStack.peek() == 'b');
	assert(aStack.pop() == 'b');
	assert(aStack.peek() == 'a');

	try
	{
		aStack.peek();
	}
	catch (std::exception& e)
	{
		cout << "Pop Test passed, we cannot pop anymore, exception called!" << endl;
		return true;
	}

	return false;
}
