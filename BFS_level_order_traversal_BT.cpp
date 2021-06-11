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

void BFS_LevelOrder(Node *root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty()){
        Node *t = q.front();
        if(t == NULL){
            cout<<endl;
            q.pop();
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout<<t->data<<" ";
            q.pop();
            if(t->left)
                q.push(t->left);
            if(t->right)
                q.push(t->right);
        }
    }
    return;
}

int main(){
    Node *root = buildTree();
    BFS_LevelOrder(root);

    return 0;

}