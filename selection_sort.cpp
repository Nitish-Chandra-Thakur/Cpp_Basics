#include<bits/stdc++.h>
using namespace std;

void swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

void selectionSort(int arr[], int n){
    for(int i=1; i<=n-1; i++){
        int max_index = 0;
        for(int j=1; j<=n-i; j++)
            if(arr[j] > arr[max_index])
                max_index = j;
        swap(&arr[max_index], &arr[n-i]);
    }
}

void printArray(int arr[], int n){
    for(int i=0; i<n; i++)
        cout<<arr[i]<<" ";
}

int main(){
    int arr[] = {20,10,5,15,25,13,10};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<"Array before sorting:"<<endl;
    printArray(arr, n);
    selectionSort(arr, n);
    cout<<endl;
    cout<<"Array after sorting:"<<endl;
    printArray(arr, n);

}