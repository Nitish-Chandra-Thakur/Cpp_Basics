#include<iostream>
#include<cstring>
using namespace std;

int knapsack(int wt[], int val[], int W, int n){
    int t[n+1][W+1];
    memset(t, -1, sizeof(t));
    // Base Condition
    if(n==0 || W==0)
        return 0;
    if(t[n][W] != -1)
        return t[n][W];

    if(wt[n-1] <= W){
        return t[n][W] = max(val[n-1]+knapsack(wt, val, W-wt[n-1], n-1), knapsack(wt, val, W, n-1));
    }
    else if(wt[n-1] > W)
        return t[n][W] = knapsack(wt, val, W, n-1);
    
}

int main(){
    int wt[] = {10, 20, 30};
    int val[] = {60, 100, 120};
    int W = 50;
    int n = sizeof(wt)/sizeof(int);
    

    cout<<knapsack(wt, val, W, n);
    return 0;
}