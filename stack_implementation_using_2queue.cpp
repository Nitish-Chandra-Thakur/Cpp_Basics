/* Implementing stack operation like push(), pop(), top(), empty() using two Queues. */
#include<bits/stdc++.h>
using namespace std;

class Stack{
    queue<int> q1;
    queue<int> q2;
public:
    void push(int data){
        q1.push(data);
    }

    void pop(){
        if(q1.empty())
            return;
        while(q1.size() > 1){
            int element = q1.front();
            q2.push(element);
            q1.pop();
        }
        q1.pop();

        swap(q1, q2);
    }

    int top(){
        while(q1.size() > 1){
            int element = q1.front();
            q2.push(element);
            q1.pop();
        }

        int element = q1.front();
        q1.pop();
        q2.push(element);

        swap(q1, q2);
        return element;
    }

    int size(){
        return q1.size() + q2.size();
    }

    bool empty(){
        return size()==0;
    }
};

int main(){
    Stack st;

    for(int i=5; i>=1; i--)
        st.push(i);

    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }

    return 0;
}