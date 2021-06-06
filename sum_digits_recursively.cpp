#include<bits/stdc++.h>
using namespace std;

//int sum = 0;
int digitSum(int n){
    int digit = n % 10;
    if(n < 10)
        return digit;
    //sum = sum + digit;
    return digit + digitSum(n/10);
}

int main(){
    int n;
    cin>>n;
    cout<<digitSum(n);
    //cout<<sum;
}