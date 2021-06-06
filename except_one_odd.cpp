#include<bits/stdc++.h>
using namespace std;

int main(){
    int arr[]={3,3,4,5,5,4,4};
    int n = sizeof(arr)/sizeof(arr[0]);
    int res = 0;
    for(int i=0; i<n; i++){
        res = res ^ arr[i];
    }
    cout<<res;
}