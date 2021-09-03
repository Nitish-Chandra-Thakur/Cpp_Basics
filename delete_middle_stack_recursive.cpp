#include<iostream>
#include<stack>
#include<vector>
using namespace std;

void deleteMiddle(stack<int> &st, int mid){
    if(st.size() == 0)
        return;

    if(mid == 1){
        st.pop();
        return;
    }

    int tp = st.top();
    st.pop();
    deleteMiddle(st, mid-1);
    st.push(tp);
    return;
}

int main(){
    stack<int> st;
    for(int i=0; i<5; i++)
        st.push(i+1);
    int ns = st.size();
    int mid = ns/2 + 1;
    deleteMiddle(st, mid);
    for(int i=0; i<ns; i++){
        cout<<st.top()<<" ";
        st.pop();
    }
    return 0;
}