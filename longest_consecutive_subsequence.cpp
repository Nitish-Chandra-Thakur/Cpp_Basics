/* We have to find the longest consecutive subsequence from given array, for NAIVE solution time comlexity is O(nlogn), and 
    for efficient solution time comlexity is O(n) */
#include<bits/stdc++.h>
using namespace std;

int getLongestNaive(int arr[], int size)
{
    int count=1, res=1;
    sort(arr, arr+size);            //This take O(nlogn) time complexity
    for(int i=1;i<size;i++)
    {
        if(arr[i] - arr[i-1] == 1)
        {
            count++;
        }
        else
        {
            res=max(res, count);
            count = 1;
        }
    }
    res=max(res, count);
    cout<< res;
    return 0;
}

int getLongestEfficient(int arr[], int size)
{
    set<int> s;
    int count=1, res=1;
    for (int i=0; i<size; i++)
    {
        s.insert(arr[i]);               //This take O(n) time complexity
    }
    auto it = s.begin();
    while(it != s.end())
    {
        auto it1 = next(it,1);
        if((*it1) - (*it) == 1)
        {
            count++;
        }
        else
        {
            res=max(res, count);
            count=1;
        }
        it++;
    }
    cout<< res;
    return 0;
}

int main()
{
    int arr[]={1,9,3,2,4,20,21,22,23,24,25,26,27,28};
    int size=sizeof(arr)/sizeof(arr[0]);

    getLongestEfficient(arr, size);
    cout<<endl;
    getLongestNaive(arr, size);
    
}