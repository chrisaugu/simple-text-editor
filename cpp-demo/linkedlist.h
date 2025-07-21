#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>

// Node structure
template <typename T>
struct Node
{
    T data;
    Node *next;

    Node(T value) : data(value), next(nullptr) {}
};

// LinkedList class
template <typename T>
class LinkedList
{
public:
    LinkedList();
    ~LinkedList();

    void append(T value);
    void insertAt(int index, T value);
    void removeAt(int index);
    T get(int index) const;
    int size() const;
    bool isEmpty() const;
    void print() const;

private:
    Node<T> *head;
    int length;

    Node<T> *getNodeAt(int index) const;
};

// #include "linkedlist.tpp"

#endif // LINKEDLIST_H