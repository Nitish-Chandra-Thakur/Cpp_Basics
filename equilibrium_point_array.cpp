/* For given an array, we have to find Equilibrium point, that means at given index of array the sum before its
   indices is equal to sum after that indices. Naive solution take O(n^2) time. Efficient solution take O(n). */
#include<bits/stdc++.h>
using namespace std;

int getEquiEfficient(int arr[], int n){
    int sum = 0;
    for(int i=0; i<n; i++)
        sum += arr[i];
    int left_sum = 0;
    for(int i=0; i<n; i++){
        if(left_sum == sum - arr[i])
            return arr[i];
        left_sum += arr[i];
        sum -= arr[i]; 
    }
    return -1;
}

int getEquiNaive(int arr[], int n){
    for(int i=0; i<n; i++){
    int left_sum = 0, right_sum = 0;
    for(int j=0; j<i; j++)
        left_sum += arr[j];
    for(int k=i+1; k<n; k++)
        right_sum += arr[k];
    if(left_sum == right_sum)
        return arr[i];
    }
    return -1;
}

int main(){
    int arr[] = {3,4,8,-9,20,6};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<getEquiNaive(arr, n)<<" ";
    int arr1[] = {4, 2, -2};
    int n1 = sizeof(arr1)/sizeof(arr1[0]);
    cout<<getEquiNaive(arr1, n1)<<" ";
    int arr2[] = {4, 2, 2};
    int n2 = sizeof(arr2)/sizeof(arr2[0]);
    cout<<getEquiNaive(arr2, n2)<<endl;

    cout<<getEquiEfficient(arr, n)<<" ";
    cout<<getEquiEfficient(arr1, n1)<<" ";
    cout<<getEquiEfficient(arr2, n2)<<endl;
}