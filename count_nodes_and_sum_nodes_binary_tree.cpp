/* Finding number of nodes and sum of the node of a Binary Tree, time complexity is O(n) as it is taking
   only one traversal of Binary Tree that is either preorder, postorder and inorder. */
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

Node *builTree(){
    int d;
    cin>>d;
    if(d == -1)
        return NULL;
    Node *root = new Node(d);
    root->left = builTree();
    root->right = builTree();
    return root;
}

int count(Node *root){
    if(root == NULL)
        return 0;
    return 1 + count(root->left) + count(root->right);
}

int sum(Node *root){
    if(root == NULL)
        return 0;
    return root->data + sum(root->left) + sum(root->right);
}

int main(){
    Node *root = builTree();
    cout<<"Number of Nodes are: "<<count(root)<<endl;
    cout<<"Sum of Nodes are: "<<sum(root)<<endl;

    return 0;
}