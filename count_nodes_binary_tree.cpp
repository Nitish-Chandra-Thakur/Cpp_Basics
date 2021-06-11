#include<iostream>
using namespace std;
int cnt = 0;

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

int printPreorder(Node *root){
    if(root == NULL)
        return 0;
    cnt++;
    printPreorder(root->left);
    printPreorder(root->right);
    return cnt;
}

int main(){
    Node *root = buildTree();
    cout<<printPreorder(root)<<endl;
    return 0;
}