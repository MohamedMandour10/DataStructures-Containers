#include <iostream>
#include "my_tree.h"

using namespace std;

int main(){
  // std::vector<int> input = {20, 14, 99, 6, 19, 64, 8, 39, 71, 44, 65, 76, 47, 72};
  //   MyTree<int> my_tree = MyTree<int>();
  //   for (int i : input)
  //   {
  //       my_tree.insert(i);
  //   }
  //   std::vector<int> preOrder = {20, 14, 6, 8, 19, 99, 64, 39, 44, 47, 71, 65, 76, 72};
  //   std::vector<int> result = my_tree.preorder_rec();
  //   // bool ok = true;
  //   if (result == preOrder){
  //     cout<< "true";
  //   }
  //   else cout<< "false";

  std::vector<int> input = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    MyTree<int> my_tree = MyTree<int>(input);
    my_tree.delete_node(4);
    my_tree.delete_node(9);
    my_tree.delete_node(7);
    cout<<my_tree.get_size()<<endl;
    cout<<my_tree.get_height()<<endl;
    cout<<my_tree.isBST() <<endl;
  return 0;  
}