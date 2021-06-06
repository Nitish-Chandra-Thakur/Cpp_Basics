#include<bits/stdc++.h>
using namespace std;

void insertionSort(int arr[], int n){
    int j;
    for(int i=0; i<n; i++){
        int key = arr[i];
        for(j=i-1; j>=0 && arr[j] > key; j--)
            arr[j+1] = arr[j];
        arr[j+1] = key;
    }
}

void printArray(int arr[], int n){
    for(int i=0; i<n; i++)
        cout<<arr[i]<<" ";
}

int main(){
    int arr[] = {10, 12, 7, 5, 15, 18, 9};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<"Array before sorting:"<<endl;
    printArray(arr, n);
    insertionSort(arr, n);
    cout<<endl;
    cout<<"Array after sorting:"<<endl;
    printArray(arr, n);

}