#include<iostream>
#include<stack>
using namespace std;

void reverseStack(stack<int> &st, stack<int> &rev){
    if(st.size() == 0)
        return;
    int temp = st.top();
    st.pop();
    rev.push(temp);
    reverseStack(st, rev);
    return;
}

int main(){
    stack<int> st;
    for(int i=1; i<6; i++)
        st.push(i);
    int ns = st.size();
    stack<int> res;
    reverseStack(st, res);

    while(!res.empty()){
        cout<<res.top();
        res.pop();
    }
    return 0;
}