#include <iostream>

#include "node.h"

using namespace std;

Node::Node() {
	next = NULL;
	prev = NULL;
	student = NULL;

	cout << "Node default constructor" << endl;
}

Node::Node(Student* student) {
	next = NULL;
	prev = NULL;
	this->student = student;
}

Node::~Node() {
	delete student;
	cout << "Deleted Node" << endl;
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