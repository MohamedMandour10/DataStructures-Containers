#include "DLk.h"
#include <iostream>
using namespace std;


    node::node(){             //default constructor
        data = 0;
        next = prev = nullptr;

}

    node::node(int element){         //initialise node with given data
        data = element;
        next = prev = nullptr;

}

    node::~node(){
    delete[] next;
    delete[] prev;
}

    My_List::My_List(){          //default constructor
        Head = tail = nullptr;
        size = 0;
}

    void My_List::addFirst(int element) {      //create new node at the beginning of list with given data
        node *newNode = new node(element);
        if (Head == nullptr && tail == nullptr) {
            Head = tail = newNode;
            newNode->next = newNode->prev = nullptr;
        } else {
            newNode->next = Head;
            newNode->prev = nullptr;
            Head->prev = newNode ;
            Head =  newNode;
            
        }
        size++;
    }

void My_List::addLast(int element) {      //create new node at the end of list with given data
    node *newNode = new node(element);
     if (Head == nullptr && tail == nullptr) {
        Head = tail = newNode;
        newNode->next = newNode->prev = nullptr;
    } else {
        newNode->next = nullptr;
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
    }
    size++;
}

void My_List::addAt(int position ,int element){
        if(position< 0 || position > size) cout<<"out of range"<<"\n";
        else if(position == 0) addFirst(element);
        else if(position == size) addLast(element);
        else{
            node *newNode = new node(element);
            node *current = Head ;
            for(int i = 1 ; i< position ; i++){
                current = current->next;
            }
            newNode->prev = current;
            newNode->next = current->next;
            current->next = newNode;
            current->next->prev = newNode;
        }
        size++;
    }


    void My_List::printForward(){                              //display all elements of list
        node *move = Head ;
        if (Head == nullptr){
            cout<<"Linked list is empty";
            return;
        }
        cout<<"{";
        while(move != nullptr){
            cout<<move->data<<" ";
            move = move->next;
        }
        cout<<"}"<<"\n";

}

    void My_List::printBackward() {
        node *move =tail ;
        if (Head == nullptr){
            cout<<"Linked list is empty";
            return;
        }
        cout<<"{";
        while(move != nullptr){
            cout<<move->data<<" ";
            move = move->prev;
        }
        cout<<"}"<<"\n";

    }


   void My_List::deleteFirst(){              //delete node of which a certain element is given
        if(Head== nullptr) cout<<"list is empty";      //case empty list
        else if(size == 1) {                           // case we have only one node
            delete[] Head;
            Head = tail = nullptr;
        } else {
            node *current = Head ;
            Head = Head->next;
            Head->prev = nullptr;
            free(current);
        }
        size--;
    }

    void My_List::deleteLast() {
        if(Head== nullptr) cout<<"list is empty";
        else if(size == 1) {                           // case we have only one node
            delete[] Head;
            Head = tail = nullptr;
        } else {
            node *current = tail ;
            tail = tail->prev;
            tail->next = nullptr ;
            free(current);
        }
        size--;
    }

void My_List::deleteAt(int position) {
    if(position< 0 || position > size) cout<<"out of range"<<"\n";
    else if(position == 0) deleteFirst();
    else if(position == size) deleteLast();
    else{
        node *current = Head ;
        for(int i = 0 ; i< position ; i++){
            current = current->next;
        }
        current->next->prev = current->prev;
        current->prev->next = current->next;
        free(current);
        size--;
    }

    }

int My_List::length() const{
        return size;
    }
