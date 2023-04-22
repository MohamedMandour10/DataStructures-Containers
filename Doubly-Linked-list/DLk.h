#ifndef __DLK_H__
#define __DLK_H__

class node
{
private:
    int data;
    node *next;
    node *prev;
    
public:
    node();      //default constructor

    explicit node(int data);   //parameterized constructor

    ~node();       //destructor
};



class My_List {
private:

    node *Head ;
    node *tail ;
    int size = 0 ;

public:

   My_List();        //default constructor to initialise node

   void addFirst(int element);      //create new node at the end with given data

   void addLast(int element);

    void addAt(int position ,int element);

   void deleteFirst();

    void deleteLast();   //delete node of which a certain element is given

    void deleteAt(int position);

   void printForward();                 //display all elements of list

   void printBackward();

   int length() const;

};


#endif
