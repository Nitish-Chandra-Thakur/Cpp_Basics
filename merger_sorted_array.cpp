#include<bits/stdc++.h>
using namespace std;

int main(){
    int arr1[] = {5,8,9};
    int m = sizeof(arr1)/sizeof(arr1[0]);
    int arr2[] = {4,7,8};
    int n = sizeof(arr2)/sizeof(arr2[0]);

    int mergearr[m+n];
    int i=0, j=0, k=0;
    while(i < m && j < n){
        if(arr1[i] < arr2[j])
            mergearr[k++] = arr1[i++];
        else
            mergearr[k++] = arr2[j++];
        }
        while (i<m)
            mergearr[k++] = arr1[i++];
        while (j<n)
            mergearr[k++] = arr2[j++];
        
    for(int k=0; k<m+n; k++)
        cout<<mergearr[k]<<" ";
}