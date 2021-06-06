#include<bits/stdc++.h>
using namespace std;

string returnDigits(const string &str)
{
    int pos = str.find('.');
    if(pos == string::npos)
        return "";
    else
        return str.substr(pos+1);
    
}
int main()
{
    string str = "12.5318";
    cout<<returnDigits(str);
}