#include<bits/stdc++.h>
using namespace std;

void lstelement(int *arr, int n, int k)
{
    int arr1[n];
    static int j = 0;
    for (int i=0; i<n; i++)
    {
        if(arr[i]<k)
        {
            arr1[j] = arr[i];
            j++;
        }
    }
    for(int m=0;m<j;m++)
        cout<<arr1[m]<<" ";
}

// OTHER METHOD
vector<int> getsmaller(int *arr, int size, int k)
{
    vector<int> res;
    for (int i = 0; i < size; i++)
    {
        if(arr[i] < k)
        {
            res.push_back(arr[i]);
        }
    }   
    return res;
}

int main()
{
    int arr[] = {100,20,40,60,80,200};
    int size = sizeof(arr)/sizeof(arr[0]);
    int k;
    cout<< "Enter an element that is less than: ";
    cin>> k;
    lstelement(arr, size, k);
    cout << endl;
    vector<int> res = getsmaller(arr, size, k);
    for(int x:res)
        cout<< x << " ";
}