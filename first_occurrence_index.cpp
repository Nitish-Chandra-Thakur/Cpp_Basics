#include<bits/stdc++.h>
using namespace std;

int firstOccurrence(int arr[], int l, int h, int x){
    if(l > h)
        return -1;
    int mid = (l+h)/2;
    if(arr[mid] == x && (mid == 0 || arr[mid-1] != x))
        return mid;
    else if(arr[mid] >= x)
        return firstOccurrence(arr, l, mid-1, x);
    else
        return firstOccurrence(arr, mid+1, h, x);

}

int main(){
    int arr[]={2,3,3,3,7};
    int n=sizeof(arr)/sizeof(arr[0]);
    int l=0, h=n-1;
    int x;
    //cout<<1/2;
    cin>>x;
    cout<<firstOccurrence(arr, l, h, x);
}