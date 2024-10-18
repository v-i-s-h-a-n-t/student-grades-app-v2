#include <iostream>

#include "node.h"
#include "student.h"

using namespace std;

template <class T>
Node<T>::Node()
{
    next = NULL;
    prev = NULL;
    data = NULL;
}

template <class T>
Node<T>::Node(T *data)
{
    next = NULL;
    prev = NULL;
    this->data = data;
}

template <class T>
Node<T>::~Node()
{
    delete data;
}

template <class T>
void Node<T>::setNext(Node<T> *next)
{
    this->next = next;
}

template <class T>
Node<T> *Node<T>::getNext()
{
    return next;
}

template <class T>
void Node<T>::setPrev(Node<T> *prev)
{
    this->prev = prev;
}

template <class T>
Node<T> *Node<T>::getPrev()
{
    return prev;
}

template <class T>
void Node<T>::setData(T *data)
{
    this->data = data;
}

template <class T>
T *Node<T>::getData()
{
    return data;
}

// explicit instantiation declaration for Student class
template class Node<Student>;

// (required since Node classs is broken into .h and .cpp files)
// https://www.geeksforgeeks.org/why-can-templates-only-be-implemented-in-the-header-file/
