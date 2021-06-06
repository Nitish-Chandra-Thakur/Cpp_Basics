#include<iostream>
#include<stack>
using namespace std;

void insertAtBottom(stack<int> &s, int data){
    // Base case
    if(s.empty()){
        s.push(data);
        return;
    }
    int x = s.top();
    s.pop();
    insertAtBottom(s, data);
    s.push(x);
}

void reverseStackRec(stack<int> &s){
    // Base case
    if(s.empty())
        return;
    int x = s.top();
    s.pop();
    reverseStackRec(s);
    insertAtBottom(s, x);
}

int main(){
    stack<int> st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);

    reverseStackRec(st);
    while(!st.empty()){
        cout<<st.top()<<endl;
        st.pop();
    }

    return 0;
}