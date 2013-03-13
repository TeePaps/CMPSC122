// main.cpp - Node class test program
// Wrtitten by Yu-san Lin

#include <iostream>
#include "Node.h"
#include <string>
using namespace std;

void main ()
{
	// way 1
	Node* a = new Node("A");
	Node* b = new Node("B");
	Node* c = new Node("C");
	Node* d = new Node("D");

	a->next = b;
	b->next = c;
	c->next = d;
	

	// way 2
	/*
	Node* head = new Node("A");
	head->next = new Node("B");
	head->next->next = new Node("C");
	head->next->next->next = newNode("D");
	*/

	// way 3
	/*
	Node* head = new Node("D");
	head = new Node("C", head);
	head = new Node("B", head);
	head = new Node("A", head);
	*/

	// Insert
	Node* e = new Node("E");
	e->next = a->next;

	// Remove
	b->next = c->next;
	delete c;

	Node* node_ptr = a;
	while(node_ptr != NULL)
	{
		cout << node_ptr->data;
		if (node_ptr->next != NULL)
			cout << "==>";
		node_ptr = node_ptr->next;
	}
	cout << endl;

	system("pause");
}