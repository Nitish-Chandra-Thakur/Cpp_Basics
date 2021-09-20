#include<iostream>
#include<vector>
using namespace std;

int solve(int ind, vector<int>&ip, int sum){
    if(ind == ip.size()){
        if(sum == 0)
            return 1;
        return 0;
    }
    int l = 0;
    int r = 0;
    if(sum >= ip[ind]){
        sum -= ip[ind];
        l =  solve(ind, ip, sum);
        sum += ip[ind];
    }
    r =  solve(ind+1, ip, sum);
    return l+r;
}

int main(){
    vector<int> ip = {1,2,3};
    int sum = 4;
    cout<<solve(0, ip, sum);
    return 0;
}