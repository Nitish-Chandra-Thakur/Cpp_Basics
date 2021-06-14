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

Node *insertInBST(Node *root, int d){
    if(root == NULL){
        return new Node(d);
    }
    if(d <= root->data){
        root->left = insertInBST(root->left, d);
    }
    else{
        root->right = insertInBST(root->right, d);
    }
    return root;
}

Node *build(){
    int d;
    cin>>d;
    Node *root = NULL;
    while(d != -1){
        root = insertInBST(root, d);
        cin>>d;
    }
    return root;
}

Node *deleteInBST(Node *root, int key){
    if(root == NULL){
        return NULL;
    }
    else if(key < root->data){
        root->left = deleteInBST(root->left, key);
        return root;
    }
    else if(key == root->data){
        // Found the NODE to delete
        // Case-1. Node with 0 child
        if(root->left == NULL && root->right == NULL){
            delete root;
            return NULL;
        }

        // Case-2. Node with 1 child
        // Root has 1 left child and no right child
        if(root->left != NULL && root->right == NULL){
            Node *temp = root->left;
            delete root;
            return temp;
        }
        // Root has 1 right child and no left child
        if(root->left == NULL && root->right != NULL){
            Node *temp = root->right;
            delete root;
            return temp;
        }

        // Case-3. Node with 2 children
        Node *replace = root->right;
        // Finding Inorder Successor in given BST
        while(replace->left != NULL){
            replace = replace->left;
        }
        root->data = replace->data;
        root->right = deleteInBST(root->right, replace->data);
        return root;
    }
    else{
        root->right = deleteInBST(root->right, key);
        return root;
    }
}

void inorder(Node *root){
    if(root == NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

int main(){
    Node *root = build();
    inorder(root);
    cout<<endl;

    int k;
    cin>>k;
    deleteInBST(root, k);
    inorder(root);
    cout<<endl;

    return 0;
}