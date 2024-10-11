#pragma once

#include <iostream>

#include "student.h"

template<typename T> class Node {
private:
	Node<T>* next;
	Node<T>* prev;
	T* data;

public:
	Node();
	Node(T* data);
	~Node();
	
	void setNext(Node<T>* node);
	Node<T>* getNext();

	void setPrev(Node<T>* node);
	Node<T>* getPrev();

	void setData(T* data);
	T* getData();
};

