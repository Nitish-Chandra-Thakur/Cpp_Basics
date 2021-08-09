#include<iostream>
#include<vector>
#include<climits>
using namespace std;

// Bottom Up approach for solving this
int minNoCoin(int mn, vector<int> denoms){
    vector<int> dp(mn+1, 0);
    dp[0] = 0;      // Initializing for money = 0

    for(int i=1; i<=mn; i++){
        dp[i] = INT_MAX;

        for(int c : denoms){
            if(i-c >= 0 && dp[i-c] != INT_MAX)      // Comparing for change is possible or not
                dp[i] = min(dp[i], dp[i-c]+1);
        }
    }

    return dp[mn] == INT_MAX ? -1 : dp[mn];     // If change is not possible , return -1
}

int main(){
    int money;
    cin>>money;

    vector<int> denoms = {1,3,7,10};        // Denominations of coin available

    cout<<minNoCoin(money, denoms)<<endl;

    return 0;

}