#include "Lk.h"
#include <iostream>
using namespace std;


    node::node(){             //default constructor
        data = 0;
        next = nullptr;
}

    node::node(int element){         //initialise node with given data
        data = element;
        next = nullptr;
}

    node::~node(){
    delete[] next;
}

    My_List::My_List(){          //default constructor
        Head = nullptr;
}

    void My_List::addNode(int element){                //create new node at the end with given data
        node *newNode = new node(element);
                //case(1): node is at the beginning of list
        if(Head == nullptr){
            Head = newNode;
            newNode->next= nullptr;
        }
                 //case(2): place node at the end of list
        node *last = Head  ;
        while (last->next != nullptr)      //moves until it reaches last node
        {
            last = last->next;
        }
        last->next = newNode ;
        newNode->next = nullptr ;
}

    void My_List::addNodeBeg(int element){
        node *newNode = new node(element);
        newNode->next = Head ;
        Head = newNode ;

    }

    void My_List::print(){                              //display all elements of list
        node *last = Head ;

        if (Head == nullptr){
            cout<<"Linked list is empty";
            return;
        }
        cout<<"{";
        while(last != nullptr){
            cout<<last->data<<" ";
            last = last->next;
        }
        cout<<"}";

}

    void My_List::deleteNode(int element){              //delete node of which a certain element is given

        if(Head == nullptr){                   //empty list
            cout<<"linked list is empty"<<"\n";
            return;
        }

        node *removed = Head ;        //points to node that need to be deleted
        node *previous = Head;        // points to the previous node of deleted node

        if(removed->data == element){           //case(1): deleted node is at the beginning of list
            Head = removed->next;
            free(removed);
            return;
        }

        while(removed->data != element){              //case(2): deleted node is at an unknown place of list
            previous = removed;
            removed = removed->next;                 // increment loop until reaching desired node
        }
        previous->next = removed->next ;
        free(removed);

    }