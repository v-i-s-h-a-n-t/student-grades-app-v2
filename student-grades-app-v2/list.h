#pragma once

#include <iostream>

#include "node.h"

class List
{
private:
	Node* head;
	Node* tail;
	int size;

public:
	List();
	~List();

	Node* getNode(int nodeIndex);

	void appendNode(Node* node);
	void removeNode(int i);

	void setSize(int size);
	int getSize();

	void printList();
	bool isEmpty();
	void operator++(int);
};