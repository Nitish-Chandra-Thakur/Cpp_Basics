#include<iostream>
#include<algorithm>
using namespace std;

int lcsRecusive(string x, string y, int m, int n){
    // Base condition
    if(m == 0 || n == 0)
        return 0;
    if(x[m-1] == y[n-1]){
        return 1 + lcsRecusive(x, y, m-1, n-1);
    }
    else{
        return max(lcsRecusive(x, y, m, n-1), lcsRecusive(x, y, m-1, n));
    }
}

int main(){
    string x =  "AGGTAB";
    string y = "GXTXAYB";

    int m = x.size();
    int n = y.size();

    cout<<lcsRecusive(x, y, m, n);
    return 0;
}
