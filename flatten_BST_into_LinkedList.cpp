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

class LinkedList{
    public:
        Node *head;
        Node *tail;
};

LinkedList flatten(Node *root){
    LinkedList l;
    // Base case when ROOT become NULL
    if(root == NULL){
        l.head = l.tail = NULL;
        return l;
    }
    // When Node of Tree is leaf
    if(root->left == NULL && root->right == NULL){
        l.head = l.tail = root;
        return l;
    }
    // When left child exist but node have no right child
    if(root->left != NULL && root->right == NULL){
        LinkedList leftLL = flatten(root->left);
        leftLL.tail->right = root;

        l.head = leftLL.head;
        l.tail = root;
        return l;
    }
    // When right child exist but no left child of Node
    if(root->left == NULL && root->right != NULL){
        LinkedList rightLL = flatten(root->right);
        root->right = rightLL.head;

        l.head = root;
        l.tail = rightLL.tail;
        return l;
    }
    // When both child exist for a given Node
    LinkedList leftLL = flatten(root->left);
    LinkedList rightLL = flatten(root->right);
    leftLL.tail->right = root;
    root->right = rightLL.head;

    l.head = leftLL.head;
    l.tail = rightLL.tail;
    return l;
}

int main(){
    Node *root = buildBST();

    LinkedList l = flatten(root);
    Node *temp = l.head;

    while (temp != NULL){
        cout<<temp->data<<"-->";
        temp = temp->right;
    }
    
    return 0;
}