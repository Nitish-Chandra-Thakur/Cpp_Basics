#include<bits/stdc++.h>
using namespace std;

int main()
{
    string str = "Nitish Chandra thakur";
    cout<< "String before reversing is: "<< str<<endl;
    reverse(str.begin(), str.end());
    cout<< "String after reversing is: "<< str<<endl;

    return 0;
}