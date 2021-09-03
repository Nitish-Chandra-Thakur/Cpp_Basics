#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;

void insert(stack<int> &st, int temp){
    if(st.size() == 0 || st.top() <=  temp){
        st.push(temp);
        return;
    }
    
    int val = st.top();
    st.pop();
    insert(st, temp);
    st.push(val);

    return;
}

void sorting(stack<int> &st){
    if(st.size() == 1)
        return;
    int temp = st.top();
    st.pop();
    sorting(st);
    insert(st, temp);
    //arr.push_back(temp);

    return;
}

int main(){
    vector<int> arr = {2,3,7,6,4,9,5};
    stack<int> st;
    int n = arr.size();
    for(int i=0; i<n; i++)
        st.push(arr[i]);
    sorting(st);
    for(int i=0; i<n; i++){
        cout<<st.top();
        st.pop();
    }
    return 0;
}