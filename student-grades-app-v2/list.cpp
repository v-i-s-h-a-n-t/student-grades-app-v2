#include <iostream>

#include "list.h"

using namespace std;

template<typename T> List<T>::List() {
	head = NULL;
	tail = NULL;
	size = 0;
	cout << "Created List" << endl;
}

template<typename T> List<T>::~List() {
	for(int i = 0; i < size; i++) {
		removeNode(0);
	}

	cout << "Deleted List" << endl;
}

template<typename T> Node<T>* List<T>::getNode(int nodeIndex) {
	Node<T>* node = head;

	for (int i = 0; i < nodeIndex; i++) {
		node = node->getNext();
	 }

	return node;
}

template<typename T> void List<T>::appendNode(Node<T>* node) {
	if (head == NULL) {      
			head = node;         
	}

	else {
		tail->setNext(node);
		node->setPrev(tail);
	}

	tail = node;
	size++;
}

template<typename T> void List<T>::removeNode(int i) {
	Node<T>* nodeToRemove = getNode(i);

	if (nodeToRemove->getPrev() == NULL) {
		head = nodeToRemove->getNext();
	}

	else {
		nodeToRemove->getPrev()->setNext(nodeToRemove->getNext());
	}

	if (nodeToRemove->getNext() == NULL) {
		tail = nodeToRemove->getPrev();
	}

	else {
		nodeToRemove->getNext()->setPrev(nodeToRemove->getPrev());
	}

	delete nodeToRemove;
	nodeToRemove = NULL;
	size--;
}

template<typename T>  void List<T>::setSize(int size) {
	this->size = size;
}

template<typename T> int List<T>::getSize() {
	return size;
}

template<typename T> bool List<T>::isEmpty() {
	return head == NULL;
}

// explicit instantiation declaration for Student class 
// (required since List classes is broken into .h and .cpp files)
template class List<Student>;
