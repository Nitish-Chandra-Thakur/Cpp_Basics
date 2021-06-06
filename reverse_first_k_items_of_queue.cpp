#include<bits/stdc++.h>
using namespace std;

int reverseFirstK(queue<int> q, int k)
{
    stack<int> s;
    for (int i=0; i<k; i++)
    {
        int n = q.front();
        q.pop();
        s.push(n);
    }
    for (int i=0; i<k; i++)
    {
        cout<<s.top()<<" ";
        s.pop();
    } 
    for (int i=0; i<2; i++)
    {
        cout<<q.front()<<" ";
        q.pop();
    }    

    return 0;
}

int main()
{
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    int k;
    cout<<"Enter K value: ";
    cin>> k;
    reverseFirstK(q, k);
    return 0;
}

