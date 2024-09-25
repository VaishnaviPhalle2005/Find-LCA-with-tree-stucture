#include<iostream>
using namespace std;
struct Node
{
 int data;
 Node*left;
 Node*right;
 Node(int value):data(value),left(nullptr),right(nullptr){}
};

class BST
{
 public:
        Node*root;
       
        BST():root(nullptr){}
       
        void insert(int data){
             root=insert(root,data);
        }
       
        Node* findLCA(int n1, int n2){
             return findLCA(root, n1, n2);
        }
 private:
       
        Node*insert(Node*node,int data){
        if(node==nullptr){
           return new Node(data);
        }
        if(data<node->data){
           node->left=insert(node->left,data);
        }
        else{
        node->right=insert(node->right,data);
        }
        return node;
        }
       
        Node* findLCA(Node* node , int n1 , int n2){
        while (node!=nullptr){
           if (n1 < node-> data && n2> node -> data){
               node=node->left;
           }
           else if (n1 > node->data && n2 > node-> data){
               node=node->right;
           }
           else {
               return node;
           }
        }
        return nullptr;
        }
};

int main(){
    BST bst;
    bst.insert(30);
    bst.insert(35);
    bst.insert(15);
    bst.insert(5);
    bst.insert(20);
    bst.insert(10);
    bst.insert(25);
   
    int n1;
    cout << "Enter an first number :" << endl;
    cin >> n1;
    int n2;
    cout << "Enter an second number :" << endl;
    cin >> n2;
    Node* lca= bst.findLCA(n1,n2);
    if (lca){
       std::cout<<"LCA of "<<n1<<" and "<<n2<<" is: "<<lca->data<<std::endl;
    }
    else{
        std::cout<<"LCA not found"<<std::endl;
    }
    return 0;
}