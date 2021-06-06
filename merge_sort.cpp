#include<bits/stdc++.h>
using namespace std;

void merge(int arr[], int l, int mid, int h){
    int m = mid-l+1;
    int n = h-mid;
    int L[m], R[n];
    for(int i=0; i<m; i++)
        L[i] = arr[l+i];
    for(int j=0; j<n; j++)
        R[j] = arr[mid+1+j];
    int i=0, j=0, k=l;
    while(i < m && j < n){
        if(L[i] < R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
        }
        while (i<m)
            arr[k++] = L[i++];
        while (j<n)
            arr[k++] = R[j++];
}

void mergeSort(int arr[], int l, int h){
    if(l<h){
        int mid = l + (h-l)/2;
        mergeSort(arr, l, mid);
        mergeSort(arr, mid+1, h);
        merge(arr, l, mid, h);
    }
}

void printArray(int arr[], int n){
    for(int i=0; i<n; i++)
        cout<<arr[i]<<" ";
}

int main(){
    int arr[] = {10,12,3,9,18,6,8,23,-8};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout<<"Array before sorting:"<<endl;
    printArray(arr, n);
    mergeSort(arr, 0, n-1);
    cout<<endl;
    cout<<"Array after sorting:"<<endl;
    printArray(arr, n);
}