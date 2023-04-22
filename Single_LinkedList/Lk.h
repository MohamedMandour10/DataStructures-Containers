#ifndef __LK_H__
#define __LK_H__

class node
{
public:
    int data;
    node *next;
    
public:
    node();      //default constructor

    explicit node(int data);   //parameterized constructor

    ~node();       //destructor
};



class My_List {
private:

    node *Head ;

public:

   My_List();        //default constructor to initialise node

   void addNode(int element);      //create new node at the end with given data

   void addNodeBeg(int element);

   void deleteNode(int element);   //delete node of which a certain element is given

   void print();                 //display all elements of list

};


#endif