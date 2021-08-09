/* This is the Bottom Up approach code for finding number of ways in the ladder problem. 
    Time complexity = O(N*K) and space complexity = O(N) */
#include<iostream>
#include<vector>
using namespace std;

int ladder(int n, int k){
    vector<int> dp(n+1, 0);
    dp[0] = 1;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=k; j++){
            if(i-j >= 0)
                dp[i] += dp[i-j]; 
        }
    }
    return dp[n];
}

int main(){
    int n, k;
    cin>>n>>k;
    cout<<ladder(n, k);

    return 0;

}