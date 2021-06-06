#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int key;
        Node *next;

        Node(int data){
            key = data;
            next = NULL;
    }
};

int lengthSLL(Node *head){
    int count=0;
    while(head != NULL){
        count++;
        head = head -> next;
    }
    return count;
}

void printSLL(Node *head){
    while (head != NULL)
    {
        cout<<head -> key<<" "<<"-> ";
        head = head -> next;
    }   
}


void insertAtBegin(Node *&head, int d){
    // Inserting first node
    if(head == NULL){
        head = new Node(d);
        return;
    }

    // Inserting node at beginning, if there exist at least one node
    Node *temp = new Node(d);
    temp -> next = head;
    head = temp;
}

void insertAtTail(Node *&head, int d){
    // Handling case where this function call before insertAtBegin() for first node
    if(head == NULL){
        head = new Node(d);
        return;
    }
    // Assigning new nodes at tail of a given linked list that contains at least one node
    Node *tail = NULL;
    tail = head;
    while(tail -> next != NULL)
        tail = tail -> next;
    
    tail -> next = new Node(d);      
}

void insertAtMiddle(Node *&head, int d, int pos){
    // Handling case when we insert at position 1st
    if(head == NULL || pos == 0){
        head = new Node(d);
        return;
    }

    else if(pos > lengthSLL(head)){
        insertAtTail(head, d);
    }
    else{
        Node *temp = head;
        for(int i=1; i<=pos-1; i++)
            temp = temp -> next;
        Node *n = new Node(d);
        n -> next = temp -> next;
        temp -> next = n;
    }
}

void reverseList(Node *&head){
    if(head == NULL)
        return;
    else if(head -> next == NULL){
        printSLL(head);
        return;
    }
    else{
        Node *prev = NULL;    // Taking variables for tracking linked lists elements
        Node *temp = head, *curr = head;
        while(temp -> next != NULL){
            temp = temp -> next;   // Saving next node chain
            curr -> next = prev;   // Making current node point to previous
            prev = curr;           // Updating previous node one step up
            curr = temp;           // Updating current node one step up
        }
        temp -> next = prev;
        head = temp;
    }
}

int main(){
    Node *head = NULL;
    insertAtBegin(head, 1);
    insertAtBegin(head, 0);

    insertAtMiddle(head, 2, 3);
    insertAtMiddle(head, 3, 4);

    insertAtTail(head, 4);
    insertAtTail(head, 5);
    printSLL(head);
    cout<<endl;

    reverseList(head);
    printSLL(head);
    cout<<endl;

}