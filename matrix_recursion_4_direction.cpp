#include<iostream>
#include<vector>
using namespace std;

int m,n;
string dir = "DLRU";
int di[] = {1,0,0,-1};
int dj[] = {0,-1,1,0};

void solve(int i, int j, string &temp, vector<string>&ans, vector<vector<int>>&vis){
    if(i>=m || j>=n || i<0 || j<0 || vis[i][j] == 1)
        return;
    if(i==m-1 && j==n-1){
        ans.push_back(temp);
        return;
    }
    vis[i][j] = 1;
    for(int x=0; x<4; x++){
        temp += dir[x];
        solve(i+di[x], j+dj[x], temp, ans, vis);
        temp.pop_back();
    }
    vis[i][j] = 0;
}

int main(){
    vector<string> ans;
    string temp = "";
    cin>>m >> n;
    vector<vector<int>> vis(m, vector<int>(n, 0));
    solve(0, 0, temp, ans, vis);
    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<endl;
    }
    return 0;
}