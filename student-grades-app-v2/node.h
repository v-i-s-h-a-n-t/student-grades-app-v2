#pragma once

#include <iostream>

template<typename T> class Node {
private:
	Node<T>* next;
	Node<T>* prev;
	T* data;

public:
	Node();
	Node(T* data);
	~Node();
	
	void setNext(Node<T>* next);
	Node<T>* getNext();

	void setPrev(Node<T>* prev);
	Node<T>* getPrev();

	void setData(T* data);
	T* getData();
};

