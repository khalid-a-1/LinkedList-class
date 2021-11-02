#include <stdexcept>
#include <iostream>
//#include "Node.h"
#include "LinkedList.h"
using namespace std;

template<typename T>
LinkedList<T>::LinkedList()
{
  head = tail = NULL;
  size = 0;
}
// deep copy
template<typename T>
LinkedList<T>::LinkedList(LinkedList<T>& list)
{
  head = tail = NULL;
  size = 0;

  Node<T>* current = list.head;
  while (current != NULL)
  {
    this->add(current->element);
    current = current->next;
  }
}

// only one , you can not overload
template<typename T>
LinkedList<T>::~LinkedList()
{
  clear();
}

template<typename T>
void LinkedList<T>::addFirst(T element)
{
  Node<T>* newNode = new Node<T>(element);
  newNode->next = head;
  head = newNode;
  size++;

  if (tail == NULL)
    tail = head;
}

template<typename T>
void LinkedList<T>::addLast(T element)
{
  if (tail == NULL)
  {
    head = tail = new Node<T>(element);
  }
  else
  {
    tail->next = new Node<T>(element);
    tail = tail->next;
  }

  size++;
}

template<typename T>
T LinkedList<T>::getFirst() const
{
  if (size == 0)
    throw runtime_error("Index out of range");
  else
    return head->element;
}

template<typename T>
T LinkedList<T>::getLast() const
{
  if (size == 0)
    throw runtime_error("Index out of range");
  else
    return tail->element;
}

template<typename T>
void LinkedList<T>::add(T element)
{
  addLast(element);
}


template<typename T>
T LinkedList<T>::removeFirst() throw (runtime_error)
{
  if (size == 0)
   throw runtime_error("No elements in the list");
  else
  {
    Node<T>* temp = head;
    head = head->next;
    if (head == NULL) tail = NULL;
    size--;
    T element = temp->element;
    delete temp;
    return element;
  }
}

template<typename T>
T LinkedList<T>::removeLast()
{
  if (size == 0)
    throw runtime_error("No elements in the list");
  else if (size == 1)
  {
    Node<T>* temp = head;
    head = tail = NULL;
    size = 0;
    T element = temp->element;
    delete temp;
    return element;
  }
  else
  {
    Node<T>* current = head;

    for (int i = 0; i < size - 2; i++)
      current = current->next;

    Node<T>* temp = tail;
    tail = current;
    tail->next = NULL;
    size--;
    T element = temp->element;
    delete temp;
    return element;
  }
}


template<typename T>
void LinkedList<T>::clear()
{
//  cout << "Destroying nodes ...\n";

  while (head != NULL)
  {
    Node<T>* temp = head;
    head = head->next;
    delete temp;
  }
//  cout << "All nodes destroyed\n\n";
  tail = NULL;
  size = 0;
}

template<typename T>
bool LinkedList<T>::isEmpty() const
{
  return head == NULL;
}

template<typename T>
int LinkedList<T>::getSize() const
{
  return size;
}

template<typename T>
void LinkedList<T>::printList() const{
   Node<T> * temp=head;
   if (size>0){
     for (int i=0;i<size;i++){
       cout<<temp->element<<" ";
       temp=temp->next;
     }
     cout<<endl;
   }
   else
    cout<<"list is empty"<<endl;
}

template<typename T>
void LinkedList<T>::add(int index, T element){
  if(index == 0)
    addFirst(element);
  else if (index >= size)
    addLast(element);
  else
  {
    Node<T>* current = head;
    for(int i = 1; i < index; i++)
    current = current->next;
    Node<T>* temp = current->next;
    current->next = new Node<T>(element);
    (current->next)->next = temp;
    size++;
  }
}

template<typename T>
T LinkedList<T>::removeAt(int index)throw(runtime_error)
{
  if (index < 0 ||index >= size)
    throw runtime_error("Index out of range");
  else if (index == 0)
    return removeFirst();
  else if (index == size - 1)
    return removeLast();
  else
  {
    Node<T>* previous = head;
    for(int i = 1; i < index; i++){
      previous = previous->next;
    }
    Node<T>*current = previous->next;
    previous->next = current->next;
    size--;
    T element = current->element;
    delete current;
    return element;
  }
}

template<typename T>
T LinkedList<T>::set(int index, T element){
    Node<T>* current = head;
    for(int i = 0; i < index-1; i++)
    current = current->next;
    current->next = new Node<T>(element);
    return element;
    }

  template<typename T>
  bool LinkedList<T>::remove(T element){
    Node<T>* current = head;
    Node<T>* temp = current;
    if(head->element == element){
      head = head->next;
      size--;
      return true;
    }
    for(int i = 0; i< size; i++){
      if(current->element == element){
        temp->next = current->next;
        size--;
        return true;
      }
      temp = current;
      current = current->next;
    }
    return false;
  }

template<typename T>
bool LinkedList<T>::contains(T element){
  Node<T>* current = head;
  for(int i = 0; i< size; i++){
    if(current->element == element){
      return true;
    }
  }
  return false;
}

template<typename T>
T LinkedList<T>::get(int index) const{
  if (index < 0 || index > size - 1){
    throw runtime_error("Index out of range");
  }
  Node<T> *current = head;
  for (int i = 0; i < index; i++){
    current = current->next;
  }
  return current->element;
}

template<typename T>
int LinkedList<T>::indexOf(T element) const {
  Node<T> *current = head;
  for (int i = 0; i < size; i++){
    if (current->element == element){
      return i;
    }
    current = current->next;
  }
  return -1;
}

template<typename T>
int LinkedList<T>::lastIndexOf(T element) const{
  Node<T> *current = head;
  int temp = -1;
  for (int i = 0; i < size; i++){
    if (current->element == element){
      temp = i;
    }
    current = current->next;
  }
  return temp;
}
