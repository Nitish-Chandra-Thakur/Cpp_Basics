/* Given a length of ROD and its selling prices for unit length of rod. We have to maximise the profit by
   cutting rod in such a way that we get more prices. Time complexity = O(2^n). */
#include<iostream>
#include<climits>
using namespace std;

int maxProfit(int prices[], int n){
    // Base case
    if(n<=0)
        return 0;
    
    //recursive case
    int ans = INT_MIN;
    for(int i=0; i<n; i++){
        int cut = i+1;
        int current_ans = prices[i] + maxProfit(prices, n-cut);
        ans = max(ans, current_ans);
    }
    return ans;
}

int main(){
    int prices[] = {1,5,8,9,10,17,17,20};
    int n = sizeof(prices)/sizeof(int);

    cout<<maxProfit(prices, n)<<endl;

    return 0;
}