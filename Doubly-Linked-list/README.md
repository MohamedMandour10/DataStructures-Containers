# Doubly-Linked-List Implementation
This repository contains a basic implementation of a doubly-linked-list in Python.

## Overview
A doubly-linked-list is a data structure used to store a collection of elements. Each element (or node) in a doubly-linked-list contains a reference to the previous and next elements in the list. This allows for efficient insertion and deletion of elements at any position in the list.

## Implementation
The implementation consists of a Node class and a DoublyLinkedList class. The Node class represents a node in the doubly-linked-list and contains the data and pointers to the previous and next nodes. The DoublyLinkedList class contains the head and tail nodes of the list and provides methods to insert, search, and delete nodes.

## Usage
To use the doubly-linked-list, import the DoublyLinkedList class in your Python program. Then create a DoublyLinkedList object and use the provided methods to insert, search, and delete nodes.

## Example
```cpp
#include <iostream>
#include "DLk.h"

using namespace std;

int main() {  
 // Insert nodes
  dll.insert(5);
  dll.insert(3);
  dll.insert(7);
  dll.insert(1);
  dll.insert(9);

  // Search for a node
  Node<int>* node = dll.search(7);
  if (node != nullptr) {
    std::cout << "Found node with value " << node->data << std::endl;
  } else {
    std::cout << "Node not found" << std::endl;
  }

  // Delete a node
  dll.remove(3);

  return 0;
```
## Contributing
Contributions are welcome! If you find a bug or have a suggestion for improvement, please create an issue or submit a pull request.
