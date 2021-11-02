#include <stdexcept>
#include <iostream>
#include <string>
//#include "Node.h"
#include "LinkedList.h"
#include "ShoppingList.h"
#include "LinkedList.cpp"

using namespace std;


template<typename E>
ShoppingList<E>::ShoppingList(){
}


template<typename E>
void ShoppingList<E>::addItem(string name, int quantity){
int check = 0 ;
  if(list.isEmpty())
  {
      list.add(name);
      list1.add(quantity);
      check++;
  }
   if(check == 0 )
   {
    for(int i =0 ; i< list.getSize();i++ )
    {

     if( i == list.getSize()){
        list.addLast(name);
        list1.addLast(quantity);
      }
      else if(name < list.get(i)){
        list.add(i,name);
        list1.add(i,quantity);
        break;
      }
    }
   }
}


template<typename E>
void ShoppingList<E>::removeItem(int index){
  list.removeAt(index);
  list1.removeAt(index);
}

template<typename E>
void ShoppingList<E>::updateQuantity(int index, int quantity){
  list1.removeAt(index);
  list1.add(index, quantity);
}

template<typename E>
void ShoppingList<E>::clear(){
  list.clear();
  list1.clear();
}

template<typename E>
void ShoppingList<E>::printList() {

  for(int i = 0;i < list.getSize(); i++) {
  string item = list.get(i);
  int quan = list1.get(i);
  cout<< item<<" "<<quan <<endl;
}
}

template<typename E>
bool ShoppingList<E>::addAll(ShoppingList<E> otherList){
  int flag = -1;
  for(int j = 0; j < otherList.list.getSize(); j++){
    string item_02= otherList.list.get(j);
    for(int i = 0; i<list.getSize(); i++){
      string item_01= list.get(i);
      if (item_01==item_02){
        int q1 = list1.get(i);
        int q2 = otherList.list1.get(j);
        int Q = q1+q2;
        updateQuantity(i, Q);
        flag=1;
        break;
      }
    }
    if(flag == -1)
    {

      for(int k =0 ; k<= list.getSize();k++ )
      {
       if( k == list.getSize()){
          list.addLast(item_02);
          list1.addLast(otherList.list1.get(j));
          break;
        }
        else if(item_02 < list.get(k)){
          list.add(k,item_02);
          list1.add(k,otherList.list1.get(j));
          break;
        }
      }
    }
    flag = -1;
  }
  return 1;
}

template<typename E>
bool ShoppingList<E>::removeReduceAll(ShoppingList<E> otherList){
  int flag = -1;
  for(int j = 0; j < otherList.list.getSize(); j++){
    string item_02= otherList.list.get(j);
    for(int i = 0; i<list.getSize(); i++){
      string item_01= list.get(i);
      if (item_01==item_02){
        int q1 = list1.get(i);
        int q2 = otherList.list1.get(j);
        int Q = q1+q2;
        if(Q==0){
          removeItem(i);
          flag=1;
          break;
        }
        else {
        updateQuantity(i, Q);
        flag=1;
        break;
      }
      }
    }
    if(flag == -1)
    {
      for(int k =0 ; k< list.getSize();k++ )
      {

       if( k == list.getSize()){
          list.addLast(item_02);
          list1.addLast(otherList.list1.get(j));
        }
        else if(item_02 < list.get(k)){
          list.add(k,item_02);
          list1.add(k,otherList.list1.get(j));
          break;
        }
      }
    }
    flag = -1;
  }
  return 1;
}
