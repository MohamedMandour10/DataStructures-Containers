#include "da.h"
#include <iostream>
using namespace std;



My_DA::My_DA(){         // non parameterized constructor to initialise data
 data = new int[capacity];

}


My_DA::My_DA(int arr[], int size){   //pass given data & push elements
    data = new int(capacity);
    for(int i = 0; i< size; i++){
        push(arr[i]);
    }
}

int My_DA::get(int index){      //return the value of a given index "position"
 return data[index];
}



void My_DA::grow_size(){                      // double the capacity of the array
    int* temp = new int[capacity*2];          // creating a temporary array to move data of original array
    for(int i =0 ; i < size ; i++){            
       temp[i]= data[i];
    }
    capacity*=2;
    data = temp;
    //delete[] temp;
    
    }


void My_DA::push(int element) {               //Adding element to the last index
    if (capacity == size) {                   // increase capacity if there is no enough space
        My_DA::grow_size();
    }
    data[size] = element;
    size++;

}
 int My_DA::pop() {                      // remove the last element, return the removed element
if(size == 0) return -1;
    int removed = data[size - 1];        //last element is placed in the last position "size points to position after last element"
    size--;
    if(size < capacity / 2) capacity /= 2;      //shrink the size of the array to reduce memory consumption
    return removed;
}


void My_DA::insert(int index, int element) {    //insert element to a given index
    if (index == capacity) {     //special case "ordinary push operation"
        My_DA::push(element);
    }
    else if(index < capacity){
        for(int i = size; i > index ; i--){    //shift data of the array to place given element
            data[i] = data[i-1];
        }
        data[index] = element;
    }

}

int My_DA::remove(int index){   //remove element from given index
    if(index >= size) return -1;    //error
    int removed = data[index];
    for (int i = index; i < size - 1; i++){        //shift data of the array to remove given element
        data[i] = data[i + 1];
    }
    size--;
    if(size < capacity / 2) capacity /= 2;
    return removed;
}

void My_DA::print(){       //print hte whole elements of the array
    
        for(int i=0 ; i<size ; i++){
            cout<<data[i]<<" ";
        }
        cout<<endl;
    }


void My_DA::clear(){       //return the array to its initial condition
    data = new int(1);
    size = 0;

}

int My_DA::find(int element){       //search for a given element & return it
    for(int i=0 ; i<size ; i++){
        if (data[i] == element)
        return i;
    }
       return -1;
}

 
void My_DA::shrink_to_fit(){        //reduce capacity of the array to fit size
 if(capacity>size){
    int *temp = new int(size);
    for(int i=0 ; i<size ; i++){
        temp[i]= data[i];
    }
    capacity= size;
     swap(data ,temp);
    //delete[] temp;
 }
}

int My_DA::get_size() const{
    return My_DA::size ;
}

int My_DA::get_capacity() const{
    return My_DA::capacity ;
}

My_DA::~My_DA(){             // destructor for memory deallocation
  delete[] data;
}






















