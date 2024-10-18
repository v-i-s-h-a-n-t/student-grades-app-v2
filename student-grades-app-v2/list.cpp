#include <iostream>

#include "list.h"
#include "student.h"

using namespace std;

template <class T>
List<T>::List()
{
    head = NULL;
    tail = NULL;
    size = 0;
}

template <class T>
List<T>::~List()
{
    while (head != NULL)
    {
        removeNode();
    }
}

// Get a node at specified index
template <class T>
Node<T> *List<T>::getNode(int index)
{
    Node<T> *node = head;

    for (int i = 0; i < index; i++)
    {
        node = node->getNext();
    }

    return node;
}

template <class T>
int List<T>::getSize()
{
    return size;
}

// Add a node to the end of the linked list
template <class T>
void List<T>::appendNode(T *data)
{
    Node<T> *newNode = new Node<T>(data);

    // Check is newNode is the first node
    if (head == NULL)
    {
        head = newNode;
    }

    else
    {
        tail->setNext(newNode);
        newNode->setPrev(tail);
    }

    tail = newNode;
    size++;
}

// Remove a node from the beginning of the linked list
template <class T>
void List<T>::removeNode()
{
    Node<T> *nodeToRemove = head;

    // Check is nodeToRemove is the last node
    if (nodeToRemove->getNext() == NULL)
    {
        head = NULL;
        tail = NULL;
    }

    else
    {
        head = nodeToRemove->getNext();
        head->setPrev(NULL);
    }

    delete nodeToRemove;
    nodeToRemove = NULL;
    size--;
}

// explicit instantiation declaration for Student class
template class List<Student>;

// (required since List classes is broken into .h and .cpp files)
// https://www.geeksforgeeks.org/why-can-templates-only-be-implemented-in-the-header-file/
