#include<bits/stdc++.h>
using namespace std;

int main(){
    int arr[] = {5, 8, 10, 12, 15};
    int n = sizeof(arr)/ sizeof(arr[0]);
    int temp, d;
    cin>>d;
    // Method - 1
    // for(int i=0; i<d; i++)
    // {
    //     temp = arr[0];
    //     int j = 1;
    //     arr[0] = arr[j];
    //     while(j < n)
    //     {
    //         j++;
    //         arr[j-1] = arr[j];
    //     }
    //     arr[n-1] = temp;
    // }
    // for(int i=0; i<n; i++)
    // {
    //     cout<<arr[i]<<" ";
    // }
    // cout<<endl;
    // cout<<endl;

    // Method -2 
    reverse(arr, arr+d);
    reverse(arr+d, arr+n);
    reverse(arr, arr+n);
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }

}