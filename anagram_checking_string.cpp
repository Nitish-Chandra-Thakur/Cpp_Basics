#include<bits/stdc++.h>
using namespace std;

bool isAnagramgNaive(string s1, string s2)
{
    int n1 = s1.length();
    int n2 = s2.length();
    
    if(n1 != n2)
        return false;
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());

    for(int i=0; i<n1; i++)
    {
        if(s1[i] != s2[i])
            return false;
    }
    return true;   
}

bool isAnagramEfficient(const string &s1, const string &s2)
{
    int n1 = s1.length();
    int n2 = s2.length();
    
    if(n1 != n2)
        return false;
    int count[256] = {0};
    for(int i=0; i<n1; i++)
        count[s1[i]]++;
    for(int i=0; i<n2; i++)
        count[s2[i]]--;
    for(int i=0; i<256; i++)
    {
        if(count[i] != 0)
            return false;
    }
    return true;
}

int main()
{
    string str1 = "listen";
    string str2 = "silent";

    cout<<isAnagramgNaive(str1, str2);
    cout<<endl;

    string str3 = "aabcbc";
    string str4 = "aabbbc";
    cout<<isAnagramEfficient(str3, str4);

}