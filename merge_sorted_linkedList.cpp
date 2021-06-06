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

void insertAtHead(Node *&head, int d){
    if(head == NULL){
        head = new Node(d);
        return;
    }
    Node *temp = new Node(d);
    temp -> next = head;
    head = temp;
}

void insertAtTail(Node *&head, int d){
    if(head == NULL){
        head = new Node(d);
        return;
    }
    Node *tail = head;
    while(tail -> next != NULL)
        tail = tail -> next;
    Node *temp = new Node(d);
    tail -> next = temp;
    temp -> next = NULL;
}

void printSLL(Node *head){
    while(head != NULL){
        cout<<head -> key<<" -> ";
        head = head -> next;
    }
}

Node* take_input(){
    int n, data;
    cin>>n;
    Node *head = NULL;
    for(int i=0; i<n; i++){
        cin>>data;
        insertAtTail(head, data);
    }
    return head;
}

Node* mergeLinkedList(Node *headA, Node *headB){
    if(headA == NULL)
        return headB;
    if(headB == NULL)
        return headA;

    Node *temp;
    if(headA -> key < headB -> key){
        temp = headA;
        temp -> next = mergeLinkedList(headA->next, headB);
    }
    else{
        temp = headB;
        temp -> next = mergeLinkedList(headA, headB->next);
    }
    return temp;
}

int main(){
    Node *headA = take_input();
    Node *headB = take_input();

    printSLL(headA);
    cout<<endl;
    printSLL(headB);
    cout<<endl;

    Node *merge_List = mergeLinkedList(headA, headB);
    printSLL(merge_List);
}