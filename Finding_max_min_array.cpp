#include<bits/stdc++.h>
using namespace std;

int main()
{
    int arr[] = {10, 20, 2, 27, 13, 35, 1, 59, 21};
    int n = sizeof(arr)/sizeof(arr[0]);
    int max = arr[0];
    int min = arr[0];
    for(int i = 0; i<n; i++)
    {
        if(max < arr[i])
            max = arr[i];
    }
    cout << "Maximum element in array is: "<< max << endl;

    for(int i = 0; i<n; i++)
    {
        if(min > arr[i])
            min = arr[i];
    }
    cout << "Minimum element in array is: "<< min << endl;

}