#ifndef MY_TREE_H
#define MY_TREE_H
#include <cmath>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>

template <class T>
struct Node {
    T data;
    Node *left;
    Node *right ;

    Node(T data) : data(data), left(nullptr), right(nullptr) {}
    
    
};

template <class T>
class MyTree{

    private:
    Node<T> *root ;
    int size = 0;
    int height;

    Node<T>* H_MyTree(std::vector<T> elements, int start, int end){
        if (start > end) return nullptr;
        int mid =  (start + end ) / 2; 
        if (((start + end ) % 2) != 0){
             mid+=1;
        }
        Node<T> *temp = new Node<T> (elements[mid]);
        temp->left = H_MyTree(elements , start , mid-1);
        temp->right = H_MyTree(elements, mid+1, end);
        return temp;
    }


    void H_insert(Node<T> *temp , T key){
        if (temp->data > key){

            if (temp->left == nullptr){
                temp->left = new Node<T>(key);
            }
            else{
                H_insert(temp->left , key);
            }
        }
        else{

             if (temp->right == nullptr){
                temp->right = new Node<T>(key);
            }
            else{
                H_insert(temp->right , key);
            }
        }
        
    }


    Node<T>* H_search(Node<T> *temp ,T key){
        if (temp == nullptr) return temp;
        else if (temp->data == key) return temp;
        else if (temp->data > key) {
            return H_search(temp->left, key);
            }
        else {
            return H_search(temp->right, key);
        }
    }


    T get_Min(Node<T> *temp){
        if (temp->left == nullptr) {
            return temp->data;
            }
        else {
            return get_Min(temp->left);
        }
    }


    Node<T>* H_delete_node(Node<T> *H_root ,T key){

        if (H_root == nullptr) return nullptr;

        else if (H_root->data > key){
            
           H_root->left = H_delete_node(H_root->left , key);
        }

        else if (H_root->data < key){
            
          H_root->right = H_delete_node(H_root->right, key);
        }

        else{

            if (H_root->left == nullptr){
                Node<T>* temp = H_root->right;
                delete H_root;
                size--;
                return temp;
                
            }

            else if (H_root->right == nullptr){
                Node<T>* temp = H_root->left;
                delete H_root;
                size--;
                return temp;
                
            }

            else{
                T minValue = get_Min(H_root->right);
                H_root->data = minValue;
                H_root->right = H_delete_node(H_root->right , minValue);
                
            }
        }
        return H_root;
        
    }



    void H_inorder_rec(Node<T> *temp, std::vector<T>& vec){
            
            if (temp != nullptr){
                H_inorder_rec(temp->left, vec);
                vec.push_back(temp->data);
                H_inorder_rec(temp->right, vec);
            }
    }
        
    void H_preorder_rec(Node<T> *temp, std::vector<T>& vec){
            
            if (!temp ) return;
                vec.push_back(temp->data);
                H_preorder_rec(temp->left, vec);
                H_preorder_rec(temp->right, vec);
    }   
    
        
    void H_postorder_rec(Node<T> *temp, std::vector<T>& vec){
             

            if (temp != nullptr){
                H_postorder_rec(temp->left, vec);
                H_postorder_rec(temp->right, vec);
                vec.push_back(temp->data);
            }

    }


    void H_clear(Node<T> *temp){
        if (temp == nullptr) return;
        H_clear(temp->left);
        H_clear(temp->right);
        delete temp;
        root = nullptr;
    }

    void H_breadth_traversal(Node<T> *temp, std::vector<T>& vec){       // traverse the BST level by level and push elements into vector
        
        std::queue<T> q;
        if (temp == nullptr) return;
        q.push(temp->data);

            while(!q.empty()){
                
                Node<T>* current = new Node<T>(q.front());
                T data = current->data;
                vec.push_back(data);
                if (current->left)
                q.push(current->left->data);
                if (current->right)
                q.push(current->right->data);
                q.pop(); //remove the element at the front
            }
            
    }

    bool H_isBST(Node<T> *temp){
        std::vector<T> result;
        H_inorder_rec(root, result);

        for(int i = 1 ; i < result.size(); i++){
            if (result[i] <= result[i-1]) return false;
        }
        return true;
    }

    int H_height(Node<T>* temp)
{
    if(temp == NULL)
            return -1;
        int leftH = H_height(temp->left);
        int rightH = H_height(temp->right);
        return std::max(rightH, leftH)+1;
   
}





    public:
        MyTree(){
            root = nullptr;
            size = 0;
        }

        
        MyTree(std::vector<T> elements){
            size = elements.size();
            sort(elements.begin(), elements.end());
            root = H_MyTree(elements , 0 , size-1);
            
        }
   
        void insert(T key){
            if (root != nullptr){
                H_insert(root, key);
            }
            else{
                Node<T> *newNode = new Node<T>(key);
                root = newNode;
            }
          size++;
        }


        void insert(const Node<T> node){
             if (root != nullptr){
                H_insert(root, node->data);
            }
            else{
                Node<T> *newNode = new Node<T>(node->data);
            }
          size++;
        }


        const Node<T>* search(T key){
           Node<T> *result = H_search(root, key);
           return result;
        }

        
        const Node<T>* delete_node(T key){
            Node<T> *result = H_delete_node(root, key);
            return result;
        }

        const Node<T>* delete_node(const Node<T> node){
            Node<T> *result = H_delete_node(root, node->data);
            return result;
        }

        bool isBST(){
          return  H_isBST(root);
        }

        
        std::vector<T> inorder_rec(){
            std::vector<T> result;
            H_inorder_rec(root, result);
            return result;
        }

        
        std::vector<T> preorder_rec(){
            std::vector<T> result;
            H_preorder_rec(root, result); 
            return result; 
        }

        
        std::vector<T> postorder_rec(){
            std::vector<T> result;
            H_postorder_rec(root, result);
            return result;
        }

        
        std::vector<T> inorder_it(){
            std::vector<T> result;
            std::stack <Node<T>*> st;
            Node<T>* current = root;
            while(current || !st.empty()){
                while(current){
                    st.push(current);
                    current = current->left;
                }
                current = st.top();
                st.pop();
                result.push_back(current->data);
                current = current->right;
            }
            return result;
        }
        
        std::vector<T> preorder_it(){
            std::vector<T> result;
            std::stack<Node<T>*> st;
            while (root || !st.empty()) {
                if (root) {
                    result.push_back(root ->data);
                    if (root -> right) {
                        st.push(root -> right);
                    }
                    root = root -> left;
                } else {
                    root = st.top();
                    st.pop();
                }
            }
            return result;
    }
        
        
        std::vector<T> postorder_it(){
            std::vector<T> result;
            std::stack<Node<T>*> st;
            Node<T>* last = NULL;
            while (root || !st.empty()) {
                if (root) {
                    st.push(root);
                    root = root -> left;
                } else {
                    Node<T>* node = st.top();
                    if (node -> right && last != node -> right) {
                        root = node -> right;
                    } else {
                        result.push_back(node ->data);
                        last = node;
                        st.pop();
                    }
                }
            }
            return result;
        }


        std::vector<T> breadth_traversal(){
            std::vector<T> result;
            if(!root) return result;
            std::queue<Node<T>*> q;
            q.push(root);
            Node<T> *current = root;
            while (!q.empty()){
                current = q.front();
                result.push_back(current->data);
                q.pop();
                if(current->left) q.push(current->left);
                if(current->right) q.push(current->right);
            }
            return result;
            
        }
        


        int get_size(){
            return size;
        }


        int get_height(){
           return H_height(root) ;
            
        }

        void clear(){
            H_clear(root);
        }


        ~MyTree(){
             H_clear(root);
        }
};

  
#endif