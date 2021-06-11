#include<iostream>
#include<queue>
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

Node *buildTree(){
    int d;
    cin>>d;
    if(d == -1)
        return NULL;
    Node *root = new Node(d);
    root->left = buildTree();
    root->right = buildTree();
    return root;
}

void BFS(Node *root){
    queue<Node*> q;
    q.push(root); 
    while(!q.empty()){
        Node *temp = q.front();
        cout<<temp->data<<" ";
        q.pop();
        if(temp->left)
            q.push(temp->left);

        if(temp->right)
            q.push(temp->right);
    }
    return;
}

int main(){
    Node *root = buildTree();
    BFS(root);
    return 0;
}