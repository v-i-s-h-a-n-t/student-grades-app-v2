#include <iostream>

#include "list.h"
#include "student.h"

using namespace std;

template<typename T> List<T>::List() {
	head = NULL;
	tail = NULL;
	size = 0;

	cout << "Created List" << endl;
}

template<typename T> List<T>::~List() {
	while(head != NULL) {
		removeNode();
	}

	cout << "Deleted List" << endl;
}

template<typename T> Node<T>* List<T>::getNode(int index) {
	Node<T>* node = head;

	for (int i = 0; i < index; i++) {
		node = node->getNext();
	 }

	return node;
}

template<typename T> Node<T>* List<T>::getHead() {
	return head;
}	

template<typename T> void List<T>::appendNode(T* data) {
	Node<T>* node = new Node<T>(data);

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

template<typename T> void List<T>::removeNode() {
	Node<T>* nodeToRemove = head;

	if (nodeToRemove->getNext() == NULL) {
		head = NULL;
		tail = NULL;
	}

	else {
		head = nodeToRemove->getNext();
		head->setPrev(NULL);
	}

	delete nodeToRemove;
	nodeToRemove = NULL;
	size--;
}

//template<typename T> void List<T>::removeNode(int i) {
//	Node<T>* nodeToRemove = getNode(i);
//
//	if (nodeToRemove->getPrev() == NULL) {
//		head = nodeToRemove->getNext();
//	}
//
//	else {
//		nodeToRemove->getPrev()->setNext(nodeToRemove->getNext());
//	}
//
//	if (nodeToRemove->getNext() == NULL) {
//		tail = nodeToRemove->getPrev();
//	}
//
//	else {
//		nodeToRemove->getNext()->setPrev(nodeToRemove->getPrev());
//	}
//
//	delete nodeToRemove;
//	nodeToRemove = NULL;
//	size--;
//}

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
