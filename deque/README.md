# Deque Implementation in C++
## Overview
A deque (double-ended queue) is a linear data structure that supports insertion and deletion of elements at both ends, front and rear. It allows operations such as push, pop, enqueue and dequeue in constant time.

This repository contains the implementation of deque data structure in C++ without using the STL library. It includes the following functionalities:

*Push Front: Insert an element at the front of the deque.
* Push Back: Insert an element at the back of the deque.
* Pop Front: Remove an element from the front of the deque.
* Pop Back: Remove an element from the back of the deque.
* Front: Get the value of the front element.
* Back: Get the value of the back element.
* Size: Get the size of the deque.
* Empty: Check if the deque is empty.
# Usage
To use this deque implementation in your C++ program, you can include the deque.h header file in your code and create an instance of the Deque class.

```cpp

#include "deque.h"

int main() {
  Deque deque;

  deque.push_front(1);
  deque.push_back(2);
  deque.push_front(3);
  deque.push_back(4);

  std::cout << "Front element: " << deque.front() << std::endl; // Output: 3
  std::cout << "Back element: " << deque.back() << std::endl; // Output: 4

  deque.pop_front();
  deque.pop_back();

  std::cout << "Size: " << deque.size() << std::endl; // Output: 2

  return 0;
}
```
Contributing
If you find any bugs or want to suggest new features, feel free to open an issue or submit a pull request.
