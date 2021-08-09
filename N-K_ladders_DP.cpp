#include<iostream>
using namespace std;

int ladder(int n, int k, int dp[]){
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;
    for(int i=3; i<=n; i++)
        dp[n] = ladder(n-1, k, dp) + ladder(n-2, k, dp) + ladder(n-3, k, dp); 
    
    return dp[n];
}

int main(){
    int n, k;
    cin>>n>>k;
    int dp[] = {0};
    cout<<ladder(n, k, dp);

    return 0;

}