#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

int t[10][10];

int lcsTD(string x, string y, int m, int n){
    // Initialization of Base case
    for(int i=0; i<m+1; i++){
        for(int j=0; j<n+1; j++){
            if(i == 0 || j == 0){
                t[i][j] = 0;
            }
        }
    }
    for(int i=1; i<m+1; i++){
        for(int j=1; j<n+1; j++){
            if(x[i-1] == y[j-1])
                t[i][j] = 1 + t[i-1][j-1];
            else
                t[i][j] = max(t[i-1][j], t[i][j-1]);
        }
    }
    return t[m][n];
}

string lcsPrintingTD(string x, string y, int m, int n){
    string str = "";
    int i=m, j=n;
    while(i > 0 && j > 0){
        if(x[i-1] == y[j-1]){
            str.push_back(x[i-1]);
            i--;
            j--;
        }
        else{
            if(t[i][j-1] > t[i-1][j]){
                j--;
            }
            else{
                i--;
            }
        }
    }
    //string ans = string(str.rbegin(), str.rend());
    reverse(str.begin(), str.end());
    return str;
}

int main(){
    //memset(t, -1, sizeof(t));
    string x =  "acbcf";
    string y = "abcdaf";

    int m = x.size();
    int n = y.size();

    cout<<lcsTD(x, y, m, n)<<endl;
    cout<<lcsPrintingTD(x, y, m, n);
    return 0;

}