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

void deleteAtHead(Node *&head){
    if(head == NULL)
        return;
    
    Node *temp = head -> next;
    delete(head);
    head = temp;
}

void deleteAtTail(Node *&head){
    Node *tail = head;
    if(tail == NULL)
        return;
    else if(tail -> next == NULL)
        delete(tail);
    else{
        while(tail -> next -> next != NULL)
            tail = tail -> next;
    }
    Node *prev = tail -> next;
    delete(prev);
    tail -> next = NULL;
}

void deleteAtMiddle(Node *&head, int pos){
    if(head == NULL || pos == 1)
        return;
    else if(pos > lengthSLL(head))
        deleteAtTail(head);
    else{
        Node *temp = head;
        int x=1;
        while(x < pos-1){
            temp = temp -> next;
            x++;
        }
        Node *n = temp -> next;
        temp -> next = n -> next;
        delete(n);
    }
}

void searchLinear(Node *head, int element){
    Node *tail = head;
    while(tail ->next != NULL)
        tail = tail -> next;
    if(head == NULL)
        return;
    else if(head -> next == NULL){
        if(head -> key == element)
            cout<<"Element present"<<endl;
        else
            cout<<"Element is not present"<<endl;
    }
    else{
        while(head != NULL){
            if(element == head -> key){
                cout<<"Element Present"<<endl;
                return;
            }
            head = head -> next;
        }
    }
    cout<<"Element not present"<<endl;
}

void printSLL(Node *head){
    while (head != NULL)
    {
        cout<<head -> key<<" "<<"-> ";
        head = head -> next;
    }  
}
int main(){
    Node *head = NULL;
    insertAtBegin(head, 4);
    insertAtBegin(head, 2);
    insertAtBegin(head, 1);
    insertAtBegin(head, 0);
    printSLL(head);
    cout<<endl;

    insertAtTail(head, 5);
    printSLL(head);
    cout<<endl;

    insertAtMiddle(head, 3, 3);
    printSLL(head);
    cout<<endl;

    insertAtTail(head, 6);
    printSLL(head);
    cout<<endl;

    searchLinear(head, 6);

    deleteAtHead(head);
    printSLL(head);
    cout<<endl;

    deleteAtMiddle(head, 4);
    printSLL(head);
    cout<<endl;

    insertAtTail(head, 7);
    printSLL(head);
    cout<<endl;

    searchLinear(head, 5);
    searchLinear(head, 7);


    deleteAtTail(head);
    printSLL(head);
    cout<<endl;

    searchLinear(head, 7);
    searchLinear(head, 6);
    searchLinear(head, 10);
    searchLinear(head, 2);
}
