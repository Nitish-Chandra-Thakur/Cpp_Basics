#include<bits/stdc++.h>
using namespace std;

int main(){
    unordered_map<char, int> mp;
    char ch = 'a';
    for(int i=0; i<26; i++){
        mp[ch] = 3;
        ch++;
    }

    for(auto m : mp){
        cout<<m.first<<" "<<m.second<<endl;
    }
    return 0;
}