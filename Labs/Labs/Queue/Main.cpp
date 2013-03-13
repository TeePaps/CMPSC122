// Main.cpp - Queue
// Written by Ted Papaioannou

#include <iostream>
#include <string>
#include <queue>

using namespace std;


struct OperationPriority
{
	OperationPriority(char operation, int priority)
	{
		Operation = operation;
		Priority = priority;
	}

	char Operation;
	int Priority;
};


void main ()
{
	string expression;
	queue<OperationPriority> myQueue;
	int nestingLevel = 0;

	cout << "Enter an algebraic expression to check the priority: ";
	getline(cin, expression);

	for ( int i = 0; i < expression.length(); i++ )
	{
		char operation;
		char priority;
		operation = expression[i];
		
		switch ( operation )
		{
		case '(' :
			nestingLevel++;
			break;
		case ')' : 
			nestingLevel--;
			break;
		case '+' : 
		case '-' :
			priority = nestingLevel*2+1;
			myQueue.push(OperationPriority(operation, priority));
			break;
		case '*' :
		case '/' :
			priority = nestingLevel*2+1;
			myQueue.push(OperationPriority(operation, priority));
			break;
		}
	}

	int length = myQueue.size();
	for ( int i = 0; i < length; i++ )
	{
		cout << "(" << myQueue.front().Operation << ", "
			<< myQueue.front().Priority << ") " << endl;
		myQueue.pop();
	}

	system ("pause");
}