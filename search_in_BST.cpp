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

Node *insertInBST(Node *root, int data){
    if(root == NULL){
        return new Node(data);
    }
    if(data <= root->data){
        root->left = insertInBST(root->left, data);
    }
    else{
        root->right = insertInBST(root->right, data);
    }
    return root;
}

Node *buildBST(){
    int d;
    cin>>d;

    Node *root = NULL;
    while(d != -1){
        root = insertInBST(root, d);
        cin>>d;
    }
    return root;
}

bool searchInBST(Node *root, int key){
    if(root == NULL){
        return false;
    }
    if(root->data == key){
        return true;
    }
    if(key <= root->data){
        return searchInBST(root->left, key);
    }
    else{
        return searchInBST(root->right, key);
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
    Node *root = buildBST();
    inorder(root);
    cout<<endl;
    int key;
    cin>>key;
    if(searchInBST(root, key)){
        cout<<"Searched element is Present in the BST";
    }
    else{
        cout<<"Searched element is NOT Present in the BST";
    }
    cout<<endl;
    return 0;
}