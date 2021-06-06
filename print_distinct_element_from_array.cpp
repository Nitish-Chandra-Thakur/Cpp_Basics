/* Printing distinct element from given array in any order for this we use unordered set, but printing in order as input given then also
   using unordered set with slight modification */
#include<bits/stdc++.h>
using namespace std;

void printDistinct(int arr[], int size)
{
    unordered_set<int> us;
    for (int i=0; i<size; i++)
    {
        us.insert(arr[i]);
    }
    for(auto x:us)
    {
        cout<< x << " ";
    }
}

void printDistinctInOrder(int arr[], int n)
{
    unordered_set<int> us;
    for (int i=0; i<n; i++)
    {
        if(us.find(arr[i]) == us.end())
        {
            cout<<arr[i]<<" ";
            us.insert(arr[i]);
        }
    }
    
}

int main()
{
    int arr[]={4,8,5,8,7,5};
    int arr1[]={2,2,2};
    int arr2[]={1,4,3,2,5};
    int size=sizeof(arr)/sizeof(arr[0]);
    int size1=sizeof(arr1)/sizeof(arr1[0]);
    int size2=sizeof(arr2)/sizeof(arr2[0]);
    printDistinct(arr, size);
    cout<<endl;
    printDistinct(arr1, size1);
    cout<<endl;
    printDistinct(arr2, size2);
    cout<<endl;
    printDistinctInOrder(arr, size);
    cout<<endl;
    printDistinctInOrder(arr1, size1);
    cout<<endl;
    printDistinctInOrder(arr2, size2);
    return 0;
}