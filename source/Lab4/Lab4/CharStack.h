#pragma once
#include<iostream>

using namespace std;

class CharStack
{
	class StackFullException: public std::exception {}; // exception handling for full stack
	class StackPeekEmptyException : public std::exception { }; // exception handling for emtpy stack
	class StackPopEmptyException : public std::exception { }; // exception handling for emtpy stack

private:
	size_t stackSize = 0; // size of the stack
	int top = -1; // index of the top element in the stack
	char *theStack = nullptr;

public:
	//CharStack() {} // We would have to pass the size in with a default constructor
	CharStack(size_t size) {
		stackSize = size;
		theStack = new char[size]; // initialize to the size
		top = -1;// top is at the bottom
	}
	//~CharStack() {} 
	bool isEmpty() 
	{
		return top == -1;
	}
	
	bool isFull() 
	{
		return top == (stackSize - 1);
	}

	void push(int ele) 
	{
		if (!isFull())
		{
			top++;
			theStack[top] = ele;
		}
		else
			throw StackFullException();
			//cout << "No more push it is full" << endl;
	}

	int pop() 
	{
		if (!isEmpty()) {

			return theStack[top--];
		}
		else
			throw StackPopEmptyException();
			//cout << "No more pop, it is empty" << endl;
	}

	int peek() 
	{
		if (!isEmpty())
		{
			return theStack[top];
		}
		else
			throw StackPeekEmptyException();
			//cout << "No more peek, it is empty" << endl;
	}
	
	void display() 
	{
		if (isEmpty())
			cout << "Empty" << endl;
		else 
		{
			for (int i = top; i >= 0; i--)
				cout << theStack[i] << endl;
		}
	}
};

