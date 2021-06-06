/* Finding LEADERS in array, means finding that elements that have no greater element on its right side.
   Naive solution take O(n^2) time. Efficient take O(n) time.  */
#include<bits/stdc++.h>
using namespace std;
void leadersNaive(int arr[], int n){
    for(int i=0; i<n; i++)
    {
        int j = i+1;
        while(j < n)
        {
            if(arr[i] > arr[j])
                j++;
            else    
                break;
        }
        if(j == n)
            cout<<arr[i]<<" ";
    }
}

void leadersEfficient(int arr[], int n){
    int max = arr[n-1];
    for (int i = n-1; i >= 0; i--)
    {
        if(i == n-1)
            cout<<max<<" ";
        else if(max < arr[i]){
            max = arr[i];
            cout<<arr[i]<<" ";
        }
        else;
    }
}

int main(){
    int arr[] = {5,3,20,15,8,3};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<"Leaders are: "<<endl;
    leadersNaive(arr, n);
    cout<<endl;
    leadersEfficient(arr, n);
    return 0;
}