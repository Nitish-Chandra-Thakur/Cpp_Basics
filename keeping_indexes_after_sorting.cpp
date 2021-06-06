#include<bits/stdc++.h>
using namespace std;

void aftersorting(int *arr, int size)
{
    sort(arr, arr+size);
    for (int i = 0; i < size; i++)
    {
        cout<< arr[i]<<" ";
    }
    
}
int main()
{
    int arr[] = {20,40,30,10};
    int n = sizeof(arr)/sizeof(arr[0]);
    aftersorting(arr, n);
}