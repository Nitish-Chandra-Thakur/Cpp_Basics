/* This is the recursive code for finding number of ways. Time complexity = O(N^K) */
#include<iostream>
using namespace std;

int ladder(int n, int k){
    if(n == 0)
        return 1;
    if(n < 0)           // For handling where n < k;
        return 0;

    int ans = 0;
    for(int i=1; i<=k; i++){
        ans += ladder(n-i, k);
    }
    return ans;
}

int main(){
    int n, k;

    cin>>n>>k;

    cout<<ladder(n, k);

    return 0;


}