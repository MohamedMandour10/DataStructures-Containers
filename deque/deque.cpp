using namespace std;
#include <iostream>
#include "deque.h"




    node::node(){             //default constructor
        data = 0;
        next = prev = nullptr;

    }

    node::node(int element){         //initialise node with given data
        data = element;
        next = prev = nullptr;

    }

    node::~node(){           //destructor
    delete[] next;
    delete[] prev;
    }


    My_Deque::My_Deque(){          //default constructor

        Head = tail = nullptr;
        size = 0;
    }

 
    My_Deque::~My_Deque(){

    }

    void My_Deque::push_back(int value){      // add the element to the end of the deque
        node *newNode = new node(value);
     if (Head == nullptr && tail == nullptr) {      //case(1): the deque is empty
        Head = tail = newNode;
        newNode->next = newNode->prev = nullptr;
    } else {                                   //case(2): place node at end of the deque
        newNode->next = nullptr;
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
    }
    size++;
    }

    void My_Deque::push_front(int value){         // add the element to the beginning of the deque
        node *newNode = new node(value);
        if (Head == nullptr && tail == nullptr) {       //case(1): the deque is empty
            Head = tail = newNode;
            newNode->next = newNode->prev = nullptr;
        } else {                                                    //case(2): place node at beginning of the deque
            newNode->next = Head;
            newNode->prev = nullptr;
            Head->prev = newNode ;
            Head =  newNode;
        }
        size++;
    }

    int My_Deque::pop_front(){        // remove the first element, return the removed element
       if (Head == nullptr ) return -1;             // the deque is empty
        int removed = Head->data ;

         if(size == 1) {                           // case we have only one node
            free(Head);
            Head = tail = nullptr;
        } else {                                        // case we have more than one node
            node *current = Head ;
            Head = Head->next;
            Head->prev = nullptr;
            free(current);
        }
        size--;
        return removed;
    }

    int My_Deque::pop_back(){                 // remove the last element, return the removed element
        if (Head == nullptr ) return -1;            // the deque is empty
        int removed = tail->data ; 

        if(size == 1) {                           // case we have only one node
            free(Head);
            Head = tail = nullptr;

        } else {                            // case we have more than one node
            node *current = tail ;
            tail = tail->prev;
            tail->next = nullptr ;
            free(current);
        }
        size--;
        return removed;
    }

    int My_Deque::begin(){                                       // return the first element
        if (Head == nullptr && tail == nullptr) return -1;
        return Head->data ;
    }

    int My_Deque::end(){                                         // return the last element
        if (Head == nullptr && tail == nullptr) return -1;
        return tail->data ;
    }

    int My_Deque::get_size(){                               // return the deque size
        return size;
    }

    void My_Deque::clear(){                     // clear the whole array
         Head = tail = nullptr;
        size = 0;
    }

    void My_Deque::print(){                                         // print the whole deque from head to tail
        node *move = Head ;
        if (Head == nullptr){
            cout<<"Linked list is empty";
            return;
        }
        cout<<"{";
        while(move != nullptr){                     // loop over the elements in the deque 
            cout<<move->data<<" ";                   // print the element  
            move = move->next;                       // move to the next
        }
        cout<<"}"<<"\n";                            
    }

    std::vector<int> My_Deque::toVector(){          // convert the deque to vector and return that vector
        std::vector<int> v;
        node *current = Head;
        while(current!= nullptr){                    // loop through the deque
            v.push_back(current->data);             // add the current element to the vector
            current = current->next;                // move to the next element
        }
        return v;
     }