#include<bits/stdc++.h>
using namespace std;

void reverseOrder(string s)
{
    stack<char> snew;
    for(int i=0; i<s.size();i++)
    {
        snew.push(s[i]);
    }
    while (!snew.empty())
    {
        cout<<snew.top();
        snew.pop();
    }
    
}
int main()
{
    string s="Nitish";
    reverseOrder(s);

}