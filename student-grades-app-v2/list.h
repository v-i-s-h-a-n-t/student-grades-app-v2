#pragma once

#include <iostream>

#include "node.h"

template<typename T> class List {
private:
	Node<T>* head;
	Node<T>* tail;
	int size;

public:
	List();
	~List();

	Node<T>* getNode(int nodeIndex);

	void appendNode(Node<T>* node);
	void removeNode(int i);

	void setSize(int size);
	int getSize();

	bool isEmpty();
};