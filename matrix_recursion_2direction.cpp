#include<iostream>
#include<vector>
using namespace std;

int m, n;

void solve(int i, int j, string &temp, vector<string>&ans){
    if(i>=m || j>=n)
        return;
    if(i==m-1 && j==n-1){
        ans.push_back(temp);
        return;
    }
    temp += "R";
    solve(i, j+1, temp, ans);
    temp.pop_back();
    temp += "D";
    solve(i+1, j, temp, ans);
    temp.pop_back();
    return;
}

int main(){
    vector<string> ans;
    string temp = "";
    cin>>m >> n;
    solve(0, 0, temp, ans);
    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<endl;
    }
    return 0;
}