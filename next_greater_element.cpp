/* Given an array of integers, finding NEXT GREATER(position-wise closest and on right side) for every array element */

#include<bits/stdc++.h>
using namespace std;

void nextGreaterNaive(int arr[], int size)
{
    for(int i=0;i<size;i++)
    {
        int j;
        for (j=i+1; j<size; j++)
        {
            if(arr[i]<=arr[j])
            {
                cout<<arr[j]<<" ";
                break;
            }
        } 
        if(j==size)
        {
            cout<<-1<<" ";
        }
    }
}

void nextGreaterEfficient(int arr[], int size)
{
    stack<int>stk;
    stk.push(arr[size-1]);
    cout<< -1 <<" ";
    for(int i=size-2;i>=0;i--)
    {
        while(!stk.empty() && stk.top() <= arr[i])
        {
            stk.pop();
        }
        int prevgreater = (stk.empty()) ? -1:stk.top();
        cout<<prevgreater<<" ";
        stk.push(arr[i]);
    }
    
}
int main()
{
    int arr[]={5,15,10,8,6,12,9,18};
    int arr1[]={10,12,23,25,35};
    int arr2[]={43,37,29,23,19,11,7};
    int size=sizeof(arr)/sizeof(arr[0]);
    int size1=sizeof(arr1)/sizeof(arr1[0]);
    int size2=sizeof(arr2)/sizeof(arr2[0]);
    nextGreaterNaive(arr, size);
    cout<<endl;
    nextGreaterNaive(arr1, size1);
    cout<<endl;
    nextGreaterNaive(arr2, size2);
    cout<<endl;
    nextGreaterEfficient(arr, size);
}