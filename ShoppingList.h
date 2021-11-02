#ifndef SHOPPINGLIST_H
#define SHOPPINGLIST_H
#include <stdexcept>
#include <iostream>
#include <string>
#include "LinkedList.h"
using namespace std;

template<typename E>
class ShoppingList
{
public:
  ShoppingList();
  void addItem(string name, int quantity);
  void removeItem(int index);
  void updateQuantity(int index, int quantity);
  void clear();
  void printList() ;
  bool addAll(ShoppingList<E> otherList);
  bool removeReduceAll(ShoppingList<E> otherList);

private:
  LinkedList<string> list;
  LinkedList<int> list1;
  Node < E > * current;


};



#endif
