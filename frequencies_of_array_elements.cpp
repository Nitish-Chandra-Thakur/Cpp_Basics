#include<bits/stdc++.h>
using namespace std;

int freqElement(int arr[], int size)
{
    unordered_map<int,int> um;
    for(int i=0;i<size;i++)
        um[arr[i]]++;
    
    for(auto x:um)
        cout<< x.first<<" "<<x.second<<endl;
    return 0;   
}
int main()
{
    int arr[]={10,5,20,5,10,5};
    int size=sizeof(arr)/sizeof(arr[0]);
    freqElement(arr, size);
}