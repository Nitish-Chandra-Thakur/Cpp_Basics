/* Given a length of ROD and its selling prices for unit length of rod. We have to maximise the profit by
   cutting rod in such a way that we get more prices. Time complexity = O(n^2). */
#include<iostream>
#include<climits>
using namespace std;

int maxProfitDP(int *prices, int n){
    int dp[n+1];
    dp[0] = 0;

    for(int len=1; len<=n; len++){
        int ans = INT_MIN;
        for(int i=0; i<len; i++){
            int cut = i+1;
            int current_ans = prices[i] + dp[len - cut];
            ans = max(ans, current_ans);
        }
        // Computed the ans for dp[len]
        dp[len] = ans;
    }
    return dp[n];
}

int main(){
    int prices[] = {3,5,8,9,10,17,17,20};
    int n = sizeof(prices)/sizeof(int);

    cout<<maxProfitDP(prices, n);

    return 0;
}