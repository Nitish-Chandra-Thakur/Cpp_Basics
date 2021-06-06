/* Counting SET bit of a given number. As Naive solution take O(n) time. But using Brian Karinghan
   algorithm time complexity is O(no._of_set_bits). */
#include<bits/stdc++.h>
using namespace std;

int countSetNaive(int n){
    int s = floor(log2(n));
    int x = s + 1;
    int arrbit[x];
    int i=1;
    while(n >= 1){
        if(n == 1){
            arrbit[x-i] = 1;
            n = n/2;
        }
        else{
            arrbit[x-i] = n%2;
            n = n/2;
        }
        i++;
    }
    for(int j=0; j<x; j++)
        cout<<arrbit[j]<<" ";
    cout<<endl;
    int count = 0;
    for(int i=0; i<x; i++){
        if(arrbit[i] == 1)
            count++;
    }
    return count;
}

int countSetBit(int n){
    int res=0;
    while(n>0){
        n = (n & (n-1));
        res++;
    }
    return res;
}

int main(){
    int n;
    cin>>n;
    cout<<countSetNaive(n);
    cout<<endl;
    cout<<countSetBit(n);

}