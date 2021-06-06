#include<bits/stdc++.h>
using namespace std;
int main()
{
    int arr[] = {10, 21, 3, 59, 31, 52, 1, 8, 57, 97};
    int n = sizeof(arr)/sizeof(arr[0]);
    sort(arr, arr+10);
    cout<< "Sorted array is: ";
    for(int i=0; i<n; i++)
    {
        cout<< arr[i] << " ";
    }3
    cout<<endl;
    int k;
    cout<< "Enter kth element for Maximum and Minimum is: ";
    cin >> k;
    cout<< "kth maximum is: "<<arr[n-k]<<endl;
    cout<< "minimum is: "<<arr[k-1]<<endl;
    return 0;
}