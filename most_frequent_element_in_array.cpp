/* Finding the most frequent element in the array. Naive solution take O(n^2) time, using two loops.
   Efficient solution take O(n) time using HASHING concept. */
#include<bits/stdc++.h>
using namespace std;

int mostFrequentNaive(int arr[], int n){
    int count[n] = {0};
    for(int i=0; i<n; i++){
        int x = arr[i];
        int freq=0;
        for(int j=0; j<n; j++){
            if(i == j)
                continue;
            if(x == arr[j])
                freq++;
        }
        count[i] = freq;
    }
    int max_index = 0, i;
    for(i=0; i<n; i++)
        if(count[max_index] < count[i])
            max_index = i;
    return arr[max_index];

}

int mostFrequentEfficient(int arr[], int n){
    map<int, int> hash;
    for(int i=0; i<n; i++)
        hash[arr[i]]++;
    
    int max_count = 0, res = -1;
    for (auto i : hash) {
        if (max_count < i.second) {
            res = i.first;
            max_count = i.second;
        }
    }
 
    return res;
}

int main(){
    int arr[] = {5,5,8,3,6,8,5,6,8,8,8,6,6};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<mostFrequentNaive(arr, n);
    cout<<endl;
    cout<<mostFrequentEfficient(arr, n);
}