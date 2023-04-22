# Implementation of Single LinkedList in C++
This is an implementation of the singly linked list data structure in C++. The linked list consists of a sequence of nodes, each containing a piece of data and a pointer to the next node in the sequence.

## Features
Insertion of a node at the beginning, end or at a given position
Deletion of a node from the beginning, end or at a given position
Searching for a node in the list
Traversing the list to print or modify its contents

## Usage
Clone the repository or download the files
Include the header file singly_linked_list.h in your program
Create an object of the SinglyLinkedList class
Use the provided member functions to perform operations on the list

## Example usage:
```cpp

#include "LK.h"

int main() {
  lk<int> list;

  // Insertion at the end
  list.insertAtEnd(10);
  list.insertAtEnd(20);

  // Insertion at the beginning
  list.insertAtBeginning(5);

  // Insertion at a given position
  list.insertAtPosition(15, 2);

  // Deletion from the end
  list.deleteAtEnd();

  // Deletion from the beginning
  list.deleteAtBeginning();

  // Deletion at a given position
  list.deleteAtPosition(1);

  // Searching for an element
  if (list.search(20)) {
    std::cout << "Element found" << std::endl;
  } else {
    std::cout << "Element not found" << std::endl;
  }

  // Traversing the list
  list.traverse([](int element){ std::cout << element << std::endl; });

  return 0;
}
```
## Contributing
Pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change.
