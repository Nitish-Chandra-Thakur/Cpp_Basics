#include<bits/stdc++.h>
using namespace std;

void swap(int *x, int *y){
    int *temp;
    temp = x;
    x = y;
    y = temp;

}

int main()
{
    int arr[] = {1,2,3,10,4};
    int n = sizeof(arr)/sizeof(arr[0]);
    reverse(arr, arr+n);            // Method - 1
    for (int i = 0; i <n ; i++)
    {
        cout<<arr[i]<< " ";
    }
    cout<<endl;

    // Method - 2
    int low = 0, high = n-1;
    while(low < high)
    {
        swap(&arr[low], &arr[high]);
        low++;
        high--;
    }
    for(int i=0; i<n; i++)
        cout<<arr[i]<<" ";
    
}