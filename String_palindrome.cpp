#include<bits/stdc++.h>
using namespace std;

int main()
{
    string str = "madam";
    int n = str.length();
    cout << "Total length of String is: "<< n << endl;
    for(int i=0; i<n/2; i++)
    {
        if(str[i] == str[n-i])
        {
            cout<< "given string is palindrome"<< " ";
        }
    }
}
