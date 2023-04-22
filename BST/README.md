# Binary Search Tree Implementation in C++
This repository contains a basic implementation of a binary search tree in C++.

## Overview
A binary search tree is a data structure used for searching and sorting data. It consists of nodes that store data and have two children, a left child and a right child. Each node in the left subtree is less than the node, and each node in the right subtree is greater than the node.

## Implementation
The implementation consists of a Node class and a BinarySearchTree class. The Node class represents a node in the binary search tree and contains the data and pointers to the left and right children. The BinarySearchTree class contains the root node of the tree and provides methods to insert, search, and delete nodes.

## Usage
To use the binary search tree, include the BinarySearchTree.h header file in your C++ program. Then create a BinarySearchTree object and use the provided methods to insert, search, and delete nodes.

## Example
```cpp
#include <iostream>
#include "my_tree.h"

using namespace std;

int main() {
    MyTree bst;

    // Insert nodes
    bst.insert(5);
    bst.insert(3);
    bst.insert(7);
    bst.insert(1);
    bst.insert(9);

    // Search for a node
    Node* node = bst.search(7);
    if (node != nullptr) {
        cout << "Found node with value " << node->data << endl;
    } else {
        cout << "Node not found" << endl;
    }

    // Delete a node
    bst.remove(3);

    return 0;
}
```
Contributing
Contributions are welcome! If you find a bug or have a suggestion for improvement, please create an issue or submit a pull request.
