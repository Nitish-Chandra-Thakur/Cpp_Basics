#include<iostream>
#include<stack>
using namespace std;

void transfer(stack<int> &s1, stack<int> &s2, int n){
    for(int i=0; i<n; i++){
        s2.push(s1.top());
        s1.pop();
    }
}

void reverseStack(stack<int> &s){
    stack<int> dummy;
    int n = s.size();
    for(int i=0; i<n; i++){
        int x = s.top();
        s.pop();

        transfer(s, dummy, n-i-1);

        s.push(x);

        transfer(dummy, s, n-i-1);
    }
}

int main(){
    stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
  
    reverseStack(s);
    while(!s.empty()){
        cout<<s.top()<<endl;
        s.pop();
    }
}