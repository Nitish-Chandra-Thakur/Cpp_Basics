#include<iostream>
#include<algorithm>
using namespace std;

int knapsack01TD(int wt[], int val[], int W, int n){
    int t[n+1][W+1];
    // Base condition to iterative form for initiliazation
    for(int i=0; i<n; i++){ 
        for(int j=0; j<W; j++){
            if(i==0 || j==0){
                t[i][j] = 0;
            }
        }
    }

    // Main recursive case to iterative case
    for(int i=1; i<n+1; i++){
        for(int j=1; j<W+1; j++){
            if(wt[i-1] <= j){
                t[i][j] = max((val[i-1]+t[i-1][j-wt[i-1]]), t[i-1][j]);
            }
            else{
                t[i][j] = t[i-1][j];
            }
        }
    }
    return t[n][W];
}

int main(){
    int wt[] = {10, 20, 30};
    int val[] = {60, 100, 120};
    int W = 50;
    int n = sizeof(wt)/sizeof(int);

    cout<<knapsack01TD(wt, val, W, n)<<endl;
    return 0;

}