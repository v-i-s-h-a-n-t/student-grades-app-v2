#include <iostream>

#include "list.h"

using namespace std;

List::List() {
	head = NULL;
	tail = NULL;

	cout << "List default constructor" << endl;
}

List::~List() {
	for(int i = 0; i < size; i++) {
		removeNode(i);
	}
}

Node* List::getNode(Node* node, int i) {
	if (i == 0) {
		return node;
	}

	else {
		return getNode(node->getNext(), i - 1);
	}
}

void List::appendNode(Node* node) {
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

void List::removeNode(int i) {
	Node* nodeToRemove = getNode(head, i);

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

void List::setSize(int size) {
	this->size = size;
}

int List::getSize() {
	return size;
}

void List::printList() {
	Node* current = head;

	while (current != NULL) {
		cout << head->getStudent()->getId() << endl;
		current = current->getNext();
	}
}

bool List::isEmpty() {
	return head == NULL;
}
