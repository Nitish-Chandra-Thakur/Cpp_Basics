/* Pattern searching problem, given a text and pattern we have to find all occurrences of pattern in the 
   given text. Naive solution take O(n*(n-m)) time.  */
#include<bits/stdc++.h>
using namespace std;

int patterSearch(string str, string pat)
{
    int position = str.find(pat);
    while(position != string::npos)
    {
        cout<< position<<" ";
        position = str.find(pat, position+1);
    }
    return 0;
}

int main()
{
    string txt = "abcd pqcda";
    string pat = "cd";
    patterSearch(txt, pat);
    cout<< endl;

    string txt1 = "aaaaa";
    string pat1 = "aaa";
    patterSearch(txt1, pat1);
}