#include<bits/stdc++.h>
using namespace std;

// Defining the structure of each node
class Node{
    public:
        int key;
        Node *next;
        Node(int d){
            key = d;
            next = NULL;
        }
};

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
    Node *tail = head;
    while(tail -> next != NULL)
        tail = tail -> next;
    
    tail -> next = new Node(d);      
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

// Function written for printing element of Linked List
void printSLL(Node *head){
    while(head != NULL){
        cout<<head -> key<<" -> ";
        head = head -> next;
    }
}

void kthNodeEnd_1(Node *head, int k){
    int count = 0;
    Node *temp = head;
    // Counting the no. of nodes in the given Linked List
    while(temp != NULL){
        count++;
        temp = temp -> next;
    }
    int pos = 1;
    // Taking nodes to required node from end of Linked List
    while(pos <= count-k){
        pos++;
        head = head -> next;
    }
    cout<<head -> key;      // Printing the reqired kth node from end of Linked List
}

void kthNodeEnd_2(Node *head, int k){
    Node *fast = head, *slow = head;
    for(int i=0; i<k; i++)
        fast = fast -> next;
    while(fast != NULL){
        fast = fast -> next;
        slow = slow -> next;
    }
    cout<<slow -> key;
}

int main(){
    Node *head = take_input();
    printSLL(head);
    cout<<endl;
    kthNodeEnd_1(head, 3);
    cout<<endl;
    kthNodeEnd_2(head, 3);

    cout<<endl;
    kthNodeEnd_1(head, 4);
    cout<<endl;
    kthNodeEnd_2(head, 4);

    cout<<endl;
    kthNodeEnd_1(head, 2);
    cout<<endl;
    kthNodeEnd_2(head, 2);
    
    
}