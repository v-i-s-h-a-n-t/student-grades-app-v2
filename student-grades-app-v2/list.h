#pragma once

#include <iostream>

#include "node.h"

template <class T>
class List
{
private:
    Node<T> *head;
    Node<T> *tail;
    int size;

public:
    List();
    ~List();

    Node<T> *getNode(int index);
     int getSize();

    void appendNode(T *data);
    void removeNode();  
};