/* Finding the number of element in the given array that is greater than the required array element, so using NAIVE 
solution time complexity is O(n^2), but efficient solution take O(nlogn) time as building a map from n items of an array 
take maximum  of O(nlogn) time. */
#include<bits/stdc++.h>
using namespace std;

int countGreaterNaive(int arr[], int size)
{
    for (int i=0; i<size; i++)
    {
        int count=0;
        for(int j=0; j<size; j++)
        {
            if(arr[i] < arr[j])
                count++;
        }
        cout<<count<<" ";
    }
    return 0;
}

void countGreaterEfficient(int arr[], int size)
{
    map<int,int> m;
    for(int i=0;i<size;i++)
        m[arr[i]]++;
    int cum_freq = 0;
    for(auto it=m.rbegin(); it != m.rend();it++)
    {
        int freq = it -> second;
        it -> second = cum_freq;
        cum_freq += freq;
    }
    for(int i=0;i<size;i++)
        cout<<m[arr[i]]<<" ";
}

int main()
{
    int arr[]={10,5,8,20,30,8};
    int size=sizeof(arr)/sizeof(arr[0]);
    int arr1[]={50,4,8,10};
    int size1=sizeof(arr1)/sizeof(arr1[0]);
    int arr2[]={8,10,2,20};
    int size2=sizeof(arr2)/sizeof(arr2[0]);

    countGreaterNaive(arr, size);
    cout<<endl;
    countGreaterNaive(arr1, size1);
    cout<<endl;
    countGreaterNaive(arr2, size2);
    cout<<endl;
    cout<<endl;

    countGreaterEfficient(arr, size);
    cout<<endl;
    countGreaterEfficient(arr1, size1);
    cout<<endl;
    countGreaterEfficient(arr2, size2);
    cout<<endl;

    

}