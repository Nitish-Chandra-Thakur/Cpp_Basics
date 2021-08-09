/* A simple brute force approach for finding the number of inversions required for sorting the given array.
   Time complexity = O(n^2) and space complexity = O(1) */
#include<iostream>
using namespace std;

int main(){
    int arr[] = {1,20,6,4,5};
    int n = sizeof(arr)/sizeof(int);

    int cnt = 0;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(arr[j] < arr[i])
                cnt++;
        }
    }

    cout<<cnt;
    return 0;
}