#include<iostream>
using namespace std;

bool isPalindrome(string s, int i, int j){
    if(i > j || i == j)
        return true;
    while(i < j){
        if(s[i] == s[j]){
            i++;
            j--;
        }
        else
            return false;
    }
    return true;
}

int main(){
    string s = "ababbbabbababa";
    int i=0, j=s.size()-1;

    if(isPalindrome(s, i, j)){
        cout<<"Given string is Palindrome";
    }
    else{
        cout<<"Given string is Not Palindrome";
    }
    return 0;
}