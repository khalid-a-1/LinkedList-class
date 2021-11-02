#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <stdexcept>
#include <iostream>
using namespace std;

template<typename T>
class Node
{
public:
  T element;  // Element contained in the node
  Node<T>* next; // Pointer to the next node

  Node() // No-arg constructor
  {
    next = NULL;
  }

  Node(T element) // Constructor
  {
    this->element = element;
    next = NULL;
  }
};

template<typename T>
class LinkedList
{
public:
  LinkedList();
  LinkedList(LinkedList<T>& list);
  ~LinkedList();
  void addFirst(T element);
  void addLast(T element);
  void add(T element);
  T getFirst() const;
  T getLast() const;
  T get(int index) const;
  T removeFirst() throw (std::runtime_error);
  T removeLast();
  void clear();
  bool isEmpty() const;
  int getSize() const;
  T set(int index, T element);
  void add(int index, T element);
  bool remove(T element);
  T removeAt(int index) throw (std::runtime_error);
  bool contains(T element);
  int lastIndexOf(T element) const;
  int indexOf(T element) const;
  void printList() const;

private:
  Node<T>* head;
  Node<T>* tail;
  int size;
};


#endif
