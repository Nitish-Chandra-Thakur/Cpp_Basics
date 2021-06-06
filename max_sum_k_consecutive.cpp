/* Finding maximum sum of 'k' consrcutive elements in an array, concept of Sliding Window Technique.
   Brute force give O(n^2) time. */ 
#include<bits/stdc++.h>
using namespace std;

void sumNaive(int arr[], int n, int k){
    int sumarr[n-k+1];
    for(int i=0; i<n; i++){
        int sum = 0;
        for(int j=i; j<k+i; j++){
            sum = sum + arr[j];
        }
        sumarr[i] = sum;
    }
    int max = sumarr[0];
    for(int i=1; i<n-k+1; i++)
    {
        if(sumarr[i] > max)
            max = sumarr[i];
    }
    cout<<max;
}

int main(){
    int arr[] = {5,2,-1,0,3};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k;
    cin>>k;
    cout<<"Maximum sum is: ";
    sumNaive(arr, n, k);
    
}