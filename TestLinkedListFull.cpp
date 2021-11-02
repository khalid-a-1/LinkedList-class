#include <iostream>
#include <string>

#include "LinkedList.h"
#include "LinkedList.cpp"
using namespace std;


int main()
{
  // Create a list for strings
  LinkedList<string> list;

  // Add elements to the list
  list.addFirst("America");
  cout << "(1) ";
  list.printList();

  list.addFirst("Canada"); // Add it to the beginning of the list
  cout << "(2) ";
  list.printList();

  list.addLast("Russia"); // Add it to the end of the list
  cout << "(3) ";
  list.printList();

  list.add(2,"France");
  cout << "(4) ";
  list.printList();

  list.addLast("Germany");
  cout << "(5) ";
  list.printList();

  list.addFirst("Norway");
  cout << "(6) ";
  list.printList();

  list.add(4,"America");
  cout << "(7) ";
  list.printList();
  cout<<"(8) size of list= "<<list.getSize()<<endl;
  cout<<"(9) index of Russia is= "<<list.indexOf("Russia")<<endl;
  // Remove elements from the list
  list.removeFirst();
  cout << "(10) ";
  list.printList();

  list.removeLast(); // Remove the element at index 2
  cout << "(11) ";
  list.printList();

  cout<<"(12) index of 2 element is= "<<list.get(2)<<endl;
  cout<<"(13) last index of America is= "<<list.lastIndexOf("America")<<endl;
  LinkedList<string> listcopy(list);
  cout << "(14)Copy List: ";
  listcopy.printList();

  listcopy.remove("Canada");
  cout << "(15) ";
  listcopy.printList();
  listcopy.set(3,"Morocco");
  cout << "(16) ";
  listcopy.printList();
  cout << "(17)Clear copylist: ";
  listcopy.clear();
  listcopy.printList();

  return 0;
}
