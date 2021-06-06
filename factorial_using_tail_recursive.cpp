#include<bits/stdc++.h>
using namespace std;

// Method - 1
int fact1(int n){
    static int product = 1;
    if(n == 0)
        return 1;
    else{
        product = product * n;
        fact1(n-1);
    }
    return product;
}

// Method - 2
int fact2(int n, int val = 1){
    if( n == 0)
        return val;
    return fact2(n-1, val*n);
}

int main(){
    int n;
    cin>>n;
    cout<<fact1(n);
    cout<<endl;
    cout<<fact2(n);

}