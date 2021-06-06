/* Generating first N numbers with given two digits in INCREASING ORDER */
#include<bits/stdc++.h>
using namespace std;

void printFirstN(string a, string b, int n)
{
    queue<string> q;
    q.push(a);
    q.push(b);
    for (int i=0; i<n; i++)
    {
        string curr = q.front();
        cout<< curr <<" ";
        q.pop();
        q.push(curr + a);
        q.push(curr + b);
    }
    
}
int main()
{
    string a, b;
    int firstN;
    cout<< "Enter First Digit: ";
    cin>> a;
    cout<< "Enter Second Digit: ";
    cin>> b;
    cout<< "Enter value of N: ";
    cin>> firstN;
    printFirstN(a, b, firstN);      
}