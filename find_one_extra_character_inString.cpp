#include<bits/stdc++.h>
using namespace std;

int extraCharNaive(string str1, string str2)
{
    sort(str1.begin(), str1.end());
    sort(str2.begin(), str2.end());

    int n = str1.length();
    for(int i=0; i<n; i++)
        if(str1[i] != str2[i])
            return str2[i];
    return str2[n];
}

int main()
{
    string str1 = "abcd";
    string str2 = "aecbd";
    cout<<char(extraCharNaive(str1, str2));
}