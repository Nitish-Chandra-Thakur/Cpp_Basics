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

Node *build(){
    //Read a list of number till -1 encounter, and insert these numbers to BST
    int d;
    cin>>d;

    Node *root = NULL;
    while(d != -1){
        root = insertInBST(root, d);
        cin>>d;
    }
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
    BFS(root);

    return 0;
}