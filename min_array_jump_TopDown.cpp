#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int minJump(vector<int> arr, int n, vector<int> dp, int i){
    if(i == n-1)
        return 0;
    
    if(i >= n)
        return INT_MAX;
    // Recursive case
    if(dp[i] != 0)
        return dp[i];

    //Assumption
    int steps = INT_MAX;
    int max_jump = arr[i];

    for(int jump=1; jump<=max_jump; jump++){
        int next_cell = i + jump;
        int subprob = minJump(arr, n, dp, next_cell);
        if(subprob != INT_MAX){
            steps = min(steps, subprob+1);
        }
    }
    return dp[i] = steps;
}

int main(){
    vector<int> arr{3,4,2,1,2,3,7,1,1,3};
    int n = arr.size();

    // Creating an array for DP
    vector<int> dp(n, 0);

    cout<<minJumps(arr, n, dp, 0)<<endl;

    return 0;
}