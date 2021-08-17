#include<iostream>
#include<cstring>
using namespace std;

int t[20][20];

int lcsubstringTD(string x, string y, int m, int n){
    // Initialization of Base case
    int result = 0;
    for(int i=0; i<m+1; i++){
        for(int j=0; j<n+1; j++){
            if(i == 0 || j == 0){
                t[i][j] = 0;
            }
        }
    }
    for(int i=1; i<m+1; i++){
        for(int j=1; j<n+1; j++){
            if(x[i-1] == y[j-1]){
                t[i][j] = 1 + t[i-1][j-1];
                result = max(result, t[i][j]);
            }
            else
                t[i][j] = 0;
        }
    }
    return result;
}

int main(){
    //memset(t, -1, sizeof(t));
    string x =  "zxabcdezy";
    string y = "yzabcdezx";

    int m = x.size();
    int n = y.size();

    cout<<lcsubstringTD(x, y, m, n);
    return 0;

}