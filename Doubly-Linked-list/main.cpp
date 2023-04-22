#include <iostream>
#include "DLk.h"
#include "DLk.cpp"
using namespace std;

int main(){

auto *node1 = new My_List()  ;
    node1->addLast(5);
    node1->addLast(7);
    node1->addLast(9);
    node1->addLast(10);
    node1->addLast(11);
    node1->addLast(12);
    node1->addLast(13);
    node1->deleteAt(5);
    node1->printForward();
    cout<<node1->length();
return 0;
}
