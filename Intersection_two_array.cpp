#include<bits/stdc++.h>
using namespace std;

int main()
{
    int arr1[] = {10,5,15,20,30,40,99,12,77};
    int arr2[] = {20,30,10,50,70,77};
    int m = sizeof(arr1)/sizeof(arr1[0]);
    int n = sizeof(arr2)/sizeof(arr2[0]);
    cout<< "Common values or intersected values in both array are: ";
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(arr1[i] == arr2[j])
            {
                cout<< arr1[i]<<" ";
                break;
            }
        }
    }
}
