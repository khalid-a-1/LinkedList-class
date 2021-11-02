#include <iostream>
#include <string>

#include "ShoppingList.h"
#include "ShoppingList.cpp"

using namespace std;

int main()
{

// create first shopping list =======================================
  ShoppingList<string> list;
  cout<<"Print our first shipping list:-"<<endl;
  list.addItem("Zeff",4);
  list.addItem("Egg", 12);
  list.addItem("Cereal",2);
  list.printList();

  cout<<"Shopping list after removing item at index 0"<<endl;
  list.removeItem(0);
  list.printList();

  cout<<"shopping list after updating quantity at index 0 to the quantity to 6"<<endl;
  list.updateQuantity(0,6);
  list.printList();
//creat second shopping list ========================================
  cout<<"Creating another shopping list"<<endl;
  ShoppingList<string> otherList;
  otherList.addItem("Zeff",-4);
  otherList.addItem("Egg", 12);
  otherList.addItem("Aex",2);
  otherList.printList();

  cout<<"We see what first list looks like"<<endl;
  list.printList();
  cout<<"We see what the second list looks like"<<endl;
  otherList.printList();
  cout<<"Using Function removeReduceAll on first by using second list"<<endl;
  list.removeReduceAll(otherList);
  list.printList();
  cout<<"We see what first list looks like"<<endl;
  list.printList();
  cout<<"We see what the second list looks like"<<endl;
  otherList.printList();
  cout<<"Using function addAll on first list by using second list"<<endl;
  list.addAll(otherList);
  list.printList();

  return 0;
}
