#include<bits/stdc++.h>
using namespace std;

int twoSums(int arr[], int size, int target)
{
    int ind1, ind2;
    for(int i=0; i<size; i++)
    {
        if(arr[i] <= target)
        {
            ind1 = i;
            target = target - arr[i];
            
        }
    }
}

int main()
{
    int size;
    cin>>size;
    int arr[size];
    for (int i=0; i<size; i++)
    {
        cin>>arr[i] ;
    }
    int target;
    cin>>target;
    twoSums(arr, size, target);
    return 0;
}