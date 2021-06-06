/* Printing the REPEATED element from a given ARRAY, with naive solution the time complexity is O(n^2), but when we use
    unordered set then time compexity is O(n)*/
#include<bits/stdc++.h>
using namespace std;

void printRepeatedNaive(int arr[], int n)
{
    for (int i=0; i<n; i++)
    {
        for (int j=i+1; j<n; j++)
        {
            if(arr[i]==arr[j])
            {
                cout<<arr[i]<<" ";
                break;
            }
        }   
    }   
}

void printRepeatedEfficient(int arr[], int n)
{
    unordered_set<int> us;
    for (int i=0; i<n; i++)
    {
        if(us.find(arr[i]) == us.end())
            us.insert(arr[i]);
        else
            cout<<arr[i]<<" ";
    }
    
}

int main()
{
    int arr[]={10,8,10,7,7,6};
    int size=sizeof(arr)/sizeof(arr[0]);
    int arr1[]={10,20,10,10,10};
    int size1=sizeof(arr1)/sizeof(arr1[0]);
    int arr2[]={10,20,30};
    int size2=sizeof(arr2)/sizeof(arr2[0]);
    int arr3[]={2,2,2,2};
    int size3=sizeof(arr3)/sizeof(arr3[0]);
    printRepeatedNaive(arr, size);
    cout<<endl;
    printRepeatedNaive(arr1, size1);
    cout<<endl;
    printRepeatedNaive(arr2, size2);
    cout<<endl;
    printRepeatedNaive(arr3, size3);
    cout<<endl;

    printRepeatedEfficient(arr, size);
    cout<<endl;
    printRepeatedEfficient(arr1, size1);
    cout<<endl;
    printRepeatedEfficient(arr2, size2);
    cout<<endl;
    printRepeatedEfficient(arr3, size3);
    cout<<endl;
}