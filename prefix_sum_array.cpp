#include<bits/stdc++.h>
using namespace std;

int getsumNaive(int arr[], int l, int r){
    int sum = 0;
    for(int i=l; i<=r; i++)
        sum = sum + arr[i];
    return sum;
}

int getsumEfficient(int prefix_sum[], int l, int r){
    if(l != 0)
        return prefix_sum[r] - prefix_sum[l-1];
    else
        return prefix_sum[r];
}

int main(){
    int arr[] = {2,8,3,9,6,5,4};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<getsumNaive(arr, 0, 2)<<endl;   
    cout<<getsumNaive(arr, 1, 3)<<endl;
    cout<<getsumNaive(arr, 2, 6)<<endl;
    cout<<endl;
    int prefix_sum[n];
    prefix_sum[0] = arr[0];
    for(int i=1; i<n; i++)
        prefix_sum[i] = prefix_sum[i-1] + arr[i];
    cout<<getsumNaive(arr, 0, 2)<<endl;   
    cout<<getsumNaive(arr, 1, 3)<<endl;
    cout<<getsumNaive(arr, 2, 6)<<endl;
    
}