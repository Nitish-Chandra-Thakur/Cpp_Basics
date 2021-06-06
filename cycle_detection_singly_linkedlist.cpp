#include<bits/stdc++.h>
using namespace std;

class Node{
    public: 
        int key;
        Node *next;
        Node(int d){
            key = d;
            next = NULL;
        }
};

void printSLL(Node *head){
    while(head != NULL){
        cout<<head->key<<" -> ";
        head = head->next;
    }
}

void insertAtTail(Node *&head, int d){
    if(head == NULL){
        head = new Node(d);
        return;
    }
    Node *tail = head;
    while(tail -> next != NULL)
        tail = tail->next;
    tail -> next = new Node(d);
}

Node* take_input(){
    int n, d;
    cin>>n;
    Node *head = NULL;
    for(int i=0; i<n; i++){
        cin>>d;
        insertAtTail(head, d);
    }
    return head;
}

bool detectCycle(Node *head){
    Node *fast = head, *slow = head;
    while(fast != NULL && fast->next != NULL){
        fast = fast->next->next;
        slow = slow->next;

        if(fast == slow)
            return true;
    }
    return false;
}

int main(){
    Node *head = take_input();
    printSLL(head);
    cout<<endl;

    cout<<detectCycle(head);
    cout<<endl;
}