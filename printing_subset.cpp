#include<iostream>
#include<vector>
using namespace std;

void solve(int ind, vector<int>&ip, vector<int>&temp, vector<vector<int>>&ans){
    if(ip.size() == ind){
        ans.push_back(temp);
        return;
    }
    temp.push_back(ip[ind]);
    solve(ind+1, ip, temp, ans);
    temp.pop_back();
    solve(ind+1, ip, temp, ans);
    return;
}

int main(){
    vector<int> ip = {1,2,3};
    int n = ip.size();
    vector<vector<int>> ans;
    vector<int> temp={};
    solve(0, ip, temp, ans);
    for(int i=0; i<ans.size(); i++){
        for(int j=0; j<ans[i].size(); j++)
            cout<<ans[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}