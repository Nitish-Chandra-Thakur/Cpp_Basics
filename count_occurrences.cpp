#include<bits/stdc++.h>
using namespace std;

int leftMost(int arr[], int l, int h, int x){
    if(l > h)
        return 0;
    int mid = (l+h)/2;
    if(arr[mid] == x && (mid == 0 || arr[mid-1] != x))
        return mid;
    else if(arr[mid] >= x)
        return leftMost(arr, l, mid-1, x);
    else
        return leftMost(arr, mid+1, h, x);
}

int rightMost(int arr[], int l, int h, int x, int n){
    if(l > h)
        return -1;
    int mid = (l+h)/2;
    if(arr[mid] == x && (mid == n-1 || arr[mid+1] != x))
        return mid;
    else if(arr[mid] > x)
        return rightMost(arr, l, mid-1, x, n);
    else
        return rightMost(arr, mid+1, h, x, n);
}

int main(){
    int arr[] = {2,3,3,3,3};
    int n = sizeof(arr)/sizeof(arr[0]);
    int l=0, h=n-1, x;
    cin>>x;
    int rmost = rightMost(arr, l, h, x, n);
    int lmost = leftMost(arr, l, h, x);
    cout<<leftMost(arr, l, h, x)<<endl;
    cout<<rightMost(arr, l, h, x, n)<<endl;
    cout<<"Occurence of "<<x<<" is "<<rmost+1-lmost;
}