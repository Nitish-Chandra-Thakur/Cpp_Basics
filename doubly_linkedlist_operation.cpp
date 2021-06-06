#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int key;
        Node *next;
        Node *prev;

        Node(int d){
            key = d;
            next = NULL;
            prev = NULL;
        }
};

void printDLL(Node *head){
    while(head != NULL){
        cout<<head->key<<" -> ";
        head = head->next;
    }
}

int lengthDLL(Node *head){
    int count = 0;
    while(head != NULL){
        count++;
        head = head->next;
    }
    return count;
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
    temp->next = NULL;
    tail -> next = temp;
    temp -> prev = tail;
}

void insertAtHead(Node *&head, int d){
    if(head == NULL){
        head = new Node(d);
        return;
    }
    Node *temp = new Node(d);
    temp->next = head;
    head -> prev = temp;
    temp -> prev = NULL;
    head = temp;
}

void insertAtMiddle(Node *&head, int d, int pos){
    if(head == NULL || pos == 0){
        insertAtHead(head, d);
    }
    if(pos > lengthDLL(head))
        insertAtTail(head, d);

    Node *n = head;
    int x=1;
    while(x < pos-1){
        n = n -> next;
        x++;
    }
    Node *temp = new Node(d);
    temp->next = n->next;
    n->next->prev = temp;
    temp->prev = n;
    n->next = temp;
}

void deleteHead(Node *&head){
    Node *temp = head;
    head = head->next;
    head->prev = NULL;
    delete(temp);
}

void deleteNodeMiddle(Node *&head, int pos){
    int x = 1;
    Node *temp = head;
    if(head == NULL || head->next == NULL){
        delete(head);
        return;
    }
    while(x < pos-1){
        temp = temp->next;
        x++;
    }
    Node *n = temp->next;
    temp->next = temp->next->next;
    temp = n->next;
    temp->prev = n->prev;
    delete(n);
    
    
}

int main(){
    Node *head = NULL, *prev = NULL;
    // Inserting Nodes at the beginning of List
    insertAtHead(head, 4);
    insertAtHead(head, 3);
    insertAtHead(head, 2);
    insertAtHead(head, 1);
    cout<<"Printing nodes inserting at head are: "<<endl;
    printDLL(head);
    cout<<endl;
    cout<<lengthDLL(head);
    cout<<endl;

    insertAtMiddle(head, 10, 2);
    insertAtMiddle(head, 20, 3);
    insertAtMiddle(head, 30, 4);
    insertAtMiddle(head, 40, 5);
    cout<<"Printing nodes inserting at head and Middle are: "<<endl;
    printDLL(head);
    cout<<endl;
    cout<<lengthDLL(head);
    cout<<endl;

    insertAtTail(head, 5);
    insertAtTail(head, 6);
    insertAtTail(head, 7);
    insertAtTail(head, 8);
    cout<<"Printing nodes inserting at head and tail are: "<<endl;
    printDLL(head);
    cout<<endl;
    cout<<lengthDLL(head);
    cout<<endl;

    deleteNodeMiddle(head, 4);
    printDLL(head);
    cout<<endl;

    deleteHead(head);
    printDLL(head);
    cout<<endl;

    deleteNodeMiddle(head, 2);
    printDLL(head);
    cout<<endl;

    return 0;
}