#include<bits/stdc++.h>
using namespace std;

bool isPangram(string str)
{
    int n = str.length();
    if(n<26)
        return false;
    
    bool visited[26] = {0};
    for(int i=0; i<n; i++)
    {
        char x = str[i];
        if(x >= 'a' && x <= 'z')
            visited[x - 'a'] = true;
        if(x >= 'A' && x <= 'Z')
            visited[x - 'A'] = true;
    }

    for (int i=0; i<26; i++)
    {
        if(visited[i] == false)
            return false;
    }
    return true;
    
}

int main()
{
    string str = "The quick brown fox jumps over the lazy dog";
    string str1 = "abc xyz pqr";
    cout<<isPangram(str);
    cout<<endl;
    cout<<isPangram(str1);

}