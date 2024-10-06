#include <iostream>

#include "node.h"

using namespace std;

Node::Node() {
	next = NULL;
	prev = NULL;
	student = NULL;

	cout << "Node default constructor" << endl;
}

Node::~Node() {
	delete next;
	delete prev;
	delete student;
}

void Node:: setNext(Node* node) {
	next = node;
}

Node* Node::getNext() {
	return next;
}

void Node::setPrev(Node* node) {
	prev = node;
}

Node* Node::getPrev() {
	return prev;
}

void Node::setStudent(Student* student) {
	this->student = student;
}

Student* Node::getStudent() {
	return student;
}