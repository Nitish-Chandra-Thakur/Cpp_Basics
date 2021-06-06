#include<bits/stdc++.h>
using namespace std;

int firstRepeatingNaive(string s, int n){
    for(int i=0; i<n; i++){
        char ch = s[i];
        for(int j=0; j<n; j++){
            if(i == j)
                continue;
            if(ch == s[j])
                return i;
        }
    }
    return -1;
}

int firstRepeatingEfficient(string s, int n){
    int res = INT_MAX;
    int count[256] = {-1};
    for(int i=0; i<n; i++){
        if(count[s[i]] == -1)
            count[s[i]] = i;
        else
            res = min(res, count[s[i]]);
    //return res;
    }
    return res;
}

int main() {
    string s = "abcbc";
    //string t = "listen";
    int n = s.length();
    cout<<firstRepeatingNaive(s, n);
    cout<<endl;
    cout<<firstRepeatingEfficient(s, n);
}