#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> v;
    int k;
    cout<< "Enter the number of element to be inserted: ";
    cin>> k;
    for (int i = 0; i < k; i++)
    {
       v.push_back(i);
    }
    for(int x:v)
    {
        cout<< x <<" ";
    }
}