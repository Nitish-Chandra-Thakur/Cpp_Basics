/* Given an array of distint integers, find closest(position-wise) greater on left of every element.
   If there is no greater element on left then print -1 */

#include<bits/stdc++.h>
using namespace std;

void prevGreaterNaive(int arr[], int size)         //Time complexity is O(n^2)
{
    for (int i=0; i<size; i++)
    {
        int j;
        for (j=i-1; j>=0; j--)
        {
            if(arr[i]<arr[j])
            {
                cout<<arr[j]<<" ";
                break;
            }
        }
        if(j==-1)
        {
            cout<<"-1"<<" "; 
        }       
    }
}

void prevGreaterEfficient(int arr[], int size)
{
    stack<int> stk;
    stk.push(arr[0]);
    cout<< -1 <<" ";
    for(int i=1;i<size;i++)
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
    int arr[]={15,10,18,12,4,6,2,8};
    int size=sizeof(arr)/sizeof(arr[0]);
    prevGreaterNaive(arr, size);
    cout<<endl;
    prevGreaterEfficient(arr, size);
}
