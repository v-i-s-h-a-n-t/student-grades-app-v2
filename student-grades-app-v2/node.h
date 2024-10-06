#pragma once

#include <iostream>

#include "student.h"

class Node
{
private:
	Node* next;
	Node* prev;
	Student* student;

public:
	Node();
	~Node();
	
	void setNext(Node* node);
	Node* getNext();

	void setPrev(Node *node);
	Node* getPrev();

	void setStudent(Student* student);
	Student* getStudent();
};

