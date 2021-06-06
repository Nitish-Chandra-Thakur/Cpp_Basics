#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int key;
        Node *next;

     //Constructor
        Node(int data){
        key = data;
        next = NULL;
    }
};

void insertAtBeginning(Node *&head, int data){
    if(head == NULL){
        head = new Node(data);
        return;
    }
    Node *temp = new Node(data);
    temp -> next = head;
    head = temp;
}

void printList(Node *&head){
    Node *temp = head;
    //temp = head;
    while(temp != NULL){
        cout<<temp -> key<<" "<<"-> ";
        temp = temp -> next;
    }
}

int main(){
    Node *head = NULL;
    insertAtBeginning(head, 5);
    insertAtBeginning(head, 10);
    insertAtBeginning(head, 15);
    insertAtBeginning(head, 20);
    printList(head);
    //cout<<endl;
}