/* For a given string we have to find the index of first non repeating character in the string. 
   Naive solution take O(n^2) time and O(n) space. Efficient solution take  O(n) time.  */
#include<bits/stdc++.h>
using namespace std;

int nonRepeatingNaive(string s, int n){
    int arr[n] = {0};
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(i == j)
                continue;
            if(s[i] == s[j])
                arr[i] = 1;
        }
    }
    for(int i=0; i<n; i++)
        if(arr[i] == 0)
            return i;
    return -1;
}

int nonRepeatingEfficient(string s, int n){
    int count[256] = {0};
    for(int i=0; i<n; i++)
        count[s[i]]++;
    for(int i=0; i<256; i++)
        if(count[s[i]] == 1)
            return i;
    return -1;
}

int main(){
    string s ="abcbacdeefghd";
    int n = s.length();
    int resn = nonRepeatingNaive(s,n);
    if(resn == -1)
        cout<<-1;
    else    
        cout<<s[resn];
    cout<<endl;
    int rese = nonRepeatingEfficient(s,n);
    if(rese == -1)
        cout<<-1;
    else    
        cout<<s[rese];

}