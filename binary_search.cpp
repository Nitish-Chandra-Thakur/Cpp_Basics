/* Binary Search algorithm implementation in both Iterative and Recursive way. Performance wise both are same.
   And time complexity is O(logn). */
#include<bits/stdc++.h>
using namespace std;

int binarySearchRecursive(int arr[], int l, int h, int x){
    if(l > h)
        return -1;
    int mid = (l+h)/2;
    if(arr[mid] == x)
        return mid;
    else if(arr[mid] > x)
        return binarySearchRecursive(arr, l, mid-1, x);
    else
        return binarySearchRecursive(arr, mid+1, h, x);
}

int binarySearchIterative(int arr[], int l, int h, int x){
    while(l <= h){
        int mid = (l+h)/2;
        if(arr[mid] == x)
            return mid;
        else if(arr[mid] > x)
            h = mid-1;
        else
            l = mid+1;
    }
    return -1;
}

int main(){
    int arr[] = {10, 12, 15, 19, 23, 27, 33};
    int n = sizeof(arr)/sizeof(arr[0]);
    int l=0;
    int h=n-1;
    int x;
    //cout<<n<<endl;
    cin>>x;
    cout<<binarySearchRecursive(arr,l,h,x);
    cout<<endl;
    cout<<binarySearchIterative(arr, l, h, x);
}