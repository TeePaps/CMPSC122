// Node.h - Node defintition
// Written by Yu-San Lin

#pragma once
#include<string>
using namespace std;

struct Node
{
	// Data fields
	string data;
	Node* next;

	// Constructor
	Node(const string& data_item, Node* next_ptr = NULL)
	{
		data = data_item;
		next = next_ptr;
	}
};