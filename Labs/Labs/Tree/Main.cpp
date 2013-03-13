// Main.cpp - Written by Ted Papaioannou	

#include <iostream>
#include <string>
#include "TreeNode.h"

using namespace std;
// 6/4+1+4*3-9 = -21.5

/*
For simplicity assume single-digit operands, no parenthesis and well-formed expression e.g.:1+5*3-4/2
Set treeRoot = NULL;
Set currentNode = treeRoot;
For each character in the expression
If you find characters ‘0’..’9’ then
Create newLeaf node (using new operator), set its value to ‘0’..’9’
If the currentNode == NULL then  treeRoot = currentNode = newLeaf;else  currentNode->Right = newLeaf;
If you find ‘+’ or ‘-’ (or ‘*’ or ’/’ and currentNode->Right == NULL) then
Create newRoot node, set its value the operation found
Set newRoot->Left = treeRoot;
Set treeRoot = newRoot;
Set currentNode = newRoot;
If you find ‘*’ or ‘/’ then
Create newChild node, set its value value the operation found
Set newChild->Left = currentNode->Right;
Set currentNode ->Right = newChild;
Set currentNode = newChild;


// Base case: choose isLeaf or is NULL
If treeNode is null then
   return
Else
   // Recursion
   for each childNode
      // Recursively traverse child node’s sub-tree
      traverse childNode
   end for
End if
*/
void main()
{
	char nextChar;

	string expression = "6/4+1+4*3-9";

	TreeNode<char>* treeRoot = NULL;
	TreeNode<char>* currentNode = treeRoot;

	//currentNode = treeRoot;
	for ( int i = 0; i < expression.length() ; i++ )
	{
		nextChar = expression[i];
		if ( nextChar >= '0' && nextChar <= '9' )
		{
			TreeNode<char>* newLeaf = new TreeNode<char>(nextChar);
			if ( currentNode == NULL )
			{
				treeRoot = currentNode;
				currentNode = newLeaf;
			}
			else
				currentNode->Right = newLeaf;
		}
		else if ( nextChar == '+' || nextChar == '-' )
		{
			TreeNode<char>* newRoot = new TreeNode<char>(nextChar);
			newRoot->Left = treeRoot;
			treeRoot = newRoot;
			currentNode = newRoot;
		}
		else if ( nextChar == '*' || nextChar == '-' )
		{
			TreeNode<char>* newChild = new TreeNode<char>(nextChar);
			newChild->Left = currentNode->Right;
			currentNode->Right = newChild;
			currentNode = newChild;
		}
	}
	system("pause");
}