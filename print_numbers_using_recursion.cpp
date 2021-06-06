#include<bits/stdc++.h>
using namespace std;

// Printing from n to 1
void printNumbers1(int n){
    if(n < 1);
    else
    {
        cout<<n<<" ";
        printNumbers1(n-1);
    }
}

// Printing from 1 to n
void printNumbers2(int n){
    if(n < 1);
    else
    {
        printNumbers2(n-1);
        cout<<n<<" ";
    }
}

int main(){
    int n;
    cin>>n;
    printNumbers1(n);
    cout<<endl;
    printNumbers2(n);
    return 0;
}