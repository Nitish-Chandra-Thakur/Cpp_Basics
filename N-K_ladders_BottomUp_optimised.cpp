#include<iostream>
#include<vector>
using namespace std;

int ladderBUOptimised(int n, int k){
    vector<int> dp(n+1, 0);
    dp[0] = dp[1] = 1;

    for(int i=2; i<=k; i++){
        dp[i] = 2*dp[i-1];
    }

    for(int i=k+1; i<=n; i++){
        dp[i] = 2*dp[i-1] - dp[i-k-1];
    }

    return dp[n];
}

int main(){
    int n,k;

    cin>>n>>k;

    cout<<ladderBUOptimised(n,k);

    return 0;
}