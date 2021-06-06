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
    while (head != NULL)
    {
        cout<<head -> key<<" -> ";
        head = head -> next;
    }  
}

// This function calculates the no. of nodes in the list
int lengthSLL(Node *head){
    int count=0;
    while(head != NULL){
        count++;
        head = head -> next;
    }
    cout<<count<<endl;
    return count;
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

// Taking element for Linked List nodes from user
Node* take_input(){
    int x, n;
    cin>>n;
    Node *head = NULL;
    for(int i=0; i<n-2; i++){
        cin>>x;
        insertAtBegin(head, x);
    }
    for(int i=n-2; i<n; i++){
        cin>>x;
        insertAtTail(head, x);
    }
    return head;
}

void findMiddle(Node *head){
    Node *slow = head, *fast = head->next;
    if(head == NULL)
        return;
    else if(head -> next == NULL || head->next->next == NULL){
        cout<<"Middle element is: "<<head->key<<endl;
        return;
    }
    else{
        while(fast != NULL && fast->next != NULL){
            fast = fast->next->next;
            slow = slow->next;
        }
        cout<<"Middle element is: "<<slow->key<<endl;
    }
}

int main(){
    Node *head = take_input();
    printSLL(head);
    cout<<endl;
    lengthSLL(head);
    findMiddle(head);

}