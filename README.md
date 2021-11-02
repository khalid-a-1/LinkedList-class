# CS173: Intermediate Computer Science

## Hw 8 : MyShoppingList Class

##### 1. ( 50p)
Complete all member functions of LinkedList class given in Notebowl. 
Test all functions with the given TestLinkedList.cpp file.

##### Output

```
(1) America
(2) Canada America
(3) Canada America Russia
(4) Canada America France Russia
(5) Canada America France Russia Germany
(6) Norway Canada America France Russia Germany
(7) Norway Canada America France America Russia Germany
(8) size of list= 7
(9) index of Russia is= 5
(10) Canada America France America Russia Germany
(11) Canada America France America Russia
(12) index of 2 element is= France
(13) last index of America is= 3
(14) Copy List: Canada America France America Russia
(15) America France America Russia
(16) America France America Morocco
(17) Clear copylist: Destroying nodes ...
America
France
America
Morocco
All nodes destroyed

list is empty
```
##### 2. ( 50p) 
Write a program “ MyShoppingList” that helps users to manage their shopping lists.
Each item, of the shopping list, includes the item’s name and the quantity needed of that
item. Items should be kept sorted alphabetically according to their names.

a. Define ShoppingList class to extend the LinkedList class.
b. Write the implementation for the most frequently operations:
                      
                      i. Add a new item to the shopping list.
                         addItem(string name, int quantity)

                      ii. Remove an item from the shopping list.
                         removeItem(int index)

                      iii. Modify the quantity of a given item.
                         updateQuantity(int index, int quantity)

                      iv. Clear the shopping list.

                      v. Print all items in the shopping list (using iterator).

                      vi. Adds the items in other shopping list to this list. Returns true if this shopping
                         list changed a result of the call. (if item has been added before, update
                         quantity of the item) boolean addAll(ShoppingList<E> otherList)

                      vii. Reduce the quantities of all the items in other shopping list from this list. If
                         updated quantity of item equals 0 then you will remove the item from this
                         list.
                         boolean removeReduceAll(ShoppingList<E> otherList)

c. Test your implementation with all member functions and print a sample run for
your implementation.

# For more information, read Hw8-ShoppingList.pdf


