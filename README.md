# Data Structures and Containers
This repository contains C++ implementations of various data structures and containers, including linked list, doubly linked list, queue, binary search tree, and dynamic memory allocation.

## Linked List
A linked list is a linear data structure in which elements are stored in a non-contiguous manner. Each element in the list, known as a node, contains a data field and a reference to the next node in the list. Linked lists are useful for implementing dynamic data structures where the size of the data is not known in advance.

## Doubly Linked List
A doubly linked list is a variation of the linked list in which each node contains references to both the next node and the previous node in the list. This allows for efficient traversal of the list in both directions.

## Dequeue
A deque, short for "double-ended queue," is a data structure that stores elements in a First-In, First-Out (FIFO) or Last-In, First-Out (LIFO) manner. Elements can be added or removed from either end of the deque, making it a versatile data structure for certain use cases.
## Binary Search Tree
A binary search tree is a binary tree in which each node has at most two children, and the left child contains values that are less than the parent, while the right child contains values that are greater than the parent. This structure allows for efficient searching of elements in the tree.

## Dynamic Memory Allocation
Dynamic memory allocation refers to the process of allocating memory during the execution of a program. This allows for the creation of data structures and containers whose size is not known in advance. Dynamic memory allocation is essential in many programming tasks, particularly when dealing with large data sets.

## How to Use
Each data structure and container is implemented in a separate C++ file. To use a particular data structure or container, simply include the corresponding header file in your program and use the provided functions and methods.

For example, to use the linked list implementation in your program, include the LinkedList.h header file and create a new LinkedList object:

c++
Copy code
```c++
#include "LinkedList.h"

LinkedList myList;

myList.add(5);
myList.add(10);
myList.add(15);
// ...
```

## Contributing
Contributions to this repository are welcome. If you would like to contribute a new data structure or container, please create a pull request with your changes.
