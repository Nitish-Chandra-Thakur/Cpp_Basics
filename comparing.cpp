#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s1, s2;
    cout<<"Enter first string: "<<
    cin>>s1;
    cout<<"Enter 2nd string: "<<
    cin>>s2;
    //int i=0, j=0;
    if(strcmp(s1, s2) == 0)
    {
        cout<< "same";
    }
    else
    {
        cout<<"string is not same";
    }
}