#include<iostream>
#include<stack>
using namespace std;

void insertEle(stack<int> &st, int val){
    if(st.size() == 0){
        st.push(val);
        return;
    }
    int temp = st.top();
    st.pop();
    insertEle(st, val);
    st.push(temp);
    return;
}

void reverseStack(stack<int> &st){
    if(st.size() == 0)
        return;
    int val = st.top();
    st.pop();
    insertEle(st, val);
}

int main(){
    stack<int> st;
    for(int i=1; i<10; i++)
        st.push(i);
    int ns = st.size();
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
    return 0;
}