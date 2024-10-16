#include <iostream>

#include "node.h"
#include "student.h"

using namespace std;

template<typename T> Node<T>::Node() {
	next = NULL;
	prev = NULL;
	data = NULL;
}

template<typename T> Node<T>::Node(T* data) {
	next = NULL;
	prev = NULL;
	this->data = data;
}

template<typename T> Node<T>::~Node() {
	delete data;
}

template<typename T> void Node<T>::setNext(Node<T>* next) {
	this->next = next;
}

template<typename T> Node<T>* Node<T>::getNext() {
	return next;
}

template<typename T> void Node<T>::setPrev(Node<T>* prev) {
	this->prev = prev;
}

template<typename T> Node<T>* Node<T>::getPrev() {
	return prev;
}

template<typename T> void Node<T>::setData(T* data) {
	this->data = data;
}

template<typename T> T* Node<T>::getData() {
	return data;
}

// explicit instantiation declaration for Student class 
// (required since Node classs is broken into .h and .cpp files)
template class Node<Student>;