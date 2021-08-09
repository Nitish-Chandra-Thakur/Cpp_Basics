/* This is the Top Down approach code for finding number of ways in the ladder problem. 
    Time complexity = O(N*K) and space complexity = O(N) */
#include<iostream>
using namespace std;

int ladderTD(int n, int k, int *dp){
    if(n == 0)
        return 1;
    if(n < 0)
        return 0;
    int ans = 0;
    for(int i=1; i<=k; i++){
        ans += ladderTD(n-i, k, dp);
    }
    return dp[n] = ans;
    
}

int main(){
    int n,k;
    cin>>n>>k;

    int dp[10000] = {0};

    cout<<ladderTD(n, k, dp);

    return 0;
}