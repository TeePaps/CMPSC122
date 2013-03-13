// Main.cpp -
// Written by Ted Papaioannou

#include <iostream>
#include <stack>
#include <string>

using namespace std;

void match (char bracket, stack<char>& myStack)
{
	if ( myStack.top() == bracket )
		myStack.pop();
}

void main ()
{
	// Equation newEquation = Equation();
	stack<char> myStack;
	string equation;

	cout << "Enter an equation to check if it is balanced: ";

	getline(cin, equation);

	for ( int i = 0; i < equation.length(); i++ )
	{
		switch ( equation[i] )
		{
		case '(': myStack.push(equation[i]);
			break;
		case '[': myStack.push(equation[i]);
			break;
		case '{': myStack.push(equation[i]);
			break;
		case ')': match('(', myStack);
			break;
		case ']': match('[', myStack);
			break;
		case '}': match('{', myStack);
			break;
		}
	}

	if ( myStack.size() == 0 )
		cout << "That equation is balanced" << endl << endl;
	else
		cout << "That is an unbalanced equation" << endl << endl;

	system ("pause");
}
