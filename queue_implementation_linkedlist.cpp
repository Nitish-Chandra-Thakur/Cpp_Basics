#include<bits/stdc++.h>
using namespace std;

class Queue{
    int curr_size;
    list<int> lq;

public:
    Queue(){
        curr_size = 0;
    }

    bool isEmpty(){
        return curr_size == 0;
    }

    void push(int data){
        lq.push_back(data);
        curr_size++;
    }

    void pop(){
        if(!isEmpty()){
            curr_size--;
            lq.pop_front();
        }
    }

    int front(){
        return lq.front();
    }
    
};

int main(){
    Queue q;
    for(int i=0; i<8; i++)
        q.push(i);

    q.pop();
    q.pop();
    cout<<q.front()<<endl;
    q.push(100);
    q.push(200);

    while(!q.isEmpty()){
        cout<<q.front()<<" ";
        q.pop();
    }
}