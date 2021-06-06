#include<bits/stdc++.h>
using namespace std;

void swap(int *x, int *y){
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

int partitions(int arr[], int low, int high){
    int pivot = arr[high];
    int i = low-1;
    for(int j=low; j<=high-1; j++){
        if(arr[j] <= pivot){
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i+1], &arr[high]);
    return (i+1);
}

void quickSort(int arr[], int low, int high){
    if(low < high)
    {
        int x = partitions(arr, low, high);
        quickSort(arr, low, x-1);
        quickSort(arr, x+1, high);
    }
}

void printArray(int arr[], int n){
    for(int i=0; i<n; i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}

int main(){
    int arr[] = {1,3,8,9,4,6,5};
    int n = sizeof(arr)/sizeof(arr[0]);
    quickSort(arr, 0, n-1);
    cout<<"sorted array is: "<<endl;
    printArray(arr, n);

}