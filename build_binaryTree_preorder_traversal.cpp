/* Building and printing Binary Tree in PREORDER, POSTORDER and INORDER way . Here, -1 in input 
   representing its child node is not exist. And the nodes value stored as ROOT-LEFT-RIGHT nodes
   value, i.e. PREORDER */
#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node *left;
        Node *right;

        Node(int d){
            data = d;
            left = NULL;
            right = NULL;
        }
};

Node* buildTree(){
    int d;
    cin>>d;
    if(d == -1)
        return NULL;

    Node *root = new Node(d);
    root->left = buildTree();
    root->right = buildTree();
    return root;
}

void printPreorder(Node *root){
    if(root == NULL)
        return;
    cout<<root->data<<" ";
    printPreorder(root->left);
    printPreorder(root->right);
}

void printPostorder(Node *root){
    if(root == NULL)
        return;
    
    printPostorder(root->left);
    cout<<root->data<<" ";
    printPostorder(root->right);
}

void printInorder(Node *root){
    if(root == NULL)
        return;
    
    printInorder(root->left);
    printInorder(root->right);
    cout<<root->data<<" ";
}

int main(){
    Node *root = buildTree();
    cout<<"PREORDER TRAVERSL is: ";
    printPreorder(root);
    cout<<endl;
    cout<<"INORDER TRAVERSL is: ";
    printPostorder(root);
    cout<<endl;
    cout<<"POSTORDER TRAVERSL is: ";
    printInorder(root);
    cout<<endl;

    return 0;
}